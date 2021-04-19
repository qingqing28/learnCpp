#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;

class Date {
public:
    Date(int date)
    {
        _year = date / 10000;
        date -= _year * 10000;
        _month = date / 100;
        date -= _month * 100;
        _day = date;
    }
    bool operator>(Date& d) {
        if (_year > d._year)
            return true;
        else {
            if (_month > d._month)
                return true;
            else {
                if (_day > d._day)
                    return true;
            }
        }
        return false;
    }
    bool operator==(Date& d) {
        return _year == d._year && _month == d._month && _day == d._day;
    }
    bool operator!=(Date& d) {
        return !(*this == d);
    }
    Date& operator--()
    {
        _day--;
        if (_day <= 0) {
            _month--;
            if (_month <= 0) {
                _year--;
                _month = 12;
            }
            _day = _day + getDay(_year, _month);
        }
        return *this;
    }
    int getDay(int year, int month)
    {
        int days[13] = { 0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 ,30 , 31 };
        int day = days[month];
        if (month == 2) {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            {
                day++;
            }
        }
        return day;
    }
    int operator-(Date& d) {
        int day = 0;
        while (*this != d) {
            --(*this);
            day++;
        }
        return day + 1;
    }
private:
    int _year;
    int _month;
    int _day;
};

int main() {
    int date1;
    int date2;
    while (scanf("%d %d", &date1, &date2) != EOF)
    {
        Date d1(date1);
        Date d2(date2);
        if (d1 > d2)
            cout << d1 - d2 << endl;
        else
            cout << d2 - d1 << endl;
    }
    return 0;
}