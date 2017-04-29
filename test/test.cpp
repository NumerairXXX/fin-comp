#include "test.h"
#include <iostream>
#include <string>
#include <vector>
#include <QtWidgets>


test::test(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	/*set up all lineEdit Widgets to use ENTER key*/
	connect(ui.stockEdit, SIGNAL(returnPressed()), ui.searchButton, SIGNAL(clicked()));
	connect(ui.thresholdEdit, SIGNAL(returnPressed()), ui.okButton, SIGNAL(clicked()));
	connect(ui.BootstrapingEdit, SIGNAL(returnPressed()), ui.okButton, SIGNAL(clicked()));
	//connect ok button with qprogressdialog
	connect(ui.okButton, SIGNAL(clicked()), this, SLOT(start_process()));
	
	//direct show qprogressdialog

	/*int num = 100000;
	QProgressDialog process("Downloading", "Cancel", 0, num, this);
	process.setWindowModality(Qt::WindowModal);
	int i = 0;
	process.setValue(i);
	QApplication::processEvents();
	i = 30000;
	process.setValue(i);
	QApplication::processEvents();
	
	i = 50000;
	process.setValue(i);
	QApplication::processEvents();

	
	process.setValue(num);
	QApplication::processEvents();
*/


	/*set up stocksTable and groupTable*/
	int col_num = 4;//width of stocksTable
	int width[4] = { 100,80,80,150 };
	for (int i = 0; i < col_num; i++) {
		ui.stocksTable->setColumnWidth(i, width[i]);
	}
	ui.stocksTable->setRowCount(91);
	col_num = 2;//width of groupTable
	for (int i = 0; i < col_num; i++) {
		ui.groupTable->setColumnWidth(i, width[i]);
	}
	//Use default threshold and bootstraping_number to calculate
	on_okButton_clicked();
}


/*slot function for okButton click signals*/
void test::on_okButton_clicked(){
	//get inputs from two QlineEdit widgets
	double threshold = ui.thresholdEdit->text().toDouble();
	int bootstraping_time = ui.BootstrapingEdit->text().toInt();
	//std::cout << threshold << " " << bootstraping_time << std::endl;
	
	
	//check if inputs are valid
	if (threshold < 5 || threshold >10) {
		QMessageBox::critical(this, tr("Threshold out of range!"), tr("Threshold should be between 5% to 10%"));
		ui.thresholdEdit->setText(tr("10"));
		return;
	}
	if (bootstraping_time < 1) {
		ui.BootstrapingEdit->setText(tr("1"));
		QMessageBox::critical(this, tr("Bootstraping times out of range!"), tr("It should be at least 1"));
		return;
	}

	//after checking inputs, invoke *** function to do all calculataions
	//and also update values of threshold an bootstraping_time in Event class


	//default set groupTable to empty
	ui.groupComboBox->setCurrentIndex(ui.groupComboBox->findText(tr("")));
}



/*slot function for excelButton click signals*/
void test::on_excelButton_clicked(){
	//invoke *** functions to put data into excel 
	//and also draws graphs
	QMessageBox::information(this, tr("Use excel"), tr("Use excel"));
}



/*slot function for searchButton click signals*/
void test::on_searchButton_clicked(){
	//set stockGroupLabel to show the stock's group
	QString ticker = ui.stockEdit->text();
	if (ticker.isEmpty()) {//no input
		ui.stocksTable->clearContents();
		ui.stockInformationList->clear();
	}
	else {
		//Invoke *** function to get the stock object according to its ticker


		//add data into stocksTable
		ui.stocksTable->clearContents();
		ui.stocksTable->setSortingEnabled(false);
		for (int row = 0; row < 100; row++) {
			for (int colume = 0; colume < 3; colume++) {
				QTableWidgetItem *item = new QTableWidgetItem(tr("2015-01-11"));
				item->setFlags(item->flags() ^ Qt::ItemIsEditable);
				ui.stocksTable->setItem(row, colume, item);
				//notice: The table takes ownership of the item.
			}
		}
		//add data into stockinformationList
		QString group("Group:Beat");
		ui.stockInformationList->clear();
		ui.stockInformationList->addItem(new QListWidgetItem(group, ui.stockInformationList));
			//notice: For the stock object we want to show, we need a *** function to generate a QString for all static information here.
		ui.stockInformationList->addItem(new QListWidgetItem(tr("Static data:\n..."), ui.stockInformationList));
	}
	ui.stocksTable->show();
	
	//set default group to this stock's group
	//*** need to change!!!
	ui.groupComboBox->setCurrentIndex(ui.groupComboBox->findText(tr("")));
}



/*slot function for groupComboBox currentText Changed signals*/
/*The signal function is: void currentTextChanged(const QString &text)*/
void test::on_groupComboBox_currentTextChanged(const QString & text){
	//call *** function to get a vector<Group>
	

	//clear contents first
	ui.groupTable->clearContents();
	//then add new items, for example
	//*** need to change!!!
	if (text == tr("Beat")) {
		//set row count at here because we don't know how many rows data we have until here
		ui.groupTable->setRowCount(30);
		QTableWidgetItem *item = new QTableWidgetItem(tr("Beat"));
		item->setFlags(item->flags() ^ Qt::ItemIsEditable);
		ui.groupTable->setItem(0, 0, item);
	}
	else if (text == tr("Meet")) {
		//set row count at here because we don't know how many rows data we have until here
		ui.groupTable->setRowCount(40);
		QTableWidgetItem *item = new QTableWidgetItem(tr("Meet"));
		item->setFlags(item->flags() ^ Qt::ItemIsEditable);
		ui.groupTable->setItem(0, 0, item);
	}
	else if (text == tr("Miss")) {
		//set row count at here because we don't know how many rows data we have until here
		ui.groupTable->setRowCount(50);
		QTableWidgetItem *item = new QTableWidgetItem(tr("Miss"));
		item->setFlags(item->flags() ^ Qt::ItemIsEditable);
		ui.groupTable->setItem(0, 0, item);
	}

}

/*slot function for cell double click signal*/
void test::on_groupTable_cellDoubleClicked(int row, int column) {
	if (row == 0) {
		QTableWidgetItem *item = new QTableWidgetItem();
		item = ui.groupTable->item(row, column);
		ui.stockEdit->setText(item->text());
		on_searchButton_clicked();
		ui.tabWidget->setCurrentIndex(0);
	}
}

/*slot function for qprogressdialog*/
void test::start_process() {
	std::cout << "test" << std::endl;
	int num = 100000;
	QProgressDialog process("Downloading", "Cancel", 0, num, this);
	process.setWindowModality(Qt::WindowModal);

	for (int i = 0; i < num; i++) {
		process.setValue(i);

		if (process.wasCanceled()) {
			
			break;
		}
		QApplication::processEvents();
	}
	process.setValue(num);
}