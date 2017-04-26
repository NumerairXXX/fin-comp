#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <map>
using namespace std;

class Date {
public:
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
	int SetYear(int y);
	int SetMonth(int m);
	int SetDay(int d);
	bool operator>(const Date obj) const;
	bool operator<(const Date obj) const;
	bool operator==(const Date obj) const;
	void operator=(const Date obj);
	Date &date_modifier(const Date obj, int shift);
private:
	int year;
	int month;
	int day;
};

#endif 

