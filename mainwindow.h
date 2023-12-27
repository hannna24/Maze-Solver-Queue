#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "mazeSolver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }   //this makes the ui mainwindow includes mainwindow class
QT_END_NAMESPACE


class MainWindow : public QWidget
{
    Q_OBJECT  //convert into c++ code hga zy kda msh mohema yaane

public:
    MainWindow(QWidget *parent = nullptr); //constructor the app is the one who did it not me
    ~MainWindow();   //same

private slots:
    void clear_comboBoxes();

    void extract_userData();

    void on_generateMaze_clicked();

    void on_findPath_clicked();

    void initialize_comboBoxes(const size_t rows, const size_t cols);

private:
    Ui::MainWindow *ui;     //object mn class mainwindow and using this object i'm gonna access all the widgets i'm gonna add
    mazeSolver m_solver;
    bool m_comboBoxesInitialized;
};
#endif // MAINWINDOW_H
