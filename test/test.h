#pragma once

#include <QtWidgets/QWidget>
#include "ui_test.h"

class test : public QWidget
{
	Q_OBJECT

public:
	test(QWidget *parent = Q_NULLPTR);

private:
	Ui::testClass ui;

private slots:
	void on_okButton_clicked(); //slot function for okButton click signal
	
	void on_excelButton_clicked(); //slot function for excelButton click signal
	
	void on_searchButton_clicked();//slot function for searchButton click signal
								   
	/*slot function for groupComboBox currentText Changed signals*/
	/*The signal function is: void currentTextChanged(const QString &text)*/
	void on_groupComboBox_currentTextChanged(const QString &text);

	/*slot function for double click cell in group table*/
	void on_groupTable_cellDoubleClicked(int row, int column);
	
	/*slot function for qprogressdialog*/
	void start_process();
};
