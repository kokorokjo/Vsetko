/********************************************************************************
** Form generated from reading UI file 'textfinder.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTFINDER_H
#define UI_TEXTFINDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TextFinder
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *findButton;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TextFinder)
    {
        if (TextFinder->objectName().isEmpty())
            TextFinder->setObjectName("TextFinder");
        TextFinder->resize(800, 600);
        centralwidget = new QWidget(TextFinder);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        findButton = new QPushButton(centralwidget);
        findButton->setObjectName("findButton");

        horizontalLayout->addWidget(findButton);


        verticalLayout->addLayout(horizontalLayout);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");

        verticalLayout->addWidget(textEdit);

        TextFinder->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TextFinder);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        TextFinder->setMenuBar(menubar);
        statusbar = new QStatusBar(TextFinder);
        statusbar->setObjectName("statusbar");
        TextFinder->setStatusBar(statusbar);

        retranslateUi(TextFinder);

        QMetaObject::connectSlotsByName(TextFinder);
    } // setupUi

    void retranslateUi(QMainWindow *TextFinder)
    {
        TextFinder->setWindowTitle(QCoreApplication::translate("TextFinder", "TextFinder", nullptr));
        label->setText(QCoreApplication::translate("TextFinder", "TextLabel", nullptr));
        lineEdit->setText(QCoreApplication::translate("TextFinder", "Keyword", nullptr));
        findButton->setText(QCoreApplication::translate("TextFinder", "Find", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextFinder: public Ui_TextFinder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTFINDER_H
