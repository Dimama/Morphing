#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTimer>
#include <mesh.h>
#include "drawer.h"
#include "camera.h"
#include <message.h>
#include <QTime>
#include <QMessageBox>
#include <QColorDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionHELP_triggered();
    void on_btn_morph_clicked();
    void on_btn_load_clicked();
    void on_btn_render_clicked();
    void timer_overflow();
    void on_spb_speed_valueChanged(int arg1);
    void on_actionColor_triggered();
    void on_rb_flat_clicked();
    void on_rb_guro_clicked();


    void on_rb_non_clicked();

private:
    Ui::MainWindow *ui;
    Message* msg;
    QTimer* timer;
    QTime t;
    QColor color;

    Mesh mesh1,mesh2,mesh;
    vector<Face> faces;
    Camera cam;
    Drawer* drawer;

    bool render;
    bool morph;

    int step;
    int steps;
    int speed;
};

#endif // MAINWINDOW_H
