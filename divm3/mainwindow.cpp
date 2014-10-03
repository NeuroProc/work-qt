#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    rx.setPattern("(\\d.\\d),(\\d.\\d)");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::msgErr(double x)
{
    QMessageBox msg;

    msg.setText(QString("Can't be calculated for given interval. A point of discontinuity: ") + QString::number(x));
    msg.exec();
}

double MainWindow::fIntegrate(double x)
{
    double cosres = pow(cos(x), 2);

    if (cosres <= 0.000001)
    {
        qDebug() << x;
        return 0;
    }
    else
        return 1 / cosres;
}

double MainWindow::fDifferential(double x)
{
    return (1 / sin(pow(x, 2)));
}

double MainWindow::Simpson(double a, double b, double h)
{

    //double h = (b - a) / n;
    int n = (b - a) / h;
    double sum = 0;

    double x0 = a;
    double x1 = a + h;

    for (int i = 0; i <= n-1; i++)
    {
        if (fIntegrate(x1) == 0)
        {
            msgErr(x1);
            return 0;
        }
        sum += fIntegrate(x0) + 4 * fIntegrate(x0 + h / 2) + fIntegrate(x1);

        x0 += h;
        x1 += h;
    }

    return (h / 6) * sum;
}


double MainWindow::Gauss(double a, double b, double eps)
{
    //double eps = 0.01;
    int n = 4, k = 1;
    double INT1, INT2 = 1, h, s, x;
    double X[] = {0.0694318, 0.3300095, 0.6699905, 0.9305682};
    double A[] = { 0.1739274, 0.3260726, 0.3260726, 0.1739274 };

    h = eps;
    while (h >= eps)
    {
        INT1 = INT2;
        k = k * 2;
        h = (b - a) / k; //шаг интегрирования
        s = 0;
        for (int j = 0; j < k; j++)
        {
            x = a + j * h;
            for (int i = 0; i < n; i++)
            {
                if (fIntegrate(x) == 0)
                {
                    msgErr(x);
                    return 0;
                }
                x = x + X[i] * h;
                s += fIntegrate(x) * A[i];
            }
        }
        INT2 = h * s;
    }
    return INT2;
}

double MainWindow::Splain(double a, double b, double x, double h)
{
    int n = (b - a) / h;
    double y_1 = 0, y_2 = 0;
    double h1;
    double h2;
    double aa;
    double y[n - 1];

    aa = a;
    int i = 0;
    for (i = 0; i < n - 1; i++)
    {
        y[i] = fDifferential(aa);
        aa += h;
    }
    i = floor((x - a)/h + h/2);
    h1 = 2 * h;
    h2 =h * h;
    if (i == 0)
    {
        y_1 = ( -3 * y[0] + 4 * y[1]-y[2]) / h1;
        y_2 = (2 * y[0] - 5 * y[1] + 4 * y[2] - y[3]) / h2;
    }
    if (i > 0 && i < ((n - 1) - 1))
    {
        y_1 = (-y[i-1] + y[i+1]) / h1;
        y_2 = (y[i-1] - 2 * y[i] + y[i+1]) / h2;
    }
    if (i == ((n - 1) - 1))
    {
        y_1 = (y[n-2] - 4*y[n-1]+3*y[n])/h1;
        y_2 = (-y[n-3]+4*y[n-2]-5*y[n-1]+2*y[n]) / h2;
    }


    QString str;
    str += QString("y'(x) = ") + QString::number(y_1) + '\n' + QString("y''(x) = ") + QString::number(y_2);
    ui->label_4->setText(str);

    return y_2;
}

void MainWindow::on_pushButton_clicked()
{
    rx.indexIn(ui->lineEdit->text());

    qDebug() << rx.cap();
    double res = Simpson(rx.cap(1).toDouble(), rx.cap(2).toDouble(), ui->lineEdit_2->text().toDouble());

    ui->label_4->setText(QString::number(res));


}

void MainWindow::on_pushButton_3_clicked()
{
    rx.indexIn(ui->lineEdit->text());

    if (ui->lineEdit_3->text().toDouble() == 0)
    {
        msgErr(0);
        return;
    }
    Splain(rx.cap(1).toDouble(), rx.cap(2).toDouble(), ui->lineEdit_3->text().toDouble(), ui->lineEdit_2->text().toDouble());

}

void MainWindow::on_pushButton_2_clicked()
{

    rx.indexIn(ui->lineEdit->text());

    qDebug() << ui->lineEdit_2->text().toDouble();

    double res = Gauss(rx.cap(1).toDouble(), rx.cap(2).toDouble(), ui->lineEdit_2->text().toDouble());

    ui->label_4->setText(QString::number(res));
}
