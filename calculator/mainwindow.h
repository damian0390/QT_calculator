#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_PB7_clicked();

    void on_PB8_clicked();

    void on_PB9_clicked();

    void on_PB4_clicked();

    void on_PB5_clicked();

    void on_PB6_clicked();

    void on_PB1_clicked();

    void on_PB2_clicked();

    void on_PB3_clicked();

    void on_PB7_12_clicked();

    void on_PBpoint_clicked();

    void on_PBplus_clicked();

    void on_PBminus_clicked();

    void on_PBmultiply_clicked();

    void on_PBdivide_clicked();

    void on_PBequal_clicked();

    void on_PBplusminus_clicked();

    void on_PBclear_clicked();

    void on_PBsqrt_clicked();

    void on_PBbackspace_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
