/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_testClass
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *okButton;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *thresholdEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *BootstrapingEdit;
    QTabWidget *tabWidget;
    QWidget *stocksTab;
    QGridLayout *gridLayout;
    QListWidget *stockInformationList;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *stockEdit;
    QPushButton *searchButton;
    QTableWidget *stocksTable;
    QWidget *groupsTab;
    QPushButton *excelButton;
    QComboBox *groupComboBox;
    QLabel *label_5;
    QTableWidget *groupTable;
    QCustomPlot *widget;

    void setupUi(QWidget *testClass)
    {
        if (testClass->objectName().isEmpty())
            testClass->setObjectName(QStringLiteral("testClass"));
        testClass->resize(955, 679);
        gridLayout_2 = new QGridLayout(testClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        okButton = new QPushButton(testClass);
        okButton->setObjectName(QStringLiteral("okButton"));

        gridLayout_2->addWidget(okButton, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(testClass);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        thresholdEdit = new QLineEdit(testClass);
        thresholdEdit->setObjectName(QStringLiteral("thresholdEdit"));

        horizontalLayout->addWidget(thresholdEdit);

        label_2 = new QLabel(testClass);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(testClass);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        BootstrapingEdit = new QLineEdit(testClass);
        BootstrapingEdit->setObjectName(QStringLiteral("BootstrapingEdit"));

        horizontalLayout->addWidget(BootstrapingEdit);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        tabWidget = new QTabWidget(testClass);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        stocksTab = new QWidget();
        stocksTab->setObjectName(QStringLiteral("stocksTab"));
        gridLayout = new QGridLayout(stocksTab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stockInformationList = new QListWidget(stocksTab);
        stockInformationList->setObjectName(QStringLiteral("stockInformationList"));

        gridLayout->addWidget(stockInformationList, 1, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(stocksTab);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        stockEdit = new QLineEdit(stocksTab);
        stockEdit->setObjectName(QStringLiteral("stockEdit"));

        horizontalLayout_2->addWidget(stockEdit);

        searchButton = new QPushButton(stocksTab);
        searchButton->setObjectName(QStringLiteral("searchButton"));

        horizontalLayout_2->addWidget(searchButton);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        stocksTable = new QTableWidget(stocksTab);
        if (stocksTable->columnCount() < 4)
            stocksTable->setColumnCount(4);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        stocksTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        stocksTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        stocksTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        stocksTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        stocksTable->setObjectName(QStringLiteral("stocksTable"));

        gridLayout->addWidget(stocksTable, 1, 0, 1, 2);

        tabWidget->addTab(stocksTab, QString());
        groupsTab = new QWidget();
        groupsTab->setObjectName(QStringLiteral("groupsTab"));
        excelButton = new QPushButton(groupsTab);
        excelButton->setObjectName(QStringLiteral("excelButton"));
        excelButton->setGeometry(QRect(820, 490, 91, 91));
        groupComboBox = new QComboBox(groupsTab);
        groupComboBox->setObjectName(QStringLiteral("groupComboBox"));
        groupComboBox->setGeometry(QRect(110, 10, 131, 31));
        label_5 = new QLabel(groupsTab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 10, 91, 31));
        groupTable = new QTableWidget(groupsTab);
        if (groupTable->columnCount() < 2)
            groupTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        groupTable->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        groupTable->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        groupTable->setObjectName(QStringLiteral("groupTable"));
        groupTable->setGeometry(QRect(20, 60, 261, 521));
        widget = new QCustomPlot(groupsTab);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(389, 59, 481, 391));
        tabWidget->addTab(groupsTab, QString());

        gridLayout_2->addWidget(tabWidget, 1, 0, 1, 2);


        retranslateUi(testClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(testClass);
    } // setupUi

    void retranslateUi(QWidget *testClass)
    {
        testClass->setWindowTitle(QApplication::translate("testClass", "Financial Computing Project", Q_NULLPTR));
        okButton->setText(QApplication::translate("testClass", "ok", Q_NULLPTR));
        label->setText(QApplication::translate("testClass", "Threshold:", Q_NULLPTR));
        thresholdEdit->setText(QApplication::translate("testClass", "10", Q_NULLPTR));
        label_2->setText(QApplication::translate("testClass", "% (5%-10%).           ", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        label_3->setWhatsThis(QApplication::translate("testClass", "How many times we choose 40 stocks from each group to calculate AAR and CAAR", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        label_3->setText(QApplication::translate("testClass", "Bootstraping Times:", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        BootstrapingEdit->setWhatsThis(QApplication::translate("testClass", "How many times we choose 40 stocks from each group to calculate AAR and CAAR", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        BootstrapingEdit->setText(QApplication::translate("testClass", "1", Q_NULLPTR));
        label_4->setText(QApplication::translate("testClass", "Ticker:", Q_NULLPTR));
        searchButton->setText(QApplication::translate("testClass", "search", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = stocksTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("testClass", "Date", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = stocksTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("testClass", "Price", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = stocksTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("testClass", "Daily Return", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        ___qtablewidgetitem2->setWhatsThis(QApplication::translate("testClass", "3", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        QTableWidgetItem *___qtablewidgetitem3 = stocksTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("testClass", "Abnormal Daily Return", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(stocksTab), QApplication::translate("testClass", "Stocks", Q_NULLPTR));
        excelButton->setText(QApplication::translate("testClass", "Get Graph \n"
" in Excel", Q_NULLPTR));
        groupComboBox->clear();
        groupComboBox->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("testClass", "Beat", Q_NULLPTR)
         << QApplication::translate("testClass", "Meet", Q_NULLPTR)
         << QApplication::translate("testClass", "Miss", Q_NULLPTR)
        );
        groupComboBox->setCurrentText(QString());
        label_5->setText(QApplication::translate("testClass", "Choose Group:", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = groupTable->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("testClass", "Ticker", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = groupTable->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("testClass", "Surprise", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(groupsTab), QApplication::translate("testClass", "Groups", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class testClass: public Ui_testClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
