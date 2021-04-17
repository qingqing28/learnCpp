#include<iostream>
using namespace std;
class Date {
public:
	void print() {
		cout << "this is print()" << endl;
	}
	void Display() {
		cout << this->_year << "_" << this->_month << "_" << this->_day << endl;
	}
	void SetDate(int year, int month, int day) {
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};

void testThis() {
	//Date d1, d2;
	//d1.SetDate(2021, 2, 3);
	//d2.SetDate(2010, 4, 5);
	//d1.Display();
	//d2.Display();
	Date* d = NULL;
	//print(d);
	d->print();
	d->Display();
}
