#include "curl.h"
#include "Date.h"
#include "Equity.h"
#include <iostream>
#include <map>
using namespace std;

Equity::Equity(std::string ticker_, Date s, Date e, std::map<Date, double> price_, std::map<Date, double> ret_) 
	:ticker(ticker_), start_date(s), end_date(e), price(price_), ret(ret_) {
}

Date Equity::GetStartDate() {
	return start_date;
}

Date Equity::GetEndDate() {
	return end_date;
}


Date Stock::GetRepDate() {
	return (*this).rep_date;
}



ETF ETF::Slice(Date s_d, Date e_d) {
	map<Date, double> subprice;
	map<Date, double> subret;
	for (auto i = price.find(s_d); i != ++(price.find(e_d)); i++) {
		subprice[i->first] = i->second;
	}
	for (auto i = ret.find(s_d); i != ++(ret.find(e_d)); i++) {
		subret[i->first] = i->second;
	}
	return ETF(ticker, s_d, e_d, subprice, subret);
}
