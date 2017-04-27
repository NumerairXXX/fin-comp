#include "date.h"
#include <iostream>
#include <map>
#include<vector>


//we call it greater than the other when it's further. E.g:  2017/5/13 > 2016/8/15 returns true
bool Date::operator>(const Date obj) const{
	bool indi = true;
	if ((*this).year > obj.year) indi = true;
	else if ((*this).year == obj.year) {
		if ((*this).month == obj.month) {
			if ((*this).day == obj.day) indi = false;
			else if ((*this).day > obj.day) indi = true;
			else indi = false;
		}
		else if ((*this).month > obj.month) indi = true;
		else indi = false;
	}
	else indi = false;
	return indi;
}

bool Date::operator<(const Date obj) const{
	bool indi = true;
	if ((*this).year < obj.year) indi = true;
	else if ((*this).year == obj.year) {
		if ((*this).month == obj.month) {
			if ((*this).day == obj.day) indi = false;
			else if ((*this).day < obj.day) indi = true;
			else indi = false;
		}
		else if ((*this).month < obj.month) indi = true;
		else indi = false;
	}
	else indi = false;
	return indi;
}

//returns true when it's the same day
bool Date::operator==(const Date obj) const {
	bool indi = true;
	if ((*this).year == obj.year) {
		if ((*this).month == obj.month) {
			if ((*this).day == obj.day) indi = true;
			else indi = false;
		}
	}
	else indi = false;
	return indi;
}

//assign the coming date object to our current object
void Date::operator=(const Date obj) {
	(*this).year = obj.year;
	(*this).month = obj.month;
	(*this).day = obj.day;
}

int Date::GetYear() const {
	return year;
}
int Date::GetMonth() const {
	return month;
}
int Date::GetDay() const {
	return day;
}

void Date::SetYear(int y) {
	year = y;
}
void Date::SetMonth(int m) {
	month = m;
}
void Date::SetDay(int d) {
	day = d;
}
