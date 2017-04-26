#include "curl.h"
#include "date.h"
#include "equity.h"
#include <iostream>
#include <map>
using namespace std;

Date Equity::GetStartDate() {
	return start_date;
}

Date Equity::GetEndDate() {
	return end_date;
}

Date ETF::GetStartDate() {

}

Date ETF::GetEndDate() {

}

Date Stock::GetRepDate() {
	return (*this).rep_date;
}

