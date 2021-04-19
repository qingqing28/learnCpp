class Date;
class Time {
public:
	friend class Date;
	Time(int hour , int minute , int second );
	void fun(Date& d);
private:
	int _hour;
	int _minute;
	int _second;
};

class Date {
public:
	friend class Time;
	Date(int year, int month, int day);
	void SetTimeOfDate(int hour, int minute, int second);
private:
	int _year;
	int _month;
	int _day;
	Time _time;
};