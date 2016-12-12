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

    CurScene->SetArrayCountPlaces();

    PreviousIndex = 0;
    CountPurchased = 0;
    CountBooked = 0;

    QPixmap  pix;
    pix.load(":/image/scena.png");
    pix = pix.scaled(ui->label_2->size());
    ui->label_2->setPixmap(pix);

   /* QPixmap pix_Legend(":/image/Legend.png");
    pix_Legend = pix_Legend.scaled(ui->label_4->size(), Qt::KeepAspectRatio);
    ui->label_4->setPixmap(pix_Legend);*/

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

    QString date = ui->dateEdit->text();
    QSqlQuery qry_delete("delete from Postanovka where date_seansa<'" +date+ "'");
    QSqlQuery qry_delete1("delete from Employed_place where date_seansa<'" +date+ "'");

    /*qry_insert.prepare("insert into Date(date_seansa) values(':date');");
    qry_insert.bindValue(":date", "14.12.2016");*/
    //QDateTime dt1= QDateTime::fromString("12.12.2016", "dd.MM.yyyy");

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
    /*for(int i = 0; i < CurScene->ArrayCountPlaces[temp][0]; i++){
        delete [] coordinates_of_places[i];
    }
    delete []coordinates_of_places;*/

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
    qDebug()<<1;
    if(coordinates_of_places[row][column])//проверяет активно ли нажатое место
    {qDebug()<<2;
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
    {qDebug()<<3;
        coordinates_of_places[row][column]=true;
        pix_checking(row,column);
        SelectedPlacesRow.push_back(row);
        SelectedPlacesCol.push_back(column);
    }
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
        else
            CurScene->TablesPlaces[temp][SelectedPlacesRow[i]][SelectedPlacesCol[i]] = 1;
    }

    DeleteBooked(PurRow, PurCol);
    CurScene->InsertTablesToDataBase(SelectedPlacesRow, SelectedPlacesCol, ui->comboBox->currentIndex(), 1);
    places_fill();
    coordinates_of_places_cleaning(ui->comboBox->currentIndex());
    customizeTableInf();
    SelectedPlacesRow.clear();
    SelectedPlacesCol.clear();
}

void MainWindow::on_pushButton_2_clicked() // забронировать
{
    int temp = ui->comboBox->currentIndex();
    for(int i = 0; i < SelectedPlacesRow.size(); i++){
        if(CurScene->TablesPlaces[temp][SelectedPlacesRow[i]][SelectedPlacesCol[i]] == 2 || CurScene->TablesPlaces[temp][SelectedPlacesRow[i]][SelectedPlacesCol[i]] == 1){
            SelectedPlacesRow.erase(SelectedPlacesRow.begin() + i);
            SelectedPlacesCol.erase(SelectedPlacesCol.begin() + i);
            i--;
        }

        else
            CurScene->TablesPlaces[temp][SelectedPlacesRow[i]][SelectedPlacesCol[i]] = 2;
    }
    CurScene->InsertTablesToDataBase(SelectedPlacesRow, SelectedPlacesCol, ui->comboBox->currentIndex(), 2);
    places_fill();
    coordinates_of_places_cleaning(ui->comboBox->currentIndex());
    customizeTableInf();
    SelectedPlacesRow.clear();
    SelectedPlacesCol.clear();
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

    for(int i = 0; i < SelectedPlacesRow.size(); i++){
        if(CurScene->TablesPlaces[temp][SelectedPlacesRow[i]][SelectedPlacesCol[i]] == 0){
            SelectedPlacesRow.erase(SelectedPlacesRow.begin() + i);
            SelectedPlacesCol.erase(SelectedPlacesCol.begin() + i);
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
            item->setText(QString::number(j + 1));
            item->setTextAlignment(Qt::AlignCenter);
            item->setFlags(item->flags() & (~Qt::ItemIsSelectable)); // устанавливаю флаг ItemIsSelectable в false
//            item->setData(Qt::ToolTip, QString::number(10));
            item->setToolTip("Ряд " + QString::number(i+1));
            ui->tableWidget->setItem( i, j, item );
        }
    }
    ui->tableWidget->setAutoScroll(false);                        // отключаю авто скролл к выбраной ячейке
}

void MainWindow::on_options_room_triggered()
{
    int temp = ui->comboBox->currentIndex();

    OptionsForHall *wind = new OptionsForHall(this);
    wind->exec();

    CurScene->SetArrayCountPlaces();
    CurScene->SetDataToTables();


    SelectedPlacesRow.clear();
    SelectedPlacesCol.clear();

    create_a_MainTable();
    coordinates_of_places_cleaning(ui->comboBox->currentIndex());
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

            AddScene *temp = new AddScene(true, CurScene, this);
            temp->exec();
            on_dateEdit_dateChanged(QDate::fromString(ui->dateEdit->text(), "dd.MM.yyyy"));
        }
    }
}

void MainWindow::DeleteBooked(std::vector <short> PurRow, std::vector<short>PurCol)
{
    for(int i = 0; i < PurRow.size(); i++){
        QSqlQuery qry("delete from Employed_place where type_place = '" + QString::number(ui->comboBox->currentIndex()) +"' and date_seansa = '" + CurScene->date + "' and time_seansa='" + CurScene->time + "' and name_seansa='" + CurScene->name + "' and row=" + QString::number(PurRow[i]) + " and column=" + QString::number(PurCol[i]));
    }
}
