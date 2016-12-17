#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString path = qApp->applicationDirPath() + "/VTeatre.sqlite";

    mydb = QSqlDatabase::addDatabase("QSQLITE");            //Подключаю БД
    mydb.setDatabaseName("./VTeatre.sqlite");
    mydb.open();
    CurScene = new Scene();                                 //Создаю объект сцены (пока пустой)

    CurScene->SetArrayCountPlaces();                        //Заполняю массив количества мест для каждого из типа мест
    CurScene->SetDataToTables();

    PreviousIndex = 0;                                      //Изначально индекс зала равен 0 - Партеру
    CountPurchased = 0;                                     //Изначально количество купленных
    CountBooked = 0;                                        //и забронированных равно 0

    dt = QDateTime::currentDateTime();                      //устанавливаю необходимую дату
    ui->dateEdit->setDateTime(dt);
    //ui->dateEdit->setMinimumDateTime(dt); // минимальная дата выставляется по текущей дате

    ui->tableSeans->setEditTriggers(QAbstractItemView::NoEditTriggers); //запрет редактирования всех ячеек в таблице tableSeans
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //запрет редактирования всех ячеек в таблице tableWidget

    ui->tableSeans->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents); // Ширина столбца с датой по размеру контента
    ui->tableSeans->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch); // Ширина столбца с названиями всё остальное пространство

    coordinates_of_places = new bool*[CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][0]];         //выделяю память для массива, содержащего информацию о каждом месте
    for(int i = 0; i < CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][0]; i++)
        coordinates_of_places[i] = new bool [CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][1]];  //и заполняю его значением false = "свободно"
    for(int i=0; i < CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][0]; i++)
        for(int j = 0; j < CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][1]; j++)
        {
            coordinates_of_places[i][j]=false;
        }

    ui->comboBox->setEnabled(false);            //Изначально combobox
    ui->pushButton->setEnabled(false);          //Кнопки оплаты, бронирования
    ui->pushButton_2->setEnabled(false);        //поиска, возврата и строки для ввода кода не доступны
    ui->pushButton_3->setEnabled(false);
    ui->pushButtonCode->setEnabled(false);
    ui->lineEditCode->setEnabled(false);

    connect(this, SIGNAL(MyWindowReSize(QResizeEvent*)), this, SLOT(main_window_resize(QResizeEvent*))); //Соеденения сигнала и слота  - используется в дальнейшем для изменения размеров виджетов
}
void MainWindow::pix_close(int row, int column)     //покрасить данную ячейку в красный цвет
{
    QPixmap pix_close1;
    pix_close1.load(":/image/image_close.png");
    pix_close1 = pix_close1.scaled(ui->tableWidget->columnWidth(0), ui->tableWidget->rowHeight(0));
    ui->tableWidget->item(row, column)->setBackground(QBrush(pix_close1));
}

void MainWindow::pix_reserv(int row, int column)    //покрасить данную ячейку в желтый цвет
{
    QPixmap pix_reserv;
    pix_reserv.load(":/image/image_reserv.png");
    pix_reserv = pix_reserv.scaled(ui->tableWidget->columnWidth(0), ui->tableWidget->rowHeight(0));
    ui->tableWidget->item(row, column)->setBackground(QBrush(pix_reserv));
}

void MainWindow::pix_checking(int row, int column)  //покрасить данную ячейку в голубой цвет
{
    QPixmap pix_checking;
    pix_checking.load(":/image/image_checking.png");
    pix_checking = pix_checking.scaled(ui->tableWidget->columnWidth(0), ui->tableWidget->rowHeight(0));
    ui->tableWidget->item(row, column)->setBackground(QBrush(pix_checking));
}

void MainWindow::pix_standart(int row, int column)  //покрасить данную ячейку в зеленый цвет
{
    QPixmap pix_standart;
    pix_standart.load(":/image/image.png");
    pix_standart = pix_standart.scaled(ui->tableWidget->columnWidth(0), ui->tableWidget->rowHeight(0));
    ui->tableWidget->item(row, column)->setBackground(QBrush(pix_standart));
}

void MainWindow::coordinates_of_places_cleaning(int temp)   //Удаление и заполнения массива
{
    int current_temp = ui->comboBox->currentIndex();        //Храним значения для предыдущего зала, это необходимо для очищения
    for(int i = 0; i < CurScene->ArrayCountPlaces[temp][0]; i++){
        delete [] coordinates_of_places[i];
    }
    delete []coordinates_of_places;

    coordinates_of_places = new bool*[CurScene->ArrayCountPlaces[current_temp][0]];         //выделяю память для массива, содержащего информацию о каждом месте
    for(int i = 0; i < CurScene->ArrayCountPlaces[current_temp][0]; i++)
        coordinates_of_places[i] = new bool [CurScene->ArrayCountPlaces[current_temp][1]];  //и заполня его значениями false = "свободно"
    for(int i=0; i < CurScene->ArrayCountPlaces[current_temp][0]; i++)
        for(int j = 0; j < CurScene->ArrayCountPlaces[current_temp][1]; j++)
        {
            coordinates_of_places[i][j]=false;
        }

}

void MainWindow::places_fill()//заполнение мест
{
    int temp = ui->comboBox->currentIndex();

    for(int i=0; i < CurScene->ArrayCountPlaces[temp][0]; i++)  //исходя из данных, занесенных в объект текущей сцены заполняется таблица мест
    {
        for(int j=0; j < CurScene->ArrayCountPlaces[temp][1]; j++)
        {
            if(CurScene->TablesPlaces[temp][i][j] == 0){
                pix_standart(i, j);
                continue;
            }
            if(CurScene->TablesPlaces[temp][i][j] == 1){
                pix_close(i, j);
                continue;
            }
            if(CurScene->TablesPlaces[temp][i][j] == 2){
                pix_reserv(i, j);
                continue;
            }
        }
    }
}


MainWindow::~MainWindow()   //Деструктор
{
    delete ui;
}

void MainWindow::on_informationAbout_triggered()    //Окно About
{
    About *window = new About(this);
    window->show();
}

void MainWindow::on_tableWidget_cellClicked(int row, int column) // по нажатию на ячейку
{
    if(coordinates_of_places[row][column])//проверяет активно ли нажатое место
    {
        int temp = ui->comboBox->currentIndex();

        if(CurScene->TablesPlaces[temp][row][column] == 0)  //Если да, тоокрашиваю его обратно в правильный цвет
            pix_standart(row,column);
        if(CurScene->TablesPlaces[temp][row][column] == 1)
            pix_close(row,column);
        if(CurScene->TablesPlaces[temp][row][column] == 2)
            pix_reserv(row,column);

        coordinates_of_places[row][column] = false;         //удаляю из массива с выделенными местами

        for(int i = 0; i < SelectedPlacesRow.size(); i++){  //очищаю векторы, хранящие номера мест
            if(SelectedPlacesRow[i] == row && SelectedPlacesCol[i] == column){
                SelectedPlacesRow.erase(SelectedPlacesRow.begin() + i);
                SelectedPlacesCol.erase(SelectedPlacesCol.begin() + i);
            }
        }
    }
    else
    {   //Если же до этого ячейка не была выбрана
        coordinates_of_places[row][column] = true;  //то в массиве отмечаю как выделенную
        pix_checking(row,column);                   //меняю ее цвет
        SelectedPlacesRow.push_back(row);           //И добавляю в вектор колонку и ряд этого места
        SelectedPlacesCol.push_back(column);
    }
    CustomizePrice();
}

void MainWindow::on_comboBox_currentIndexChanged(int index) // по изменению пункта в combobox
{
    coordinates_of_places_cleaning(PreviousIndex);  //пересоздаю массив

    create_a_MainTable();                           //создаю таблицу мест
    places_fill();                                  //заполняю ее
    customizeTableInf();                            //изменяю таблицу информации о местах

    SelectedPlacesRow.clear();                      //очищаю векторы, хранящие номера мест
    SelectedPlacesCol.clear();

    PreviousIndex = index;                          //Предыдущий индекс обновляю на текущий
    CustomizePrice();
}


void MainWindow::on_tableSeans_cellClicked(int row, int column) // по нажатию на название постановки
{
    if(column == 1) //проверяю на нажатие именно на название
    {
        ui->comboBox->setEnabled(true);         //Делаю доступными все элементы которые раньше были недоступны
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButtonCode->setEnabled(true);
        ui->lineEditCode->setEnabled(true);

        delete CurScene;                        //удаляю  устаревшую сцену

        CurScene = new Scene();                 //и создаю новую

        CurScene->set_name(ui->tableSeans->item(row, 1)->text());   //Устанавливаю для нее имя
        CurScene->set_time(ui->tableSeans->item(row, 0)->text());   //время
        CurScene->set_date(ui->dateEdit->text());                   //дату
        CurScene->set_cost();                                       //и цены

        CurScene->SetArrayCountPlaces();                            //Количество мест  для каждого зала

        CurScene->SetDataToTables();                                //и информацию о каждом месте
        coordinates_of_places_cleaning(ui->comboBox->currentIndex());   //очищаю массив выбранных мест
        create_a_MainTable();                                       //создаю заново таблицу мест
        places_fill();                                              //заполняю ее
        customizeTableInf();                                        //обновляю таблицу с информацией
        SelectedPlacesRow.clear();                                  //очищаю векторы, хранящие номера мест
        SelectedPlacesCol.clear();
        ui->comboBox->setCurrentIndex(0);

        QString name = ui->tableSeans->item(row,column)->text();    //Изменяю подпись текущей постаановки
        ui->label_4->setText(name);
    }
    CustomizePrice();
}

void MainWindow::on_dateEdit_dateChanged(const QDate &date)         //После изменения текущей даты в календаре
{
        QString date_seansa = ui->dateEdit->text();
        QSqlQuery qry1("select * from Postanovka where date_seansa='" + date_seansa + "'");

        std::vector<QString>Name;
        std::vector<QString>Time;

        while(qry1.next())              //считываю из базы данных информацию о времени и названии спектаклей на этот день
        {
            Time.push_back(qry1.value(1).toString());
            Name.push_back(qry1.value(0).toString());//записывает данные спектакля в вектор
        }
        ui->tableSeans->setRowCount(Name.size()); // указываем количество строк

        for(int i = 0; i < Name.size(); i++)        //выделяю память
        {
            ui->tableSeans->setItem(i, 0, new QTableWidgetItem); // вставляем ячейку
            ui->tableSeans->setItem(i, 1, new QTableWidgetItem); // вставляем ячейку

            ui->tableSeans->item(i, 0)->setText(Time[i]);       //и заполняю данными каждую ячейку
            ui->tableSeans->item(i, 1)->setText(Name[i]);
        }
}

void MainWindow::on_pushButton_clicked() // купить
{
    bool *verification = new bool [1];  //указатель, указывающий на то, подтверждена ли покупка
    *verification = false;              //изначально равен false
    int temp = ui->comboBox->currentIndex();
    std::vector <short> PurRow;
    std::vector <short> PurCol;

    for(int i = 0; i < SelectedPlacesRow.size(); i++){              //Если покупаю уже забронированные
        if(CurScene->TablesPlaces[temp][SelectedPlacesRow[i]][SelectedPlacesCol[i]] == 2){
            PurRow.push_back(SelectedPlacesRow[i]);                 //То добавляю в массив для удаления
            PurCol.push_back(SelectedPlacesCol[i]);
        }
        if(CurScene->TablesPlaces[temp][SelectedPlacesRow[i]][SelectedPlacesCol[i]] == 1){//Если поукупаю уже купленные
            QMessageBox::warning(this, "Предупреждение", "Место: " + QString::number(SelectedPlacesCol[i] + 1) + " Ряд: "+ QString::number(SelectedPlacesRow[i] + 1) +" уже куплено.");

            SelectedPlacesRow.erase(SelectedPlacesRow.begin() + i);                       //То удаляю из вектора и ничего не делаю с ними
            SelectedPlacesCol.erase(SelectedPlacesCol.begin() + i);
            i--;
        }
    }
    if(SelectedPlacesRow.size()){//если выбрано хотябы 1 не купленные место
        FinalyWindow *wnd = new FinalyWindow(SelectedPlacesRow, SelectedPlacesCol, CurScene, ui->comboBox->currentText(), ui->comboBox->currentIndex(), verification);  //вызаваю окно подтверждения покупки
        wnd->exec();

        if(*verification){  //если покупка действительно прошла успешно
            DeleteBooked(PurRow, PurCol);   //то удаляю из базы данных бронированные, которые мы уже купили
            for(int i = 0; i < SelectedPlacesRow.size(); i++){  //И обновляю объект текущей сцены
                CurScene->TablesPlaces[temp][SelectedPlacesRow[i]][SelectedPlacesCol[i]] = 1;
            }
            QSqlQuery qry0("select count_place from DataforStatistic where date='" + ui->dateEdit->text()+ "' and type_place='" +ui->comboBox->currentText()+ "'"); //Обновляю БД
            qry0.first();
            QSqlQuery qry("update DataforStatistic set count_place="+ QString::number(SelectedPlacesRow.size() + qry0.value("count_place").toInt()) +" where date='" +ui->dateEdit->text()+ "' and type_place='" +ui->comboBox->currentText()+ "'");
            CurScene->InsertTablesToDataBase(SelectedPlacesRow, SelectedPlacesCol, ui->comboBox->currentIndex(), 1);
            customizeTableInf();
        }

        places_fill();  //Обновляю таблицу мест
        coordinates_of_places_cleaning(ui->comboBox->currentIndex());   //очищаю массив
        SelectedPlacesRow.clear();                                      //очищаю векторы, хранящие номера мест
        SelectedPlacesCol.clear();
        CustomizePrice();                                               //изменяю данные о количестве выбранных мест
    }
}

void MainWindow::on_pushButton_2_clicked() // забронировать
{
    int temp = ui->comboBox->currentIndex();
    QString Code = "";
    for(int i = 0; i < SelectedPlacesRow.size(); i++){
        if(CurScene->TablesPlaces[temp][SelectedPlacesRow[i]][SelectedPlacesCol[i]] == 2 || CurScene->TablesPlaces[temp][SelectedPlacesRow[i]][SelectedPlacesCol[i]] == 1){
            SelectedPlacesRow.erase(SelectedPlacesRow.begin() + i); //если бронирую уже забронированный
            SelectedPlacesCol.erase(SelectedPlacesCol.begin() + i); //или купленный
            i--;                                                    //то ничего с ними не делаю
        }
        else
            CurScene->TablesPlaces[temp][SelectedPlacesRow[i]][SelectedPlacesCol[i]] = 2; //в противоположном случае - отмечаю как бронированное
    }
    if(SelectedPlacesCol.size()){   //если остались места, которые необходимо бронировать
        srand(time(NULL));
        for(int i = 0; i < 10; i++){    //генерирую случайный код
            Code += QString::number(std::rand() % 10);
        }
        //QMessageBox::information(QMessageBox::NoIcon,QObject::tr("Бронирование"),tr("Ваш код: ") + Code);//и вывожу его
        QMessageBox::information(this, QObject::tr("Бронирование"),tr("Ваш код: ") + Code );
    }
    CurScene->InsertTablesToDataBase(SelectedPlacesRow, SelectedPlacesCol, ui->comboBox->currentIndex(), 2, Code);  //обновляю БД
    places_fill();                                                  //Обновляю таблицу мест
    coordinates_of_places_cleaning(ui->comboBox->currentIndex());   //очищаю массив мест
    customizeTableInf();                                            //изменяю данные таблицу информации
    SelectedPlacesRow.clear();                                      //очищаю векторы, хранящие номера мест
    SelectedPlacesCol.clear();
    CustomizePrice();                                               //изменяю информацию о выделенных местах
}

void MainWindow::on_action_exit_triggered() // пункт Выход
{
    this->close();
}

void MainWindow::on_action_statistic_sale_triggered() // окно статистики
{
    Statistic *wnd = new Statistic;
    wnd->exec();
}

void MainWindow::on_pushButton_3_clicked()//вернуть
{
    int temp = ui->comboBox->currentIndex();
    QSqlQuery qry0("select count_place from DataforStatistic where date='" + ui->dateEdit->text()+ "' and type_place='" +ui->comboBox->currentText()+ "'"); //Обновляю БД
    qry0.first();
    QSqlQuery qry("update DataforStatistic set count_place="+ QString::number(qry0.value("count_place").toInt() - SelectedPlacesRow.size()) +" where date='" +ui->dateEdit->text()+ "' and type_place='" +ui->comboBox->currentText()+ "'");
    for(int i = 0; i < SelectedPlacesRow.size(); i++){
        if(CurScene->TablesPlaces[temp][SelectedPlacesRow[i]][SelectedPlacesCol[i]] == 0){  //проверяю на то, занято ли место
            SelectedPlacesRow.erase(SelectedPlacesRow.begin() + i);                         //если да, то удаляю его из вектора
            SelectedPlacesCol.erase(SelectedPlacesCol.begin() + i);
            i--;
        }
        else
            CurScene->TablesPlaces[temp][SelectedPlacesRow[i]][SelectedPlacesCol[i]] = 0;   //если нет то заношу ищзменения в объект
    }
    CurScene->InsertTablesToDataBase(SelectedPlacesRow, SelectedPlacesCol, ui->comboBox->currentIndex(), 0);    //и заношу данные изменения в БД
    places_fill();                                                  //перерисовываю таблицу
    coordinates_of_places_cleaning(ui->comboBox->currentIndex());   //очищаю массив мест
    customizeTableInf();                                            //обновляю таблицу информации
    SelectedPlacesRow.clear();                                      //очищаю векторы, хранящие номера мест
    SelectedPlacesCol.clear();
    CustomizePrice();                                               //обновляю данные о выделенных местах
}

void MainWindow::create_a_MainTable()                               //создаю таблицу с местами
{
    int temp = ui->comboBox->currentIndex();
    ui->tableWidget->setRowCount(CurScene->ArrayCountPlaces[temp][0]);      //Устанавливаю необходимое число строк
    ui->tableWidget->setColumnCount(CurScene->ArrayCountPlaces[temp][1]);   //Устанавливаю необходичое число столбцов

    for(int i=0; i < ui->tableWidget->rowCount(); i++){                     //выделяю для каждой ячейки память
        for(int j=0; j < ui->tableWidget->columnCount(); j++){
            ui->tableWidget->setItem(i, j, new QTableWidgetItem);
        }
    }

    row_height = (ui->tableWidget->height() -10) / ui->tableWidget->rowCount();     //подсчитываю высоту и ширину ячеек
    column_width = (ui->tableWidget->width() -35) / ui->tableWidget->columnCount();

    for(int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        ui->tableWidget->setRowHeight(i, row_height); // высота строк
        for(int j = 0; j < ui->tableWidget->columnCount(); j++)
        {
            if(i == 0)
                ui->tableWidget->setColumnWidth(j, column_width); // ширина столбцов

            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(QString::number(j + 1));
            item->setTextAlignment(Qt::AlignCenter);
            item->setFlags(item->flags() & (~Qt::ItemIsSelectable)); // устанавливаю флаг ItemIsSelectable в false
            item->setToolTip("Ряд " + QString::number(i+1));
            ui->tableWidget->setItem( i, j, item );
        }
    }

    ui->tableWidget->verticalHeader()->setStyleSheet("border-style: solid;"             // стиль для хидера
                                                     "border-width: 1px;"
                                                     "border-color: black;"
                                                     "border-radius: 0px;"
                                                     "color: black;");
    ui->tableWidget->setStyleSheet("QTableWidget{"                                      // стиль для таблицы и tooltip-a
                                   "border-style: solid;"
                                   "border-width: 5px;"
                                   "border-radius: 1px;"
                                   "border-color: #d3bb9c;"
                                   "}"
                                   "QTableWidget QToolTip{"
                                   "color:red;"
                                   "border-style: solid;"
                                   "border-width: 1px;"
                                   "border-color: green;"
                                   "border-radius: 0px;"
                                   "}"
                                   "QHeaderView{"
                                   "background-color: transparent;"
                                   "}");
    ui->tableWidget->verticalHeader()->setVisible(true);
    ui->tableWidget->verticalHeader()->setMaximumSectionSize(ui->tableWidget->verticalHeader()->defaultSectionSize());//Устанавливаю размеры вертикального хедера
    ui->tableWidget->verticalHeader()->setMinimumSectionSize(ui->tableWidget->verticalHeader()->defaultSectionSize());
}

void MainWindow::on_options_room_triggered()    //Окно настройки зала
{
    int temp = ui->comboBox->currentIndex();

    for(int i = 0; i < CurScene->ArrayCountPlaces[temp][0]; i++){   //очищаю массив мест
        delete [] coordinates_of_places[i];
    }
    delete []coordinates_of_places;

    OptionsForHall *wind = new OptionsForHall(this);            //открываю окно
    wind->exec();

    CurScene->DeleteTables();                                   //очищаю таблицы
    CurScene->SetArrayCountPlaces();                            //устанавливаю обновленные данные о количестве мест
    CurScene->SetDataToTables();                                //Заполняю таблицы данными

    SelectedPlacesRow.clear();                                  //создаю таблицу с местами
    SelectedPlacesCol.clear();

    create_a_MainTable();                                       //создаю таблицу мест
    places_fill();                                              //заполняю таблицу мест
    customizeTableInf();                                        //обновляю таблицу информации

    coordinates_of_places = new bool*[CurScene->ArrayCountPlaces[temp][0]]; //Выделяю память для массива мест
    for(int i = 0; i < CurScene->ArrayCountPlaces[temp][0]; i++)
        coordinates_of_places[i] = new bool [CurScene->ArrayCountPlaces[temp][1]];
    for(int i=0; i < CurScene->ArrayCountPlaces[temp][0]; i++)
        for(int j = 0; j < CurScene->ArrayCountPlaces[temp][1]; j++)
        {
            coordinates_of_places[i][j]=false;
        }
}

void MainWindow::on_action_addScene_triggered()                 // нажатие на "Добавить постановку"
{
    AddScene *window = new AddScene(this);
    window->exec();
    on_dateEdit_dateChanged(QDate::fromString(ui->dateEdit->text(), "dd.MM.yyyy")); //Обновляю таблицу сеансов
}

void MainWindow::customizeTableInf()        //обновляю таблицу информации
{
    CountPurchased = 0;                     //Количество купленных и бронированных
    CountBooked = 0;

    int temp = ui->comboBox->currentIndex();
    for(int i=0; i < CurScene->ArrayCountPlaces[temp][0] ; i++) //Подсчитываю количество купленных и бронированных
    {
        for(int j=0; j < CurScene->ArrayCountPlaces[temp][1]; j++)
        {
            if(CurScene->TablesPlaces[temp][i][j] == 1)
                CountPurchased++;
            if(CurScene->TablesPlaces[temp][i][j] == 2)
                CountBooked++;
        }
    }
    //И заполняю таблицу информации данными
    int CountOfPlaces = CurScene->ArrayCountPlaces[temp][0] * CurScene->ArrayCountPlaces[temp][1];
    ui->tableInfo->item(0,0)->setText("Всего мест: " + QString::number(CountOfPlaces));
    ui->tableInfo->item(0,1)->setText("Продано: " + QString::number(CountPurchased));
    ui->tableInfo->item(1,1)->setText("Бронь: " + QString::number(CountBooked));
    ui->tableInfo->item(1,0)->setText("Свободно: " + QString::number(CountOfPlaces - CountPurchased - CountBooked));
}

void MainWindow::on_action_hovered()
{

}

void MainWindow::on_tableSeans_customContextMenuRequested(const QPoint &pos)
{
    /* Создаем объект контекстного меню */
    QMenu * menu = new QMenu(this);
    /* Создаём действия для контекстного меню */
    QAction * editDevice = new QAction(trUtf8("Редактировать"), this);
    QAction * delDevice = new QAction(trUtf8("Удалить"), this);

    /* Подключаем СЛОТы обработчики для действий контекстного меню */
    connect(editDevice, SIGNAL(triggered()), this, SLOT(slotEditRecord()));     // Обработчик вызова диалога редактирования
    connect(delDevice, SIGNAL(triggered()), this, SLOT(slotDelRecord()));     // Обработчик вызова диалога редактирования
    /* Устанавливаем действия в меню */
    menu->addAction(editDevice);
    menu->addAction(delDevice);
    /* Вызываем контекстное меню */
    menu->popup(ui->tableSeans->viewport()->mapToGlobal(pos));
}
void MainWindow::slotEditRecord()
{
    int row = ui->tableSeans->currentRow();
    if (QMessageBox::warning(this, trUtf8("Редактирование записи"), trUtf8("Вы уверены, что хотите редактировать эту запись?"), QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
        return;
    else {
        Scene *tempScene = new Scene();
        QSqlQuery qry("select * from Postanovka where name='" + ui->tableSeans->item(row, 1)->text() + "' and time_seansa='" + ui->tableSeans->item(row, 0)->text() + "' and date_seansa='" + ui->dateEdit->text() + "'");
        qry.first();
        tempScene->set_time(ui->tableSeans->item(row, 0)->text());
        tempScene->set_name(ui->tableSeans->item(row, 1)->text());
        tempScene->set_date(ui->dateEdit->text());
        tempScene->set_cost(qry.value("cost_parter").toInt(), qry.value("cost_benuar").toInt(), qry.value("cost_beletaj").toInt());
        AddScene *temp = new AddScene(true, tempScene, this);
        temp->exec();
        on_dateEdit_dateChanged(QDate::fromString(ui->dateEdit->text(), "dd.MM.yyyy"));
    }

}

void MainWindow::slotDelRecord(){   //Удалить постановку
    int row = ui->tableSeans->currentRow();

    QSqlQuery qry1("delete from Postanovka where name='" + ui->tableSeans->item(row, 1)->text() + "' and time_seansa='" + ui->tableSeans->item(row, 0)->text() + "' and date_seansa='" + ui->dateEdit->text() + "'");
    QSqlQuery qry2("delete from Employed_place where name_seansa='" + ui->tableSeans->item(row, 1)->text() + "' and time_seansa='" + ui->tableSeans->item(row, 0)->text() + "' and date_seansa='" + ui->dateEdit->text() + "'");
    if(ui->tableSeans->item(row, 1)->text() == CurScene->name && ui->tableSeans->item(row, 0)->text() == CurScene->time && ui->dateEdit->text() == CurScene->date){
        delete CurScene;                        //если удалил ту постановку, тоторая сейчас открыта
        CurScene = new Scene();

        ui->comboBox->setEnabled(false);        //то необходимо ее закрыть
        ui->pushButton->setEnabled(false);      //и очистить все массивы и векторы которые с ней связаны
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButtonCode->setEnabled(false);
        ui->lineEditCode->setEnabled(false);
        ui->tableWidget->setVerticalHeader(false);
        ui->tableWidget->verticalHeader()->setStyleSheet("border-width: 0px;");
        ui->label_4->setText("");
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setColumnCount(0);

        customizeTableInf();
        CustomizePrice();

        SelectedPlacesRow.clear();
        SelectedPlacesCol.clear();
    }
    on_dateEdit_dateChanged(QDate::fromString(ui->dateEdit->text(), "dd.MM.yyyy"));
}

void MainWindow::DeleteBooked(std::vector <short> PurRow, std::vector<short>PurCol) //удаляю забронированные места
{
    for(int i = 0; i < PurRow.size(); i++){
        QSqlQuery qry("delete from Employed_place where type_place = '" + QString::number(ui->comboBox->currentIndex()) +"' and date_seansa = '" + CurScene->date + "' and time_seansa='" + CurScene->time + "' and name_seansa='" + CurScene->name + "' and row=" + QString::number(PurRow[i]) + " and column=" + QString::number(PurCol[i]));
    }
}

void MainWindow::CustomizePrice(){              //изменение данных о выбранных местах
    int CountChecked = 0;
    int temp = ui->comboBox->currentIndex();
    for(int i=0; i < CurScene->ArrayCountPlaces[temp][0]; i++){         //подсчитываю количество выбранных
        for(int j = 0; j < CurScene->ArrayCountPlaces[temp][1]; j++){
            if(coordinates_of_places[i][j])
                CountChecked++;
        }
    }

    ui->LabelCountSel->setText("Выбрано: " + QString::number(CountChecked));//и изменяю данные таблицы
}

void MainWindow::on_pushButtonCode_clicked()    //Поиск мест по введенному коду
{
    places_fill();                              //перерисовываю таблицу мест
    coordinates_of_places_cleaning(ui->comboBox->currentIndex());   //очищаю массив мест

    SelectedPlacesRow.clear();                  //очищаю вектор с выбранными местами
    SelectedPlacesCol.clear();

    QSqlQuery qry("select * from Employed_place where code='" + ui->lineEditCode->text() + "' and name_seansa='" + CurScene->name + "' and date_seansa='" + CurScene->date + "' and time_seansa='" + CurScene->time + "' and type_place='" + ui->comboBox->currentText() + "'");
    bool Enabled = true;
    while(qry.next()){  //поиск в БД необходимых мест
        coordinates_of_places[qry.value(5).toInt()][qry.value(6).toInt()] = true;

        SelectedPlacesRow.push_back(qry.value(5).toInt());  //если нашел, то дабвляю в вектор выбранных мест
        SelectedPlacesCol.push_back(qry.value(6).toInt());

        pix_checking(qry.value(5).toInt(), qry.value(6).toInt());   //и изменяю цвет ячейки
        Enabled = false;
    }
    if(Enabled){//если не найдено, то вывести сообщение пользователю
        QMessageBox::critical(this,QObject::tr("Ошибка"),tr("Для данной постановки код не найден."));
    }
}
void MainWindow::resizeEvent(QResizeEvent* e)   //изменение размера. Из класса QObject
{
    emit MyWindowReSize(e);     //Посылаю сигнал для перерисовки некоторых виджетов
    QWidget::resizeEvent(e);    //После чего слот продолжает свою стандартную работу
}

void MainWindow::main_window_resize(QResizeEvent *event)
{

}
