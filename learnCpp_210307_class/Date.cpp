#include<iostream>
#include"test.h"
using namespace std;
Time::Time(int hour = 1, int minute = 1, int second = 1)
	:_hour(hour)
	, _minute(minute)
	, _second(second)
{}
void Time::fun(Date& d) {
	cout << d._year << "-" << d._month << "-" << d._day << endl;
}
Date::Date(int year = 1990, int month = 2, int day = 24)
	:_year(year)
	, _month(month)
	, _day(day)
{}
void Date::SetTimeOfDate(int hour, int minute, int second) {
	_time._hour = hour;
	_time._minute = minute;
	_time._second = second;
}
