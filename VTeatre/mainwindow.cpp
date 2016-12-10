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
    mydb.setDatabaseName("D:/Cursovaya/Cursovaya/VTeatre.sqlite");

    CurScene = new Scene(3);

    if(!mydb.open())
        qDebug()<<mydb.lastError().text();
    else
        qDebug()<<"Connected Compled";

    QSqlQuery qry("select * from Options where type_place = '" + ui->comboBox->currentText() + "'");
    qry.next();
    CountRow = qry.value(1).toInt();
    CountColumn = qry.value(2).toInt();

    PreviousIndex = 0;
    CountPurchased = 0;
    CountBooked = 0;

    QPixmap  pix;
    pix.load(":/image/scena.png");
    pix = pix.scaled(ui->label_2->size());
    ui->label_2->setPixmap(pix);

    QPixmap pix_Legend(":/image/Legend.png");
    pix_Legend = pix_Legend.scaled(ui->label_4->size(), Qt::KeepAspectRatio);
    ui->label_4->setPixmap(pix_Legend);


    dt = QDateTime::currentDateTime();
    ui->dateEdit->setDateTime(dt);
    ui->dateEdit->setMinimumDateTime(dt); // минимальная дата выставляется по текущей дате

    ui->tableSeans->setEditTriggers(QAbstractItemView::NoEditTriggers); //запрет редактирования всех ячеек в таблице tableSeans
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //запрет редактирования всех ячеек в таблице tableWidget

    ui->tableSeans->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents); // Ширина столбца с датой по размеру контента
    ui->tableSeans->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch); // Ширина столбца с названиями всё остальное пространство

    coordinates_of_places = new bool*[CountRow];
    for(int i = 0; i < CountRow; i++)
        coordinates_of_places[i] = new bool [CountColumn];
    for(int i=0; i < CountRow; i++)
        for(int j = 0; j < CountColumn; j++)
        {
            coordinates_of_places[i][j]=false;
        }

    ui->comboBox->setEnabled(false);

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
    for(int i = 0; i < CurScene->ArrayCountPlaces[temp][0]; i++)
        delete [] coordinates_of_places[i];
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

        for(int i = 0; i < SelectedPlaces.size(); i ++){
            if(SelectedPlaces[i] == CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][1] * row + column + 1){
                SelectedPlaces.erase(SelectedPlaces.begin() + i - 1);
            }
        }
    }
    else
    {
        coordinates_of_places[row][column]=true;
        pix_checking(row,column);
        SelectedPlaces.push_back(CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][1] * row + column + 1);
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index) // по изменению пункта в combobox менять таблицу
{
    coordinates_of_places_cleaning(PreviousIndex);

    create_a_MainTable();
    places_fill();
    customizeTableInf();

    SelectedPlaces.clear();

    PreviousIndex = index;
}


void MainWindow::on_tableSeans_cellClicked(int row, int column) // по нажатию на название изменить таблицу с местами
{
    if(column == 1)
    {
        ui->comboBox->setEnabled(true);

        delete CurScene;
        CurScene = new Scene(3);

        //1 - найти имя, время, дата
        CurScene->set_name(ui->tableSeans->item(row, 1)->text());
        CurScene->set_time(ui->tableSeans->item(row, 0)->text());
        CurScene->set_date(ui->dateEdit->text());

        //2 - найти количество мест в каждом типе
        CurScene->SetArrayCountPlaces();

        //3 - найти инф. о каждом месте
        CurScene->SetDataToTables();

        coordinates_of_places_cleaning(ui->comboBox->currentIndex());
        create_a_MainTable();
        places_fill();
        customizeTableInf();

        SelectedPlaces.clear();
        ui->comboBox->setCurrentIndex(0);
    }
}

void MainWindow::on_dateEdit_dateChanged(const QDate &date)//Выводит сеансы по дате
{
        QString date_seansa=ui->dateEdit->text();
        QSqlQuery qry1("select * from Postanovka where date_seansa='"+date_seansa+"'");

        int i = 0;
        QString Postanovka[255][2];
        while(qry1.next())
        {
            for(int j=0; j < 2 ;++j)
            {
                Postanovka[i][j]=qry1.value(1-j).toString();//записывает данные спектакля в массив
            }
            i++;
         }

        // работа с таблицей сеансов-------------------------------

        ui->tableSeans->setRowCount(i); // указываем количество строк, вместо 10 нужно подставлять количество спектаклей на какое-то число

        for(int row = 0; row < i; row++)
        {
            for(int column = 0; column < 2; column++)
            {
                ui->tableSeans->setItem(row, column, new QTableWidgetItem); // вставляем ячейку
            }
        }
        for(int k = 0; k < i; k++)
        {
            for(int j = 0; j < 2; j++)
            {
                ui->tableSeans->item(k, j)->setText(Postanovka[k][j]);
            }
        }
}

void MainWindow::on_pushButton_clicked() // купить
{
    int temp = ui->comboBox->currentIndex();

    for(int i = 0; i < SelectedPlaces.size(); i++){

        int row = (SelectedPlaces[i] - 1) / CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][1];
        int column  = (SelectedPlaces[i] - 1)  % CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][1];

        if(CurScene->TablesPlaces[temp][row][column] == 1 || CurScene->TablesPlaces[temp][row][column] == 2){
            SelectedPlaces.erase(SelectedPlaces.begin() + i - 1);
            i--;
        }
        else
            CurScene->TablesPlaces[temp][row][column] = 1;
    }
    CurScene->InsertTablesToDataBase(SelectedPlaces, ui->comboBox->currentIndex(), 1);
    places_fill();
    coordinates_of_places_cleaning(ui->comboBox->currentIndex());
    customizeTableInf();
    SelectedPlaces.clear();
}

void MainWindow::on_pushButton_2_clicked() // забронировать
{
    int temp = ui->comboBox->currentIndex();

    for(int i = 0; i < SelectedPlaces.size(); i++){

        int row = (SelectedPlaces[i] - 1) / CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][1];
        int column  = (SelectedPlaces[i] - 1)  % CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][1];

        if(CurScene->TablesPlaces[temp][row][column] == 2 || CurScene->TablesPlaces[temp][row][column] == 1){
            SelectedPlaces.erase(SelectedPlaces.begin() + i - 1);
            i--;
        }
        else
            CurScene->TablesPlaces[temp][row][column] = 2;
    }
    CurScene->InsertTablesToDataBase(SelectedPlaces, ui->comboBox->currentIndex(), 2);
    places_fill();
    coordinates_of_places_cleaning(ui->comboBox->currentIndex());
    customizeTableInf();
    SelectedPlaces.clear();
}

void MainWindow::on_action_exit_triggered() // пункт Выход
{
}

void MainWindow::on_action_statistic_sale_triggered() // окно статистики
{
    Statistic *wind = new Statistic(dt, this);
    wind->show();
}

void MainWindow::on_pushButton_3_clicked()//вернуть
{
    int temp = ui->comboBox->currentIndex();

    for(int i = 0; i < SelectedPlaces.size(); i++){

        int row = (SelectedPlaces[i] - 1) / CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][1];
        int column  = (SelectedPlaces[i] - 1)  % CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][1];

        if(CurScene->TablesPlaces[temp][row][column] == 0){
            SelectedPlaces.erase(SelectedPlaces.begin() + i - 1);
        }
        else
            CurScene->TablesPlaces[temp][row][column] = 0;
    }
    CurScene->InsertTablesToDataBase(SelectedPlaces, ui->comboBox->currentIndex(), 0);
    places_fill();
    coordinates_of_places_cleaning(ui->comboBox->currentIndex());
    customizeTableInf();
    SelectedPlaces.clear();
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
    column_width = (ui->tableWidget->width() -10) / ui->tableWidget->columnCount();

    for(int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        ui->tableWidget->setRowHeight(i, row_height); // высота строк
        for(int j = 0; j < ui->tableWidget->columnCount(); j++)
        {
            if(i == 0)
                ui->tableWidget->setColumnWidth(j, column_width); // ширина столбцов

            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(QString::number(i * ui->tableWidget->columnCount() + j + 1));
            item->setTextAlignment(Qt::AlignCenter);
            item->setFlags(item->flags() & (~Qt::ItemIsSelectable)); // устанавливаю флаг ItemIsSelectable в false
            ui->tableWidget->setItem( i, j, item );
        }
    }
    ui->tableWidget->setAutoScroll(false);                        // отключаю авто скролл к выбраной ячейке

}

void MainWindow::on_options_room_triggered()
{
    OptionsForHall *wind = new OptionsForHall(this);
    wind->exec();

    QSqlQuery qry("select * from Options");

    for (int i = 0; qry.next(); i++) {
        CurScene->ArrayCountPlaces[i][0] = qry.value(1).toInt();
        CurScene->ArrayCountPlaces[i][1] = qry.value(2).toInt();
    }

    QSqlQuery qry1("select place, type_place, date_seansa, time_seansa, name_seansa from Employed_place");
    //QString Names[3] = {"Партер", "Бенуар", "Бельэтаж"};
    while(qry1.next()){

        QSqlQuery qry2("update Employed_place set column=" + QString::number( (qry1.value(0).toInt() - 1) / qry1.value(1).toInt() ) + ", row=" + QString::number( (qry1.value(0).toInt() - 1) % qry1.value(1).toInt() ) + " where type_place='" + qry1.value(1).toString() + "' and date_seansa='" + qry.value(2).toString() + "' and time_seansa='" + qry1.value(3).toString() + "' and name_seansa='" + qry.value(4).toString() + "'");
        qDebug()<<qry1.value(0).toInt();
    }

    CurScene->SetDataToTables();

    coordinates_of_places_cleaning(ui->comboBox->currentIndex());
    SelectedPlaces.clear();

    create_a_MainTable();
    places_fill();
    customizeTableInf();
}

void MainWindow::on_action_addScene_triggered()                 // нажатие на "Добавить постановку"
{
    AddScene *window = new AddScene(this);
    window->show();
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
    /* Подключаем СЛОТы обработчики для действий контекстного меню */
    connect(editDevice, SIGNAL(triggered()), this, SLOT(slotEditRecord()));     // Обработчик вызова диалога редактирования
    /* Устанавливаем действия в меню */
    menu->addAction(editDevice);
    /* Вызываем контекстное меню */
    menu->popup(ui->tableSeans->viewport()->mapToGlobal(pos));
}
void MainWindow::slotEditRecord()
{
    int row = ui->tableSeans->currentRow();
    //Проверяем, что строка была действительно выбрана
    if(row >= 0){
        /* Задаём вопрос, стоит ли действительно редактировать запись.
         * При положительном ответе редактируем запись
         * */
        if (QMessageBox::warning(this,
                                 trUtf8("Редактирование записи"),
                                 trUtf8("Вы уверены, что хотите редактировать эту запись?"),
                                 QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
            return;
        else {
            // В противном случае производим редактирование записи
            // Твой выход, кодер.
            AddScene *temp = new AddScene(CurScene, this);
            temp->show();
        }
    }
}
