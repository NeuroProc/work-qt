#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QList>
//#include <QString>
#include <QTableView>
#include <QStandardItemModel>
//#include <exception>

void incMatrix();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->tableWidget->setSizeIncrement(ui->tableWidget->width() + ui->tableWidget->horizontalHeader()->defaultSectionSize(),
    //                                  ui->tableWidget->height() + ui->tableWidget->verticalHeader()->defaultSectionSize());

    incMatrix();
    incMatrix();
    incMatrix();
    incMatrix();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   QMessageBox msg;



/*
   msg.setText("FIRST");
   msg.exec();

   QList<int> a;
   for (int i = 0; i < 10; i++)
       a[i] = i*10;

   QStandardItemModel *tableModel = new QStandardItemModel(2,3,this); //2 Rows and 3 Columns
   tableModel->setHorizontalHeaderItem(0, new QStandardItem(QString("1")));
   tableModel->setHorizontalHeaderItem(1, new QStandardItem(QString("2")));
   tableModel->setHorizontalHeaderItem(2, new QStandardItem(QString("3")));

   ui->tableView->setModel(tableModel);
*/
   ui->textEdit->clear();

   if (ui->radioButton->isChecked())
        computeGauss();
   else
        computeHoleckii();

}


void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    QMessageBox msg;
/*
    msg.setText(QString::number(row));
    msg.exec();

    QTableWidgetItem tmp = *(ui->tableWidget->item(row, column));
    QString str = tmp.text();

    try
    {
        str.toInt();
    }
    catch (...)
    {
        msg.setText(QString("ERROR %1").arg(str));
        ui->tableWidget->setItem(row, column, new QTableWidgetItem(QString("0")));

        return;
    }
*/

    if (ui->tableWidget->rowCount() - 1 == row /*|| ui->tableWidget->columnCount() - 1 == column*/)
    {

        incMatrix();

    }
}

void MainWindow::incMatrix()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
    ui->tableWidget->setColumnCount(ui->tableWidget->columnCount() + 1);
    ui->tableWidget->setGeometry(QRect(ui->tableWidget->geometry().x(), ui->tableWidget->geometry().y(),
                                               ui->tableWidget->width() + 101,
                                               ui->tableWidget->height() + 31));

    //ui->tableWidget->setGeometry(QRect(ui->tableWidget->geometry().x(), ui->tableWidget->geometry().y(),
    //                                       ui->tableWidget->width() + ui->tableWidget->horizontalHeader()->defaultSectionSize(),
    //                                       ui->tableWidget->height() + ui->tableWidget->verticalHeader()->defaultSectionSize()));
}

int MainWindow::getMatrix(float ***a, int *size)
{
    *size = ui->tableWidget->rowCount();

    int tmp = *size;
    QTableWidgetItem tmpItem;
    QString str;

    tmp--;
    *size = *size-1;

    *a = new float *[tmp];
    for (int i = 0; i < tmp; i++)
        (*a)[i] = new float [tmp + 2]; //чтобы объекты не плодить, корни в ту же скидаю

    for (int i = 0; i < tmp; i++)
    {
        for (int j = 0; j < tmp + 1; j++)
        {

            tmpItem = *(ui->tableWidget->item(i, j));
            str = QString(tmpItem.text());

            (*a)[i][j] = str.toFloat();
/*
            QMessageBox msg;
            msg.setText(QString::number((*a)[i][tmp+1]));
            msg.exec();
            */
        }
        (*a)[i][tmp+1] = 0;
    }

    return tmp;
}

void MainWindow::exchange(float **a, int size, int from, int to){
    for(int i = 0; i < size; i++){
        a[from][i] = a[from][i] + a[to][i];
        a[to][i] = a[from][i] - a[to][i];
        a[from][i] = a[from][i] - a[to][i];
    }
}

// определяем ближайшую строку с не 0 диоганалью вниз
int MainWindow::getNoEmpty(float **a, int size, int begin){
    for(int i = begin + 1; i < size; i++){
        if(a[i][i] != 0){
            return i;
        }
    }

    return -1;
}

void MainWindow::printMatrix(float **matr, int size)
{
    QString str;
    ////////////////////////////////////////////////
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            str += QString("%1  ").arg(matr[i][j]);

        str += QString("\t%1\n").arg(matr[i][size]);
        //str += QString("%1\n").arg(matr[i][size+1]);
    }
    ui->textEdit->setPlainText(str);
    ////////////////////////////////////////////////
}

int MainWindow::check(float **matr, int size)
{

    bool flag, CBflag = false, INflag = false;

    for (int i = 0; i < size; i++)
    {
        if (matr[i][i] == 0)
            CBflag = true;

        flag = true;
        for (int j = 0; j < size; j++)
        {
            if (matr[i][j] != 0)
            {
                flag = false;
                break;
            }
        }
        if (flag && matr[i][size] != 0)
        {
            return 1;
        }

        if (flag && matr[i][size] == 0)
        {
            INflag = true;
        }

    }

    if (INflag)
    {
        return 2;
    }
    if (CBflag)
    {
        return 3;
    }

    return 0;

}

void MainWindow::computeGauss()
{
    float **matr;
    int size;
    QString str;

    getMatrix(&matr, &size);

    ////////////////////////////////////////////////
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            str += QString("%1  ").arg(matr[i][j]);

        str += QString("\t%1\n").arg(matr[i][size]);
        //str += QString("%1\n").arg(matr[i][size+1]);
    }
    str += QString("%1\n").arg(matr[1][1]);
    ui->textEdit->setPlainText(str);
    ////////////////////////////////////////////////



    //printMatrix(matr, size);

    //str.clear();
    //return; 

/*
    bool flag, CBflag = false, INflag = false;

    for (int i = 0; i < size; i++)
    {
        if (matr[i][i] == 0)
            CBflag = true;

        flag = true;
        for (int j = 0; j < size; j++)
        {
            if (matr[i][j] != 0)
            {
                flag = false;
                break;
            }
        }
        if (flag && matr[i][size] != 0)
        {
            str += QString("No solution");
            goto EXIT;
        }

        if (flag && matr[i][size] == 0)
        {
            INflag = true;
        }

    }
    */
/*
    if (INflag)
    {
        str += QString("Infinite number of solutions\n");
        goto EXIT;
    }

    if (CBflag)
    {
        str += QString("Cannot be solved by the Gauss method");
        goto EXIT;
    }

*/

    /*прямой ход*/
    float tmp;
    for (int i = 0; i < size; i++)
    {
/*
        if (matr[i][i] == 0)
        {
            if (matr[i][size] == 0)
                str += QString("Infinite number of solutions\n");
            else
                //str += QString("Cannot be solved by the Gauss method");

            goto EXIT;
        }

*/
        switch (check(matr, size))
        {
        case 1:
            str += QString("No solution");
            goto EXIT;
            break;
        case 2:
            str += QString("Infinite number of solutions\n");
            goto EXIT;
            break;
        case 3:
            str += QString("Cannot be solved by the Gauss method");
            goto EXIT;
            break;
        default:
            break;
        }


        tmp = matr[i][i];
        for (int j = size;j >= i;j--)
            matr[i][j] /= tmp;

        for (int j = i+1; j < size;j++)
        {
            tmp = matr[j][i];
            for (int k = size; k >= i;k--)
                matr[j][k] -= tmp * matr[i][k];
        }
    }
    /*обратный ход*/
    matr[size-1][size+1] = matr[size-1][size];
    for (int i = size-2; i >= 0; i--)
    {
        matr[i][size+1] = matr[i][size];
        for (int j = i+1;j < size;j++) matr[i][size+1]-= matr[i][j] * matr[j][size+1];
    }

        // вывод решений
    for(int i = 0; i < size; i++) {
        str += QString("x[%1] = %2\n").arg(i).arg(matr[i][size + 1]);
    }

EXIT:
    ui->textEdit->setPlainText(str);

    delete[] matr;
}


float* MainWindow::holeckii(float **a, int n)
{
            int i, j, p;
            //int n =
            float **b, **c;
            b = new float *[n];
            c = new float *[n];
            for (i = 0; i < n; i++)
            {
                b[i] = new float[n];
                c[i] = new float[n];
            }

            for (i = 0; i < n; i++) {
                b[i][0] = a[i][0];
                c[0][i] = a[0][i] / b[0][0];
                if (i != 0) {
                    c[i][i] = 1;
                }
            }

            float sum;

            for (i = 1; i < n; i++) {
                for (j = 1; j < n; j++) {
                    if (j > i) {
                        sum = 0;
                        for (p = 0; p <= i - 1; p++) {
                            sum += (b[i][p] * c[p][j]);
                        }
                        c[i][j] = ((a[i][j] - sum) / b[i][i]);
                    }
                    if (i >= j) {
                        sum = 0;
                        for (p = 0; p <= j - 1; p++) {
                            sum += (b[i][p] * c[p][j]);
                        }
                        b[i][j] = a[i][j] - sum;
                    }
                }
            }

            float *y = new float[n];
            float *x = new float[n];
            y[0] = a[0][n] / b[0][0];

            for (i = 1; i < n; i++) {
                sum = 0;
                for (p = 0; p <= i - 1; p++) {
                    sum += (b[i][p] * y[p]);
                }
                y[i] = (a[i][n] - sum) / b[i][i];
            }
            x[n - 1] = y[n - 1];
            for (i = n - 2; i >= 0; i--) {
                sum = 0;
                for (j = i + 1; j < n; j++) {
                    sum += c[i][j] * x[j];
                }
                x[i] = y[i] - sum;
            }

            return x;
}


void MainWindow::computeHoleckii()
{
    float **matr, *x;
    int size;
    QString str;
    bool flag = false;

    getMatrix(&matr, &size);

    ////////////////////////////////////////////////
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            str += QString("%1  ").arg(matr[i][j]);

        str += QString("\t%1\n").arg(matr[i][size]);
        //str += QString("%1\n").arg(matr[i][size+1]);
    }
    ui->textEdit->setPlainText(str);
    ////////////////////////////////////////////////

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matr[i][j] != matr[j][i])
                flag = true;
        }
        if (flag)
        {
            str += QString("Cannot be solved by the Holeckii method");
            ui->textEdit->setPlainText(str);
            delete[] matr;
            return;
        }

    }
    x = holeckii(matr, size);
    for(int i = 0; i < size; i++) {
        str += QString("x[%1] = %2\n").arg(i).arg(x[i]);
    }
    ui->textEdit->setPlainText(str);
    delete[] matr;
    return;

}
