#include "fincomp.h"
#include <QtWidgets/QApplication>
#include <stdio.h>
#include "curl.h"
#include "date.h"
#include "equity.h"
#include <map>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[])
{
	/*QApplication a(argc, argv);
	fincomp w;
	w.show(); */

	string add = "C:\\Users\\Mengzhou Tang\\Documents\Visual Studio 2015\\Projects\\fincomp\\sur.csv";
	vector<Stock> total = AllStock(add);


	//return a.exec();
	return 0;
}
