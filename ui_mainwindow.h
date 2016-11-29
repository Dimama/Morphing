/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHELP;
    QAction *actionFILE;
    QWidget *centralWidget;
    QPushButton *btn_morph;
    QGraphicsView *Canvas;
    QPushButton *btn_render;
    QGroupBox *groupBox;
    QPushButton *btn_load;
    QGroupBox *groupBox_2;
    QRadioButton *rb_obj1;
    QRadioButton *rb_obj2;
    QLabel *lbl_obj1;
    QLabel *lbl_obj2;
    QGroupBox *groupBox_3;
    QRadioButton *rb_12;
    QRadioButton *rb_21;
    QGroupBox *groupBox_4;
    QSpinBox *spb_x;
    QSpinBox *spb_y;
    QSpinBox *spb_z;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QProgressBar *progressBar;
    QLabel *label_4;
    QSpinBox *spb_speed;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(700, 700);
        actionHELP = new QAction(MainWindow);
        actionHELP->setObjectName(QStringLiteral("actionHELP"));
        actionHELP->setCheckable(false);
        actionHELP->setChecked(false);
        actionFILE = new QAction(MainWindow);
        actionFILE->setObjectName(QStringLiteral("actionFILE"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btn_morph = new QPushButton(centralWidget);
        btn_morph->setObjectName(QStringLiteral("btn_morph"));
        btn_morph->setGeometry(QRect(27, 570, 81, 41));
        Canvas = new QGraphicsView(centralWidget);
        Canvas->setObjectName(QStringLiteral("Canvas"));
        Canvas->setGeometry(QRect(10, 20, 640, 480));
        btn_render = new QPushButton(centralWidget);
        btn_render->setObjectName(QStringLiteral("btn_render"));
        btn_render->setGeometry(QRect(27, 520, 81, 41));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(117, 520, 281, 131));
        btn_load = new QPushButton(groupBox);
        btn_load->setObjectName(QStringLiteral("btn_load"));
        btn_load->setGeometry(QRect(10, 20, 121, 23));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 50, 121, 71));
        rb_obj1 = new QRadioButton(groupBox_2);
        rb_obj1->setObjectName(QStringLiteral("rb_obj1"));
        rb_obj1->setGeometry(QRect(10, 20, 82, 17));
        rb_obj2 = new QRadioButton(groupBox_2);
        rb_obj2->setObjectName(QStringLiteral("rb_obj2"));
        rb_obj2->setGeometry(QRect(10, 40, 82, 17));
        lbl_obj1 = new QLabel(groupBox);
        lbl_obj1->setObjectName(QStringLiteral("lbl_obj1"));
        lbl_obj1->setGeometry(QRect(150, 30, 121, 16));
        lbl_obj2 = new QLabel(groupBox);
        lbl_obj2->setObjectName(QStringLiteral("lbl_obj2"));
        lbl_obj2->setGeometry(QRect(150, 80, 121, 16));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setEnabled(false);
        groupBox_3->setGeometry(QRect(407, 530, 111, 61));
        rb_12 = new QRadioButton(groupBox_3);
        rb_12->setObjectName(QStringLiteral("rb_12"));
        rb_12->setGeometry(QRect(10, 20, 82, 17));
        rb_21 = new QRadioButton(groupBox_3);
        rb_21->setObjectName(QStringLiteral("rb_21"));
        rb_21->setGeometry(QRect(10, 40, 82, 17));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(547, 520, 81, 101));
        spb_x = new QSpinBox(groupBox_4);
        spb_x->setObjectName(QStringLiteral("spb_x"));
        spb_x->setGeometry(QRect(28, 19, 42, 22));
        spb_x->setMinimum(-5);
        spb_x->setMaximum(5);
        spb_x->setValue(1);
        spb_y = new QSpinBox(groupBox_4);
        spb_y->setObjectName(QStringLiteral("spb_y"));
        spb_y->setGeometry(QRect(29, 45, 42, 22));
        spb_y->setMinimum(-5);
        spb_y->setMaximum(5);
        spb_y->setValue(1);
        spb_z = new QSpinBox(groupBox_4);
        spb_z->setObjectName(QStringLiteral("spb_z"));
        spb_z->setGeometry(QRect(29, 71, 42, 22));
        spb_z->setMinimum(-5);
        spb_z->setMaximum(5);
        spb_z->setValue(1);
        label = new QLabel(groupBox_4);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 22, 47, 13));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 49, 47, 13));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 76, 47, 13));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(407, 600, 118, 21));
        progressBar->setValue(0);
        progressBar->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(407, 630, 111, 16));
        spb_speed = new QSpinBox(centralWidget);
        spb_speed->setObjectName(QStringLiteral("spb_speed"));
        spb_speed->setGeometry(QRect(517, 630, 42, 22));
        spb_speed->setMinimum(1);
        spb_speed->setMaximum(20);
        spb_speed->setValue(20);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        QFont font;
        font.setKerning(true);
        toolBar->setFont(font);
        toolBar->setCursor(QCursor(Qt::UpArrowCursor));
        toolBar->setMouseTracking(false);
        toolBar->setFocusPolicy(Qt::ClickFocus);
        toolBar->setContextMenuPolicy(Qt::ActionsContextMenu);
        toolBar->setAcceptDrops(true);
        toolBar->setOrientation(Qt::Horizontal);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addSeparator();
        toolBar->addAction(actionHELP);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Morphing", 0));
        actionHELP->setText(QApplication::translate("MainWindow", "\320\241\320\237\320\240\320\220\320\222\320\232\320\220", 0));
#ifndef QT_NO_TOOLTIP
        actionHELP->setToolTip(QApplication::translate("MainWindow", "\320\241\320\237\320\240\320\220\320\222\320\232\320\220", 0));
#endif // QT_NO_TOOLTIP
        actionHELP->setShortcut(QApplication::translate("MainWindow", "H", 0));
        actionFILE->setText(QApplication::translate("MainWindow", "\320\227\320\220\320\223\320\240\320\243\320\227\320\232\320\220 \320\234\320\236\320\224\320\225\320\233\320\230", 0));
#ifndef QT_NO_TOOLTIP
        actionFILE->setToolTip(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\321\214", 0));
#endif // QT_NO_TOOLTIP
        actionFILE->setShortcut(QApplication::translate("MainWindow", "F", 0));
        btn_morph->setText(QApplication::translate("MainWindow", "MORPH", 0));
        btn_render->setText(QApplication::translate("MainWindow", "\320\236\321\202\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\272\321\202\321\213", 0));
        btn_load->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", 0));
        rb_obj1->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\272\321\202 1", 0));
        rb_obj2->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\272\321\202 2", 0));
        lbl_obj1->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\272\321\202 1: ", 0));
        lbl_obj2->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\272\321\202 2: ", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\321\200\321\217\320\264\320\276\320\272 \320\274\320\276\321\200\321\204\320\270\320\275\320\263\320\260", 0));
        rb_12->setText(QApplication::translate("MainWindow", " 1 --> 2", 0));
        rb_21->setText(QApplication::translate("MainWindow", " 2 --> 1", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265 ", 0));
        label->setText(QApplication::translate("MainWindow", "X:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Y:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Z:", 0));
        progressBar->setFormat(QApplication::translate("MainWindow", "%p%", 0));
        label_4->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\274\320\276\321\200\321\204\320\270\320\275\320\263\320\260: ", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
