#include "Date.h"
#include <iostream>
#include <map>
#include<vector>


//we call it greater than the other when it's further. E.g:  2017/5/13 > 2016/8/15 returns true
bool Date::operator>(const Date& obj) const {
	if (year > obj.year) {
		return true;
	} else if (year == obj.year) {
		if (month > obj.month) {
			return true;
		} else if (month == obj.month) {
			return (day > obj.day);
		}
	}
	return false;
}

bool Date::operator<(const Date& obj) const {
	if (year < obj.year) {
		return true;
	} else if (year == obj.year) {
		if (month < obj.month) {
			return true;
		} else if (month == obj.month) {
			return (day < obj.day);
		}
	}
	return false;
}

//returns true when it's the same day
bool Date::operator==(const Date& obj) const {
	if (year == obj.year && month == obj.month && day == obj.day) {
		return true;
	}
	return false;
}

//assign the coming date object to our current object
Date& Date::operator=(const Date& obj) {
	year = obj.year;
	month = obj.month;
	day = obj.day;
	return *this;
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