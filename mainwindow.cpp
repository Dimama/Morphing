#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QDebug>

#define N INT_MAX
#define TIME 22


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    drawer = new Drawer(ui->Canvas->width(), ui->Canvas->height());
    ui->Canvas->setScene(drawer->getScene());
    timer = new QTimer();
    msg = new Message();


    try
    {
        mesh1 = Mesh::LoadFromJSON("cube.babylon");
        mesh2 = Mesh::LoadFromJSON("other.babylon");
    }
    catch(B_Error& err)
    {
        msg->showErrorMessage(err.info());
    }

    mesh = mesh1;
    cam.setPosition(QVector3D(0,0,10));
    cam.setTarget(QVector3D(0,0,0));

    ui->lbl_obj1->setText("Объект 1: " + mesh1.getName());
    ui->lbl_obj2->setText("Объект 2: " + mesh2.getName());

    ui->rb_12->setChecked(1);
    ui->rb_obj1->setChecked(1);

    render = false;
    morph = false;

    steps = 100;
    step = N;

    ui->progressBar->setMaximum(steps);   //
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(timer_overflow()));

    ui->btn_morph->setEnabled(0);

}

MainWindow::~MainWindow()
{
    delete timer;
    delete msg;
    delete ui;
    delete drawer;
}

void MainWindow::on_actionHELP_triggered()
{

    QMessageBox::information(this,"Справка","Справка");
}

void MainWindow::on_btn_morph_clicked()
{
    if(mesh1.isEqual(mesh2) == 1)
    {
        msg->showMessage("Объекты одинаковые!");
        return;
    }
    if(mesh1.isEqual(mesh2) == 2)
    {
        msg->showMessage("Разное количество полигонов у объектов!");
        return;
    }

    faces.clear();
    if(mesh.isEqual(mesh1) == 1)
    {
        mesh.setName(mesh2.getName());
        faces = mesh1.CalculateMorphingFaces(mesh2);
    }
    else
    {
        mesh.setName(mesh1.getName());
        faces = mesh2.CalculateMorphingFaces(mesh1);
    }

    if(!(timer->isActive()))
    {
        timer->start(TIME);
    }

    step = 0;
    speed = ui->spb_speed->value();   // НЕ ТРОГАТЬ!

    /* заблокировать кнопки */
    ui->btn_morph->setEnabled(0);
    ui->btn_load->setEnabled(0);

    morph = true;

}

/* Загрузка модели*/
void MainWindow::on_btn_load_clicked()
{

    const char *fileName = msg->getFileName();
    Mesh mesh_tmp;
    if(!fileName)
    {
        msg->showErrorMessage("Модель не загружена!");
        return;
    }

    try
    {
        mesh_tmp = Mesh::LoadFromJSON(fileName);
    }

    catch(B_Error& err)
    {
        msg->showErrorMessage(err.info());
        return;
    }

    if(ui->rb_obj1->isChecked())
    {
        mesh1 = mesh_tmp;
        mesh = mesh1;
        ui->lbl_obj1->setText("Объект 1: " + mesh1.getName());

    }
    else
    {
        mesh2 = mesh_tmp;
        mesh = mesh2;
        ui->lbl_obj2->setText("Объект 2: " + mesh2.getName());
    }

}


void MainWindow::on_btn_render_clicked()
{

    speed = ui->spb_speed->value();
    if(!(timer->isActive()))
    {
        ui->btn_render->setText("Пауза");
        timer->start(TIME);
        if(step == N)
        {
            ui->btn_morph->setEnabled(1);
        }
    }
    else
    {
        ui->btn_render->setText("Отрисовать");
        timer->stop();
    }
    render = true;
}

/* Обрабатываем каждую секунду таймера*/
void MainWindow::timer_overflow()
{

    t.start();
    mesh.setRotation(ui->spb_x->value(), ui->spb_y->value(), ui->spb_z->value());
    if(steps - step < speed)
    {
        speed = steps-step;
    }
    if(step < steps)
    {
        step += speed;
        ui->progressBar->setValue(step);
        mesh.Morph(faces,speed);
    }
    if(step == steps)
    {
        ui->progressBar->setValue(0);
        ui->btn_load->setEnabled(1);
        ui->btn_morph->setEnabled(1);

        step = N;
        morph = false;
    }

    render = (morph || ui->spb_x->value() || ui->spb_y->value() || ui->spb_z->value());
    if(render)
    {
        drawer->Render(mesh,cam,qRgb(0,0,255),false);

    }

    ui->statusBar->showMessage("Render time: " + QString::number(t.elapsed()));
}


void MainWindow::on_spb_speed_valueChanged(int arg1)
{
    ui->spb_speed->setValue(arg1);
    speed = ui->spb_speed->value();
}
