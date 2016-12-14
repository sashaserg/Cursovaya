#include "statistic.h"
#include "ui_statistic.h"
#include "dataforstatistic.h"

Statistic::Statistic(QDateTime datenow, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistic)
{
    ui->setupUi(this);

/*
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
    ui->widget->graph(0)->setName("Physical graph");

    //Making setup for emotional graph
    ui->widget->addGraph();
    ui->widget->graph(1)->setPen(QPen(QColor("#0BB3A8"), 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    //ui->widget->graph(1)->setBrush(QBrush(QPixmap("./balboa.jpg"))); // fill with texture of specified image
    ui->widget->graph(1)->setLineStyle(QCPGraph::lsLine);
    //ui->widget->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
    ui->widget->graph(1)->setName("Emotional graph");

    //Making setup for intelectual graph
    ui->widget->addGraph();
    ui->widget->graph(2)->setPen(QPen(QColor("#973A12"), 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    //ui->widget->graph(2)->setBrush(QBrush(QPixmap("./balboa.jpg"))); // fill with texture of specified image
    ui->widget->graph(2)->setLineStyle(QCPGraph::lsLine);
    //ui->widget->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
    ui->widget->graph(2)->setName("Intelectual graph");

    //Подписываем оси Ox и Oy
    ui->widget->xAxis->setLabel("Date");
    ui->widget->yAxis->setLabel("State");

    // configure bottom axis to show date instead of number:
    ui->widget->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->widget->xAxis->setDateTimeFormat("d. MMMM\nyyyy");
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
    ui->widget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);*/
}

Statistic::~Statistic()
{
    delete ui;
}



void Statistic::on_pushButton_clicked()
{
    DataforStatistic obj;
    obj.set_count_place(7);
    obj.set_date(7);
    obj.set_type_place(7);
    std::vector<QString> date = obj.get_date();
    std::vector<int> count_place = obj.get_count_place();
    std::vector<QString> type_place = obj.get_type_place();
    for(int i = 0; i<7 ; i++)
    {
        qDebug()<<date[i];
    }
    for(int i = 0; i<7; i++)
    {
        qDebug()<<type_place[i];
    }
}
