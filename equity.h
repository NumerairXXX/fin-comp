#ifndef EQUITY_H
#define EQUITY_H
#include "curl.h"
#include "date.h"
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

class Equity {
public: 
	virtual Date GetStartDate();
	virtual Date GetEndDate();
private: 
	string ticker;
	Date start_date;
	Date end_date;
	map<Date, double> price;
	map<Date, double> ret;
};

class ETF : public Equity {
public:
	Date GetStartDate();
	Date GetEndDate();
private:
	map<Date, double> price;
	map<Date, double> ret;
};

class Stock :public Equity {
public:
	Date GetRepDate();
	friend void AllStock();
	friend string web_generator(Stock stk);
private:
	Date rep_date;

	double surprise;

	string ticker;
	string security;
	string sector;
	string sub_industry;
	string address;
	int cik;

	map<Date, double> price;
	map<Date, double> ret;
};


#endif

