#pragma once
#include "curl.h"
#include "date.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>


class Equity {
protected:
	std::string ticker;
	Date start_date;
	Date end_date;
	map<Date, double> price;
	map<Date, double> ret;

public:
	Equity() {}
	Equity(std::string ticker_, Date s, Date e, std::map<Date, double> price_, std::map<Date, double> ret_);
	Equity(const Equity& e):ticker(e.ticker), start_date(e.start_date), end_date(e.end_date), price(e.price), ret(e.ret){}
	~Equity() {}
	Date GetStartDate();
	Date GetEndDate();
	

};

class ETF : public Equity {
public:
	ETF() {}
	//constructor with parameter
	ETF(std::string ticker_, Date s, Date e, std::map<Date, double> price_, std::map<Date, double> ret_) 
		:Equity(ticker_, s, e, price_, ret_) {}
	//copy constructor
	ETF(const ETF& etf) {
		Equity::ticker = etf.ticker;
		Equity::start_date = etf.start_date;
		Equity::end_date = etf.end_date;
		Equity::price = etf.price;
		Equity::ret = etf.ret;
	}

	ETF Slice(Date s_d, Date e_d);
};

class Stock :public Equity {
private:
	Date rep_date;
	double surprise;
	string security;
	string sector;
	string sub_industry;
	string address;
	int cik;

public:
	Stock() {}
	Stock(std::string ticker_, Date s, Date e, Date report, map<Date, double> price_, map<Date, double> ret_, std::string security_, std::string sector_, std::string subsector_, std::string address_, int cik_, double surprise_)
		:Equity(ticker_, s, e, price_, ret_), rep_date(report), security(security_), sector(sector_), sub_industry(subsector_), address(address_), cik(cik_), surprise(surprise_){}
	Stock(const Stock& stock): rep_date(stock.rep_date),security(stock.security),sector(stock.sector),sub_industry(stock.sub_industry),address(stock.address),cik(stock.cik),surprise(stock.surprise) {
		Equity::ticker = stock.ticker;
		Equity::start_date = stock.start_date;
		Equity::end_date = stock.end_date;
		Equity::price = stock.price;
		Equity::ret = stock.ret;
	}
	~Stock() {}
	Date GetRepDate();
};
