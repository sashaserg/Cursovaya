#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Cursovaya/VTeatre.sqlite");

    CurScene = new Scene();

    if(!mydb.open())
        qDebug()<<mydb.lastError().text();
    else
        qDebug()<<"Connected Compled";

    CurScene->SetArrayCountPlaces();
    CurScene->SetDataToTables();

    PreviousIndex = 0;
    CountPurchased = 0;
    CountBooked = 0;

  /*  QPixmap  pix;
    pix.load(":/image/scena.png");
    pix = pix.scaled(ui->label_2->size());
    ui->label_2->setPixmap(pix);
*/
    dt = QDateTime::currentDateTime();
    ui->dateEdit->setDateTime(dt);
    //ui->dateEdit->setMinimumDateTime(dt); // минимальная дата выставляется по текущей дате

    ui->tableSeans->setEditTriggers(QAbstractItemView::NoEditTriggers); //запрет редактирования всех ячеек в таблице tableSeans
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //запрет редактирования всех ячеек в таблице tableWidget

    ui->tableSeans->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents); // Ширина столбца с датой по размеру контента
    ui->tableSeans->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch); // Ширина столбца с названиями всё остальное пространство

    coordinates_of_places = new bool*[CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][0]];
    for(int i = 0; i < CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][0]; i++)
        coordinates_of_places[i] = new bool [CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][1]];
    for(int i=0; i < CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][0]; i++)
        for(int j = 0; j < CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][1]; j++)
        {
            coordinates_of_places[i][j]=false;
        }

    ui->comboBox->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButtonCode->setEnabled(false);
    ui->lineEditCode->setEnabled(false);

    QString date = ui->dateEdit->text();
    //QSqlQuery qry_delete("delete from Postanovka where date_seansa<'" +date+ "'");
    //QSqlQuery qry_delete1("delete from Employed_place where date_seansa<'" +date+ "'");



    connect(this, SIGNAL(MyWindowReSize(QResizeEvent*)), this, SLOT(main_window_resize(QResizeEvent*)));
}
void MainWindow::pix_close(int row, int column)
{
    QPixmap pix_close1;
    pix_close1.load(":/image/image_close.png");
    pix_close1 = pix_close1.scaled(ui->tableWidget->columnWidth(0), ui->tableWidget->rowHeight(0));
    ui->tableWidget->item(row, column)->setBackground(QBrush(pix_close1));
}

void MainWindow::pix_reserv(int row, int column)
{
    QPixmap pix_reserv;
    pix_reserv.load(":/image/image_reserv.png");
    pix_reserv = pix_reserv.scaled(ui->tableWidget->columnWidth(0), ui->tableWidget->rowHeight(0));
    ui->tableWidget->item(row, column)->setBackground(QBrush(pix_reserv));
}

void MainWindow::pix_checking(int row, int column)
{
    QPixmap pix_checking;
    pix_checking.load(":/image/image_checking.png");
    pix_checking = pix_checking.scaled(ui->tableWidget->columnWidth(0), ui->tableWidget->rowHeight(0));
    ui->tableWidget->item(row, column)->setBackground(QBrush(pix_checking));
}

void MainWindow::pix_standart(int row, int column)
{
    QPixmap pix_standart;
    pix_standart.load(":/image/image.png");
    pix_standart = pix_standart.scaled(ui->tableWidget->columnWidth(0), ui->tableWidget->rowHeight(0));
    ui->tableWidget->item(row, column)->setBackground(QBrush(pix_standart));
}

void MainWindow::cleasing_places()//очистка мест
{

}

void MainWindow::coordinates_of_places_cleaning(int temp)
{
    int current_temp = ui->comboBox->currentIndex();
    for(int i = 0; i < CurScene->ArrayCountPlaces[temp][0]; i++){
        delete [] coordinates_of_places[i];
    }
    delete []coordinates_of_places;

    coordinates_of_places = new bool*[CurScene->ArrayCountPlaces[current_temp][0]];
    for(int i = 0; i < CurScene->ArrayCountPlaces[current_temp][0]; i++)
        coordinates_of_places[i] = new bool [CurScene->ArrayCountPlaces[current_temp][1]];
    for(int i=0; i < CurScene->ArrayCountPlaces[current_temp][0]; i++)
        for(int j = 0; j < CurScene->ArrayCountPlaces[current_temp][1]; j++)
        {
            coordinates_of_places[i][j]=false;
        }

}

void MainWindow::places_fill()//заполнение мест
{
    int temp = ui->comboBox->currentIndex();

    for(int i=0; i < CurScene->ArrayCountPlaces[temp][0]; i++)
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


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_informationAbout_triggered()
{
    About *window = new About(this);
    window->show();
}

void MainWindow::on_action_triggered()
{
  // открытие окна покупателя, класс WindowBuyer
}

void MainWindow::on_tableWidget_cellClicked(int row, int column) // по нажатию на ячейку она меняет цвет
{
    if(coordinates_of_places[row][column])//проверяет активно ли нажатое место
    {
        int temp = ui->comboBox->currentIndex();

        if(CurScene->TablesPlaces[temp][row][column] == 0)
            pix_standart(row,column);
        if(CurScene->TablesPlaces[temp][row][column] == 1)
            pix_close(row,column);
        if(CurScene->TablesPlaces[temp][row][column] == 2)
            pix_reserv(row,column);

        coordinates_of_places[row][column]=false;

        for(int i = 0; i < SelectedPlacesRow.size(); i++){
            if(SelectedPlacesRow[i] == row && SelectedPlacesCol[i] == column){
                SelectedPlacesRow.erase(SelectedPlacesRow.begin() + i);
                SelectedPlacesCol.erase(SelectedPlacesCol.begin() + i);
            }
        }
    }
    else
    {
        coordinates_of_places[row][column]=true;
        pix_checking(row,column);
        SelectedPlacesRow.push_back(row);
        SelectedPlacesCol.push_back(column);
    }
    CustomizePrice();
}

void MainWindow::on_comboBox_currentIndexChanged(int index) // по изменению пункта в combobox менять таблицу
{
    coordinates_of_places_cleaning(PreviousIndex);

    create_a_MainTable();
    places_fill();
    customizeTableInf();

    SelectedPlacesRow.clear();
    SelectedPlacesCol.clear();

    PreviousIndex = index;
    CustomizePrice();
}


void MainWindow::on_tableSeans_cellClicked(int row, int column) // по нажатию на название изменить таблицу с местами
{
    if(column == 1)
    {
        ui->comboBox->setEnabled(true);
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButtonCode->setEnabled(true);
        ui->lineEditCode->setEnabled(true);

        delete CurScene;

        CurScene = new Scene();

        //1 - найти имя, время, дата
        CurScene->set_name(ui->tableSeans->item(row, 1)->text());
        CurScene->set_time(ui->tableSeans->item(row, 0)->text());
        CurScene->set_date(ui->dateEdit->text());
        CurScene->set_cost();

        //2 - найти количество мест в каждом типе
        CurScene->SetArrayCountPlaces();

        //3 - найти инф. о каждом месте
        CurScene->SetDataToTables();
        coordinates_of_places_cleaning(ui->comboBox->currentIndex());//Багует когда меняю размер сцены(не всегда)
        create_a_MainTable();
        places_fill();
        customizeTableInf();
        SelectedPlacesRow.clear();
        SelectedPlacesCol.clear();
        ui->comboBox->setCurrentIndex(0);

        QString name = ui->tableSeans->item(row,column)->text();
        ui->label_4->setText(name);
    }
    CustomizePrice();
}

void MainWindow::on_dateEdit_dateChanged(const QDate &date)//Выводит сеансы по дате
{
        QString date_seansa=ui->dateEdit->text();
        QSqlQuery qry1("select * from Postanovka where date_seansa='" + date_seansa + "'");

        std::vector<QString>Name;
        std::vector<QString>Time;

        while(qry1.next())
        {
            Time.push_back(qry1.value(1).toString());
            Name.push_back(qry1.value(0).toString());//записывает данные спектакля в массив
        }
        ui->tableSeans->setRowCount(Name.size()); // указываем количество строк, вместо 10 нужно подставлять количество спектаклей на какое-то число

        for(int i = 0; i < Name.size(); i++)
        {
            ui->tableSeans->setItem(i, 0, new QTableWidgetItem); // вставляем ячейку
            ui->tableSeans->setItem(i, 1, new QTableWidgetItem); // вставляем ячейку

            ui->tableSeans->item(i, 0)->setText(Time[i]);
            ui->tableSeans->item(i, 1)->setText(Name[i]);
        }
}

void MainWindow::on_pushButton_clicked() // купить
{
    bool *verification = new bool [1];
    *verification = false;
    int temp = ui->comboBox->currentIndex();
    std::vector <short> PurRow;
    std::vector <short> PurCol;

    for(int i = 0; i < SelectedPlacesRow.size(); i++){
        if(CurScene->TablesPlaces[temp][SelectedPlacesRow[i]][SelectedPlacesCol[i]] == 2){
            PurRow.push_back(SelectedPlacesRow[i]);
            PurCol.push_back(SelectedPlacesCol[i]);
        }
        if(CurScene->TablesPlaces[temp][SelectedPlacesRow[i]][SelectedPlacesCol[i]] == 1){
            SelectedPlacesRow.erase(SelectedPlacesRow.begin() + i);
            SelectedPlacesCol.erase(SelectedPlacesCol.begin() + i);
            i--;
        }
    }
    if(SelectedPlacesRow.size()){
        FinalyWindow *wnd = new FinalyWindow(SelectedPlacesRow, SelectedPlacesCol, CurScene, ui->comboBox->currentText(), ui->comboBox->currentIndex(), verification);
        wnd->exec();

        if(*verification){
            DeleteBooked(PurRow, PurCol);
            for(int i = 0; i < SelectedPlacesRow.size(); i++){
                CurScene->TablesPlaces[temp][SelectedPlacesRow[i]][SelectedPlacesCol[i]] = 1;
                QSqlQuery qry("update DataforStatistic set count_place="+ QString::number(i) +" where date='" +ui->dateEdit->text()+ "' and type_place='" +ui->comboBox->currentText()+ "'");
            }
            CurScene->InsertTablesToDataBase(SelectedPlacesRow, SelectedPlacesCol, ui->comboBox->currentIndex(), 1);
            customizeTableInf();
        }

        places_fill();
        coordinates_of_places_cleaning(ui->comboBox->currentIndex());
        SelectedPlacesRow.clear();
        SelectedPlacesCol.clear();
        CustomizePrice();
    }
}

void MainWindow::on_pushButton_2_clicked() // забронировать
{
    int temp = ui->comboBox->currentIndex();
    QString Code = "";
    for(int i = 0; i < SelectedPlacesRow.size(); i++){
        if(CurScene->TablesPlaces[temp][SelectedPlacesRow[i]][SelectedPlacesCol[i]] == 2 || CurScene->TablesPlaces[temp][SelectedPlacesRow[i]][SelectedPlacesCol[i]] == 1){
            SelectedPlacesRow.erase(SelectedPlacesRow.begin() + i);
            SelectedPlacesCol.erase(SelectedPlacesCol.begin() + i);
            i--;
        }

        else
            CurScene->TablesPlaces[temp][SelectedPlacesRow[i]][SelectedPlacesCol[i]] = 2;
    }
    if(SelectedPlacesCol.size()){
        srand(time(NULL));
        for(int i = 0; i < 10; i++){
            Code += QString::number(std::rand() % 10);
        }
        QMessageBox::information(NULL,QObject::tr("Бронирование"),tr("Ваш код: ") + Code);
    }
    CurScene->InsertTablesToDataBase(SelectedPlacesRow, SelectedPlacesCol, ui->comboBox->currentIndex(), 2, Code);
    places_fill();
    coordinates_of_places_cleaning(ui->comboBox->currentIndex());
    customizeTableInf();
    SelectedPlacesRow.clear();
    SelectedPlacesCol.clear();
    CustomizePrice();
}

void MainWindow::on_action_exit_triggered() // пункт Выход
{

}

void MainWindow::on_action_statistic_sale_triggered() // окно статистики
{
    Statistic *wnd = new Statistic;
    wnd->exec();
}

void MainWindow::on_pushButton_3_clicked()//вернуть
{
    int temp = ui->comboBox->currentIndex();

    for(int i = 0; i < SelectedPlacesRow.size(); i++){
        if(CurScene->TablesPlaces[temp][SelectedPlacesRow[i]][SelectedPlacesCol[i]] == 0){
            SelectedPlacesRow.erase(SelectedPlacesRow.begin() + i);
            SelectedPlacesCol.erase(SelectedPlacesCol.begin() + i);
            i--;
        }
        else
            CurScene->TablesPlaces[temp][SelectedPlacesRow[i]][SelectedPlacesCol[i]] = 0;
    }
    CurScene->InsertTablesToDataBase(SelectedPlacesRow, SelectedPlacesCol, ui->comboBox->currentIndex(), 0);
    places_fill();
    coordinates_of_places_cleaning(ui->comboBox->currentIndex());
    customizeTableInf();
    SelectedPlacesRow.clear();
    SelectedPlacesCol.clear();
    CustomizePrice();
}

void MainWindow::create_a_MainTable()
{//создаю таблицу с местами
    int temp = ui->comboBox->currentIndex();
    ui->tableWidget->setRowCount(CurScene->ArrayCountPlaces[temp][0]);
    ui->tableWidget->setColumnCount(CurScene->ArrayCountPlaces[temp][1]);

    for(int i=0; i < ui->tableWidget->rowCount(); i++){
        for(int j=0; j < ui->tableWidget->columnCount(); j++){
            ui->tableWidget->setItem(i, j, new QTableWidgetItem);
        }
    }

    row_height = (ui->tableWidget->height() -10) / ui->tableWidget->rowCount();
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
//            item->setData(Qt::ToolTip, QString::number(10));
            item->setToolTip("Ряд " + QString::number(i+1));
            ui->tableWidget->setItem( i, j, item );
        }
    }
    //ui->tableWidget->setAutoScroll(false);                        // отключаю авто скролл к выбраной ячейке

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
                                   "}");
    ui->tableWidget->verticalHeader()->setVisible(true);
    ui->tableWidget->verticalHeader()->setMaximumSectionSize(ui->tableWidget->verticalHeader()->defaultSectionSize());
    ui->tableWidget->verticalHeader()->setMinimumSectionSize(ui->tableWidget->verticalHeader()->defaultSectionSize());
   // ui->tableWidget->verticalHeader()->setFixedWidth(30);         // размер хидера
}



void MainWindow::on_options_room_triggered()
{
    int temp = ui->comboBox->currentIndex();

    for(int i = 0; i < CurScene->ArrayCountPlaces[temp][0]; i++){
        delete [] coordinates_of_places[i];
    }
    delete []coordinates_of_places;

    OptionsForHall *wind = new OptionsForHall(this);
    wind->exec();

    CurScene->DeleteTables();

    CurScene->SetArrayCountPlaces();
    CurScene->SetDataToTables();

    SelectedPlacesRow.clear();
    SelectedPlacesCol.clear();

    create_a_MainTable();
    places_fill();
    customizeTableInf();

    coordinates_of_places = new bool*[CurScene->ArrayCountPlaces[temp][0]];
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
    on_dateEdit_dateChanged(QDate::fromString(ui->dateEdit->text(), "dd.MM.yyyy"));
}

void MainWindow::customizeTableInf()
{
    CountPurchased = 0;
    CountBooked = 0;

    int temp = ui->comboBox->currentIndex();
        for(int i=0; i < CurScene->ArrayCountPlaces[temp][0] ; i++)
        {
            for(int j=0; j < CurScene->ArrayCountPlaces[temp][1]; j++)
            {
                if(CurScene->TablesPlaces[temp][i][j] == 1)
                    CountPurchased++;
                if(CurScene->TablesPlaces[temp][i][j] == 2)
                    CountBooked++;
            }
        }

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

void MainWindow::slotDelRecord(){
    int row = ui->tableSeans->currentRow();

    QSqlQuery qry1("delete from Postanovka where name='" + ui->tableSeans->item(row, 1)->text() + "' and time_seansa='" + ui->tableSeans->item(row, 0)->text() + "' and date_seansa='" + ui->dateEdit->text() + "'");
    QSqlQuery qry2("delete from Employed_place where name_seansa='" + ui->tableSeans->item(row, 1)->text() + "' and time_seansa='" + ui->tableSeans->item(row, 0)->text() + "' and date_seansa='" + ui->dateEdit->text() + "'");
    if(ui->tableSeans->item(row, 1)->text() == CurScene->name && ui->tableSeans->item(row, 0)->text() == CurScene->time && ui->dateEdit->text() == CurScene->date){
        delete CurScene;
        CurScene = new Scene();

        ui->comboBox->setEnabled(false);
        ui->pushButton->setEnabled(false);
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

void MainWindow::DeleteBooked(std::vector <short> PurRow, std::vector<short>PurCol)
{
    for(int i = 0; i < PurRow.size(); i++){
        QSqlQuery qry("delete from Employed_place where type_place = '" + QString::number(ui->comboBox->currentIndex()) +"' and date_seansa = '" + CurScene->date + "' and time_seansa='" + CurScene->time + "' and name_seansa='" + CurScene->name + "' and row=" + QString::number(PurRow[i]) + " and column=" + QString::number(PurCol[i]));
    }
}

void MainWindow::CustomizePrice(){
    int CountChecked = 0;
    int temp = ui->comboBox->currentIndex();
    for(int i=0; i < CurScene->ArrayCountPlaces[temp][0]; i++){
        for(int j = 0; j < CurScene->ArrayCountPlaces[temp][1]; j++){
            if(coordinates_of_places[i][j])
                CountChecked++;
        }
    }

    ui->LabelCountSel->setText("Выбрано: " + QString::number(CountChecked));
}

void MainWindow::on_pushButtonCode_clicked()
{
    places_fill();
    coordinates_of_places_cleaning(ui->comboBox->currentIndex());

    SelectedPlacesRow.clear();
    SelectedPlacesCol.clear();

    QSqlQuery qry("select * from Employed_place where code='" + ui->lineEditCode->text() + "' and name_seansa='" + CurScene->name + "' and date_seansa='" + CurScene->date + "' and time_seansa='" + CurScene->time + "' and type_place='" + ui->comboBox->currentText() + "'");
    bool Enabled = true;
    while(qry.next()){
        coordinates_of_places[qry.value(5).toInt()][qry.value(6).toInt()] = true;

        SelectedPlacesRow.push_back(qry.value(5).toInt());
        SelectedPlacesCol.push_back(qry.value(6).toInt());

        pix_checking(qry.value(5).toInt(), qry.value(6).toInt());
        Enabled = false;
    }
    if(Enabled){
        QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Для данной постановки код не найден."));
    }
}
void MainWindow::resizeEvent(QResizeEvent* e)
{
    emit MyWindowReSize(e);
    QWidget::resizeEvent(e);
}

void MainWindow::main_window_resize(QResizeEvent *event)
{
   /* QPixmap  pix;
    pix.load(":/image/scena.png");
    pix = pix.scaled(ui->label_2->size());
    ui->label_2->setPixmap(pix);*/
}
