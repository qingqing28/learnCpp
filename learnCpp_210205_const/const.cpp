#include<iostream>
using namespace std;

class A {
	int _a;
	//this: A* const
	void setA(int a) {
		_a = a;
		//getA();
	}
	//const this:const A* const
	int getA() const{
		//setA(3);
		return _a;
	}

	A* operator& (const A& a) {
		return this;
	}

	const A* operator&(const A& a)const {
		return this;
	}
};

void test() {
	A obja;
	A* pa = &obja;
	const A* pb = &obja;
	const A objb;
	const A* pc = &objb;
	//A* pd = &objb;









	//int a = 3;
	//int b = 4;
	////int* pa = &a;
	////pa = &b;

	//const int c = 1;
	//const int d = 2;
	//int* const pc = &a;
	//*pc = 4;

	//const int* pa = &a;
	//const int* const pb = &b;
	//pb = &a;
	//*pb = 4;

}