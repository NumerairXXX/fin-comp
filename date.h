#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <map>
using namespace std;

class Date {
public:
	bool operator>(const Date obj) const;
	bool operator<(const Date obj) const;
	bool operator==(const Date obj) const;
	void operator=(const Date obj);

	//friend map<Date, double>& price_getter(Stock stk);

	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
	void SetYear(int y);
	void SetMonth(int m);
	void SetDay(int d);
private:
	int year;
	int month;
	int day;
};

#endif 

