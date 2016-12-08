#include "mainwindow.h"
#include <QApplication>

#include <qDebug>
#include <drawer.h>

int main(int argc, char* argv[])
{

//#if defined(_OPENMP)
//    qDebug() << "Compiled by an OpenMP-compliant implementation";
//    qDebug() <<  "The result of omp_get_num_threads: " ;
//#endif

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();





    return 0;
}
