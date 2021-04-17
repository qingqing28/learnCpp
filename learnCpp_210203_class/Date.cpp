#include<iostream>
using namespace std;

class  A {
public:
	A(int a = 3) {
		_a = a;
		cout << "A(int)" << endl;
	}
	~A() {
		cout << "~A" << endl;
	}
private:
	int _a;
};
class Date {
public:
	/*Date() {
		cout << "Date()" << endl;
	}*/
	/*Date(int year, int month, int day) {
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int int int)" << endl;
	}*/
	Date(int year = 2021, int month = 3, int day = 4) {
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int int int)ȫȱʡ" << endl;
	}
	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(const Date&)" << endl;
	}
	~Date() {
		cout << "~Date()" << endl;
	}
	bool operator==(const Date& d) {
		return _year == d._year && _month == d._month && _day == d._day;
	}
	
public:
	int _year;
	int _month;
	int _day;
};
//bool operator== (const Date & d1, const Date & d2) {
//	return d1._year == d2._year && d1._month == d2._month && d1._day == d2._day;
//}
void testDate() {
	Date d2(2021, 2);
	Date d3(2001, 3);
	cout << operator==(d2,d3) << endl;
	cout << (d2 == d3) << endl;
}