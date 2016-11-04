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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
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
    QPushButton *pushButton;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(535, 396);
        actionHELP = new QAction(MainWindow);
        actionHELP->setObjectName(QStringLiteral("actionHELP"));
        actionHELP->setCheckable(false);
        actionHELP->setChecked(false);
        actionFILE = new QAction(MainWindow);
        actionFILE->setObjectName(QStringLiteral("actionFILE"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 260, 141, 71));
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
        MainWindow->insertToolBarBreak(toolBar);

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
        pushButton->setText(QApplication::translate("MainWindow", "Morph", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
