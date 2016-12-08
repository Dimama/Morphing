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
#include <QtWidgets/QHBoxLayout>
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
    QAction *actionColor;
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
    QGroupBox *groupBox_4;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spb_x;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spb_y;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *spb_z;
    QProgressBar *progressBar;
    QGroupBox *groupBox_3;
    QRadioButton *rb_non;
    QRadioButton *rb_flat;
    QRadioButton *rb_guro;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpinBox *spb_speed;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(676, 684);
        actionHELP = new QAction(MainWindow);
        actionHELP->setObjectName(QStringLiteral("actionHELP"));
        actionHELP->setCheckable(false);
        actionHELP->setChecked(false);
        actionColor = new QAction(MainWindow);
        actionColor->setObjectName(QStringLiteral("actionColor"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btn_morph = new QPushButton(centralWidget);
        btn_morph->setObjectName(QStringLiteral("btn_morph"));
        btn_morph->setGeometry(QRect(9, 547, 81, 41));
        Canvas = new QGraphicsView(centralWidget);
        Canvas->setObjectName(QStringLiteral("Canvas"));
        Canvas->setGeometry(QRect(10, 9, 640, 480));
        btn_render = new QPushButton(centralWidget);
        btn_render->setObjectName(QStringLiteral("btn_render"));
        btn_render->setGeometry(QRect(10, 500, 81, 41));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(369, 498, 281, 131));
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
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(280, 497, 81, 91));
        layoutWidget = new QWidget(groupBox_4);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 16, 53, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        spb_x = new QSpinBox(layoutWidget);
        spb_x->setObjectName(QStringLiteral("spb_x"));
        spb_x->setMinimum(-5);
        spb_x->setMaximum(5);
        spb_x->setValue(1);

        horizontalLayout->addWidget(spb_x);

        layoutWidget1 = new QWidget(groupBox_4);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 41, 53, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spb_y = new QSpinBox(layoutWidget1);
        spb_y->setObjectName(QStringLiteral("spb_y"));
        spb_y->setMinimum(-5);
        spb_y->setMaximum(5);
        spb_y->setValue(1);

        horizontalLayout_2->addWidget(spb_y);

        layoutWidget2 = new QWidget(groupBox_4);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 66, 53, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        spb_z = new QSpinBox(layoutWidget2);
        spb_z->setObjectName(QStringLiteral("spb_z"));
        spb_z->setMinimum(-5);
        spb_z->setMaximum(5);
        spb_z->setValue(1);

        horizontalLayout_3->addWidget(spb_z);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(220, 610, 118, 21));
        progressBar->setValue(0);
        progressBar->setOrientation(Qt::Horizontal);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(95, 497, 181, 91));
        rb_non = new QRadioButton(groupBox_3);
        rb_non->setObjectName(QStringLiteral("rb_non"));
        rb_non->setGeometry(QRect(10, 20, 121, 17));
        rb_non->setChecked(true);
        rb_flat = new QRadioButton(groupBox_3);
        rb_flat->setObjectName(QStringLiteral("rb_flat"));
        rb_flat->setGeometry(QRect(10, 40, 161, 17));
        rb_guro = new QRadioButton(groupBox_3);
        rb_guro->setObjectName(QStringLiteral("rb_guro"));
        rb_guro->setGeometry(QRect(10, 60, 131, 17));
        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 610, 152, 22));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        spb_speed = new QSpinBox(layoutWidget3);
        spb_speed->setObjectName(QStringLiteral("spb_speed"));
        spb_speed->setMinimum(1);
        spb_speed->setMaximum(40);
        spb_speed->setValue(20);

        horizontalLayout_4->addWidget(spb_speed);

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
        toolBar->addAction(actionColor);

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
        actionColor->setText(QApplication::translate("MainWindow", "\320\246\320\222\320\225\320\242", 0));
#ifndef QT_NO_TOOLTIP
        actionColor->setToolTip(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \321\206\320\262\320\265\321\202\320\260", 0));
#endif // QT_NO_TOOLTIP
        btn_morph->setText(QApplication::translate("MainWindow", "MORPH", 0));
        btn_render->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\266\320\260\321\202\321\214", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\272\321\202\321\213", 0));
        btn_load->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", 0));
        rb_obj1->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\272\321\202 1", 0));
        rb_obj2->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\272\321\202 2", 0));
        lbl_obj1->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\272\321\202 1: ", 0));
        lbl_obj2->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\272\321\202 2: ", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265 ", 0));
        label->setText(QApplication::translate("MainWindow", "X:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Y:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Z:", 0));
        progressBar->setFormat(QApplication::translate("MainWindow", "%p%", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214 \320\276\321\201\320\262\320\265\321\211\320\265\320\275\320\270\321\217", 0));
        rb_non->setText(QApplication::translate("MainWindow", "\320\221\320\265\320\267 \320\276\321\201\320\262\320\265\321\211\320\265\320\275\320\270\321\217", 0));
        rb_flat->setText(QApplication::translate("MainWindow", "\320\237\320\273\320\276\321\201\320\272\320\260\321\217 \320\274\320\276\320\264\320\265\320\273\321\214 \320\276\321\201\320\262\320\265\321\211\320\265\320\275\320\270\321\217", 0));
        rb_guro->setText(QApplication::translate("MainWindow", "\320\236\321\201\320\262\320\265\321\211\320\265\320\275\320\270\320\265 \320\277\320\276 \320\223\321\203\321\200\320\276", 0));
        label_4->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\274\320\276\321\200\321\204\320\270\320\275\320\263\320\260: ", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
