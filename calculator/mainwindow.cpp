#include "mainwindow.h"
#include "ui_mainwindow.h"

double first, number, tmp;
bool decimal, minus, eq_press;
int num, dec, action;

void clean();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clean();
    ui -> LCD ->display(number);
}

MainWindow::~MainWindow()
{
    delete ui;
}

double decimal_place(int dec){
    switch (dec){
    case 1 : return 0.1;
    case 2 : return 0.01;
    case 3 : return 0.001;
    case 4 : return 0.0001;
    case 5 : return 0.00001;
    case 6 : return 0.000001;
    case 7 : return 0.0000001;
    }
    return 0.00000001;
}

void clean(){
    number = 0;
    first = 0;
    decimal = false;
    minus = false;
    eq_press = false;
    num = 0;
    dec = 0;
}

void fill_number(int i){
    if (eq_press) clean();
    num++;
    if (decimal) dec++;

    if (num <= 8){
        if (!decimal){
            number *= 10;
            minus? number -= i: number += i;
        } else{
            minus? number -= i * decimal_place(dec): number += i * decimal_place(dec);
        }
    }
}


void MainWindow::on_PB7_clicked()
{
    fill_number(7);
    ui -> LCD ->display(number);

}

void MainWindow::on_PB8_clicked()
{
    fill_number(8);
    ui -> LCD ->display(number);
}


void MainWindow::on_PB9_clicked()
{
    fill_number(9);
    ui -> LCD ->display(number);
}


void MainWindow::on_PB4_clicked()
{
    fill_number(4);
    ui -> LCD ->display(number);
}


void MainWindow::on_PB5_clicked()
{
    fill_number(5);
    ui -> LCD ->display(number);
}


void MainWindow::on_PB6_clicked()
{
    fill_number(6);
    ui -> LCD ->display(number);
}


void MainWindow::on_PB1_clicked()
{
    fill_number(1);
    ui -> LCD ->display(number);
}


void MainWindow::on_PB2_clicked()
{
    fill_number(2);
    ui -> LCD ->display(number);
}


void MainWindow::on_PB3_clicked()
{
    fill_number(3);
    ui -> LCD ->display(number);
}


void MainWindow::on_PB7_12_clicked()
{
    if (eq_press) clean();
    if (number != 0) num++;
    if (decimal && number != 0) dec++;

    if (num <= 8){
        if (!decimal){
            number *= 10;
            minus? number -= 0: number += 0;
        } else{
            minus? number -= 0 * decimal_place(dec): number += 0 * decimal_place(dec);
        }
        ui -> LCD ->display(number);
    }
}


void MainWindow::on_PBpoint_clicked()
{
    decimal = true;
    num++;
    ui -> LCD ->display(number);
}


void MainWindow::on_PBplus_clicked()
{
    action = 1;
    eq_press = false;
    decimal = false;
    minus = false;
    first = number;
    number = 0;
    ui -> LCD ->display(number);
}


void MainWindow::on_PBminus_clicked()
{
    action = 2;
    eq_press = false;
    decimal = false;
    minus = false;
    first = number;
    number = 0;
    ui -> LCD ->display(number);
}


void MainWindow::on_PBmultiply_clicked()
{
    action = 3;
    eq_press = false;
    decimal = false;
    minus = false;
    first = number;
    number = 0;
    ui -> LCD ->display(number);
}


void MainWindow::on_PBdivide_clicked()
{
    action = 4;
    eq_press = false;
    decimal = false;
    minus = false;
    first = number;
    number = 0;
    ui -> LCD ->display(number);
}


void MainWindow::on_PBequal_clicked()
{
    if (action == 1){
        if (!eq_press){
        tmp = first;
        first = number;
        number = tmp;
        }
        number = first + number;
    } else if (action == 2){
        if (!eq_press) tmp = number;
        number = first - tmp;
        first = number;
    } else if (action == 3){
        if (!eq_press){
        tmp = first;
        first = number;
        number = tmp;
        }
        number = first * number;
    } else if (action == 4){
        if (!eq_press) tmp = number;
        number = first / tmp;
        first = number;
    }
    eq_press = true;
    ui -> LCD ->display(number);
}


void MainWindow::on_PBplusminus_clicked()
{
    if (eq_press) clean();
    number = -number;
    minus = !minus;
    ui -> LCD ->display(number);
}


void MainWindow::on_PBclear_clicked()
{
    clean();
    ui -> LCD ->display(number);
}


void MainWindow::on_PBsqrt_clicked()
{
    number = sqrt(number);
    ui -> LCD ->display(number);
}


void MainWindow::on_PBbackspace_clicked()
{
    if (eq_press) {clean(); return;}

    if (!decimal && number != 0){
        number -= ((int)number % 10);
        number /= 10;
        num--;
    } else if (dec == 0){
        num--;
        decimal = false;
    } else{
        num--;
        number -= (((int)(number/decimal_place(dec))) % 10) * decimal_place(dec);
        dec--;
    }
    ui -> LCD ->display(number);
}
