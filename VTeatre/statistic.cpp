#include "statistic.h"
#include "ui_statistic.h"

Statistic::Statistic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistic)
{
    ui->setupUi(this);


    //Changing ticks on y axis
    QVector<double> ticks;
    int tmp = -100;
    while(tmp <= 100){
        ticks.push_back(tmp);
        tmp += 10;
    }
    ui->widget->yAxis->setAutoTicks(false);
    ui->widget->yAxis->setTickVector(ticks);

    //Making setup for physical graph
    ui->widget->addGraph();
    ui->widget->graph(0)->setPen(QPen(QColor("#0026A4"), 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    //ui->widget->graph(0)->setBrush(QBrush(QPixmap("./balboa.jpg"))); // fill with texture of specified image
    ui->widget->graph(0)->setLineStyle(QCPGraph::lsLine);
    //ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
    ui->widget->graph(0)->setName("Партер");

    //Making setup for emotional graph
    ui->widget->addGraph();
    ui->widget->graph(1)->setPen(QPen(QColor("#0BB3A8"), 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    //ui->widget->graph(1)->setBrush(QBrush(QPixmap("./balboa.jpg"))); // fill with texture of specified image
    ui->widget->graph(1)->setLineStyle(QCPGraph::lsLine);
    //ui->widget->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
    ui->widget->graph(1)->setName("Бенуар");

    //Making setup for intelectual graph
    ui->widget->addGraph();
    ui->widget->graph(2)->setPen(QPen(QColor("#973A12"), 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    //ui->widget->graph(2)->setBrush(QBrush(QPixmap("./balboa.jpg"))); // fill with texture of specified image
    ui->widget->graph(2)->setLineStyle(QCPGraph::lsLine);
    //ui->widget->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
    ui->widget->graph(2)->setName("Бельэтаж");

    //Подписываем оси Ox и Oy
    ui->widget->xAxis->setLabel("Дата");
    ui->widget->yAxis->setLabel("Количество проданных мест");

    // configure bottom axis to show date instead of number:
    ui->widget->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->widget->xAxis->setDateTimeFormat("dd.MM.yyyy");
    ui->widget->xAxis->setTickLabelRotation(45);
    ui->widget->xAxis->setAutoTickStep(true);
    ui->widget->xAxis->setTickLabels(false);
    //ui->widget->xAxis->setTickStep(86400000);

    //Making legend
    ui->widget->legend->setVisible(true);
    QFont legendFont = font();  // start out with MainWindow's font..
    legendFont.setPointSize(9); // and make a bit smaller for legend
    ui->widget->legend->setFont(legendFont);
    ui->widget->legend->setBrush(QBrush(QColor(255,255,255,150)));
    // by default, the legend is in the inset layout of the main axis rect. So this is how we access it to change legend placement:
    ui->widget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
}

Statistic::~Statistic()
{
    delete ui;
}



void Statistic::on_pushButton_clicked()
{
    DataforStatistic *data = new DataforStatistic(7);
    data->InsertData();
    //Пока данил не сделал БД
    /*data->DataOfPlaces[0][0][0] = QString::number(55);
    data->DataOfPlaces[0][1][0] = QString::number(60);
    data->DataOfPlaces[0][2][0] = QString::number(16);

    data->DataOfPlaces[1][0][0] = QString::number(54);
    data->DataOfPlaces[1][1][0] = QString::number(70);
    data->DataOfPlaces[1][2][0] = QString::number(10);

    data->DataOfPlaces[2][0][0] = QString::number(60);
    data->DataOfPlaces[2][1][0] = QString::number(59);
    data->DataOfPlaces[2][2][0] = QString::number(40);

    data->DataOfPlaces[3][0][0] = QString::number(15);
    data->DataOfPlaces[3][1][0] = QString::number(67);
    data->DataOfPlaces[3][2][0] = QString::number(47);

    data->DataOfPlaces[4][0][0] = QString::number(39);
    data->DataOfPlaces[4][1][0] = QString::number(76);
    data->DataOfPlaces[4][2][0] = QString::number(45);

    data->DataOfPlaces[5][0][0] = QString::number(63);
    data->DataOfPlaces[5][1][0] = QString::number(56);
    data->DataOfPlaces[5][2][0] = QString::number(24);

    data->DataOfPlaces[6][0][0] = QString::number(5);
    data->DataOfPlaces[6][1][0] = QString::number(45);
    data->DataOfPlaces[6][2][0] = QString::number(96);
    //
    data->DataOfPlaces[0][0][1] = "15.12.2016";
    data->DataOfPlaces[0][1][1] = "15.12.2016";
    data->DataOfPlaces[0][2][1] = "15.12.2016";

    data->DataOfPlaces[1][0][1] = "14.12.2016";
    data->DataOfPlaces[1][1][1] = "14.12.2016";
    data->DataOfPlaces[1][2][1] = "14.12.2016";

    data->DataOfPlaces[2][0][1] = "13.12.2016";
    data->DataOfPlaces[2][1][1] = "13.12.2016";
    data->DataOfPlaces[2][2][1] = "13.12.2016";

    data->DataOfPlaces[3][0][1] = "12.12.2016";
    data->DataOfPlaces[3][1][1] = "12.12.2016";
    data->DataOfPlaces[3][2][1] = "12.12.2016";

    data->DataOfPlaces[4][0][1] = "11.12.2016";
    data->DataOfPlaces[4][1][1] = "11.12.2016";
    data->DataOfPlaces[4][2][1] = "11.12.2016";

    data->DataOfPlaces[5][0][1] = "10.12.2016";
    data->DataOfPlaces[5][1][1] = "10.12.2016";
    data->DataOfPlaces[5][2][1] = "10.12.2016";

    data->DataOfPlaces[6][0][1] = "09.12.2016";
    data->DataOfPlaces[6][1][1] = "09.12.2016";
    data->DataOfPlaces[6][2][1] = "09.12.2016";*/

    CreateGraph(data, 7);
}

void Statistic::CreateGraph(DataforStatistic *data, int CountDays){
    QVector <double> date;
    QVector <double> par;
    for(int i = 0; i < CountDays; i++){
        QDateTime t = QDateTime::fromString(data->DataOfPlaces[i][0][1], "dd.MM.yyyy");
        date.push_back(t.toTime_t());
        par.push_back(data->DataOfPlaces[i][0][0].toDouble());
    }

    ui->widget->graph(0)->setData(date, par);

    QDateTime s = QDateTime::fromString(data->DataOfPlaces[6][0][1], "dd.MM.yyyy");
    QDateTime f = QDateTime::fromString(data->DataOfPlaces[0][0][1], "dd.MM.yyyy");

    ui->widget->yAxis->setRange(0, 100);//Для оси Oy
    ui->widget->xAxis->setRange(s.toTime_t(), f.toTime_t());//Для оси Ox

    ui->widget->xAxis->setTickLabels(true);
    //И перерисуем график на нашем widget
    ui->widget->replot();
    qDebug()<<s.toTime_t();
    qDebug()<<f.toTime_t();
}
