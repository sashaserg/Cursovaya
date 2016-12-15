#include "statistic.h"
#include "ui_statistic.h"

Statistic::Statistic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistic)
{
    ui->setupUi(this);


    //Changing ticks on y axis


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
    ui->widget->yAxis->setAutoTickStep(true);
    ui->widget->yAxis->setTickLabels(false);
    //ui->widget->xAxis->setTickStep(86400000);

    //Making legend
    ui->widget->legend->setVisible(true);
    QFont legendFont = font();  // start out with MainWindow's font..
    legendFont.setPointSize(9); // and make a bit smaller for legend
    ui->widget->legend->setFont(legendFont);
    ui->widget->legend->setBrush(QBrush(QColor(255,255,255,150)));
    // by default, the legend is in the inset layout of the main axis rect. So this is how we access it to change legend placement:
    ui->widget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);
}

Statistic::~Statistic()
{
    delete ui;
}



void Statistic::on_pushButton_clicked()
{
    DataforStatistic *data = new DataforStatistic(7);
    data->InsertData();

    CreateGraph(data, 7);
}

void Statistic::CreateGraph(DataforStatistic *data, int CountDays){
    QVector <double> date;
    QVector <double> par;
    QVector <double> ben;
    QVector <double> bel;

    int MaxValueY = 0;
    for(int i = 0; i < CountDays; i++){
        QDateTime t = QDateTime::fromString(data->DataOfPlaces[i][0][1], "dd.MM.yyyy");

        date.push_back(t.toTime_t());
        par.push_back(data->DataOfPlaces[i][0][0].toDouble());
        ben.push_back(data->DataOfPlaces[i][1][0].toDouble());
        bel.push_back(data->DataOfPlaces[i][2][0].toDouble());

        if(par[i] > MaxValueY)
            MaxValueY = par[i];
        if(ben[i] > MaxValueY)
            MaxValueY = ben[i];
        if(bel[i] > MaxValueY)
            MaxValueY = bel[i];
    }

    for(int i = 0; i < CountDays; i++){
        qDebug()<<par[i]<<" "<<date[i];
    }
    ui->widget->graph(0)->setData(date, par);
    ui->widget->graph(1)->setData(date, ben);
    ui->widget->graph(2)->setData(date, bel);

    QDateTime s = QDateTime::fromString(data->DataOfPlaces[CountDays - 1][0][1], "dd.MM.yyyy");
    QDateTime f = QDateTime::fromString(data->DataOfPlaces[0][0][1], "dd.MM.yyyy");

    ui->widget->yAxis->setRange(0, MaxValueY * 1.1);//Для оси Oy
    ui->widget->xAxis->setRange(s.toTime_t(), f.toTime_t());//Для оси Ox

    ui->widget->xAxis->setTickLabels(true);
    ui->widget->yAxis->setTickLabels(true);
    QVector<double> ticks;

    for(int i = 0; i < MaxValueY + 10; i += MaxValueY / 10){
        ticks.push_back(i);
    }
    ui->widget->yAxis->setAutoTicks(false);
    ui->widget->yAxis->setTickVector(ticks);

    //И перерисуем график на нашем widget
    ui->widget->replot();
    qDebug()<<s.toTime_t();
    qDebug()<<f.toTime_t();
}

void Statistic::on_pushButton_2_clicked()
{
    DataforStatistic *data = new DataforStatistic(30);
    data->InsertData();

    CreateGraph(data, 30);
}
