#include<iostream>
using namespace std;

class Date {
public:
	//构造函数
	Date(int year = 1 , int month = 1, int day = 1) {
		if (year <= 0 || month <= 0 || month > 12 || day <= 0 || day > getDay(year, month)) {
			_year = 1;
			_month = 1;
			_day = 1;
			cout << "日期有误，设置为默认值" << endl;
		}
		else {
			_year = year;
			_month = month;
			_day = day;
		}
	}

	int getDay(int year, int month) {
		static int days[] = { 0 ,31, 28 ,31 ,30 ,31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
			day++;
		return day;
	}
	//拷贝构造函数
	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//赋值运算符重载
	Date& operator=(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}

	//Date+int
	Date& operator+=(int day) {
		//2021.2.5 + 30 -> 2021.2.35 -28 ->2021.3.7
		if (day < 0)
			return *this -= (-day);
		_day += day;
		while (_day > getDay(_year, _month)) {
			_day -= getDay(_year, _month);
			_month++;
			if (_month == 13) {
				_year++;
				_month = 1;
			}
		}
		return *this;
	}

	Date& operator -=(int day) {
		if (day < 0)
			return *this += (-day);
		//2021.2.5 - 25 ->2021.2.-20 -- 31 ->2021.1.11
		_day -= day;
		while (_day < 0) {
			_month--;
			if (_month <= 0) {
				_year--;
				_month = 12;
			}
			_day += getDay(_year, _month);
		}
		return *this;
	}

	Date operator+(int day) {
		Date copy(*this);
		return copy += day;
	}

	Date operator-(int day) {
		Date copy(*this);
		return copy -= day;
	}

	Date& operator++() {
		return *this += 1;
	}

	Date operator++(int) {
		Date copy(*this);
		*this += 1;
		return copy;
	}

	Date& operator--() {
		return *this -= 1;
	}

	Date operator--(int) {
		Date copy(*this);
		*this -= 1;
		return copy;
	}

	bool operator==(const Date& d) {
		return _year == d._year && _month == d._month && _day == d._day;
	}
	bool operator!=(const Date& d) {
		return !(*this == d);
	}
	bool operator>(const Date& d) {
		if (_year > d._year)
			return true;
		else if (_year == d._year) {
			if (_month > d._month)
				return true;
			else if (_month == d._month) {
				if (_day > d._day)
					return true;
			}
		}
		return false;
	}
	bool operator>= (const Date & d) {
		return (*this == d) || (*this > d);
	}

	bool operator<(const Date& d) {
		return !(*this >= d);
	}
	bool operator<=(const Date& d) {
		return (*this < d) || (*this == d);
	}
	int operator-(const Date& d) {
		Date max = *this;
		Date min = d;
		int flag = 1;
		if (max < min) {
			max = d;
			min = *this;
			flag = -1;
		}
		int day = 0;
		while (min < max) {
			min++;
			day++;
		}
		return day * flag;
	}
private:
	int _year;
	int _month;
	int _day;
};

void test() {
	Date d1(2021, 2, 5);
	Date d2(2021, 2, 4);
	Date d3(2021, 2, 9);
	Date d4(2021, 2, 5);

	bool ret = d1 == d4;
	ret = d1 != d2;
	ret = d1 > d2;
	ret = d1 >= d2;
	ret = d1 < d3;
	ret = d1 <= d3;

	d2 = d1 + 36;
	int day = d1 - d2;
	//d2 = d1++;  //2021.2.5         2021.2.6
	//d2 = ++d1;//2021.2.7    2021.2.7
	//d2 = d1--; //  2021.2.7  2021.2.6
	//d2 = --d1;//2021.2.5  2021.2.5
}

//void test() {
//
//	Date d(2021, 2, 28);
//	Date d1(2013, 5, 24);
//	Date d2(d1);
//	Date d3;
//	d3 = d;
//	d3.operator=(d1);
//	d2 = d3 = d;
//}