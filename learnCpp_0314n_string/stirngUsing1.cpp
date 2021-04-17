#include<iostream>
using namespace std;

void testStringUsing1()
{
	//1.member functions
	//(1)构造函数
	string str;                      //""
	string str2("abcdefgh");            //"abcdefgh"
	string str3(str2);               //"abcdefgh"
	string str4(str2, 3, 3);          //"def"
	string str5("1234567", 4);       //"1234"
	string str6(4,'a');                //"aaaa"
	string str7(++str2.begin(), --str2.end());   //"bcdefg"

	//(2)析构函数
	//(3)operator=
	str = str2;
	str = "abc";
	str = 'a';

	//2.element access
	//(1)operator[]
	char ch = str2[4];
	str2[4] = '1';               // str2-"abcd1fgh"
	const string str8 = "abcdefgh"; //str8-"abcdefgh"
	ch = str8[4];
	//str8[4] = '1';

	//(2)at
	ch = str2.at(4);
	str2.at(4) = 'e';           //str2-"abcdefgh"
	ch = str8.at(4);              //str8-"abcdefgh"
	//str8.at(4) = '6';
	
	//(3)back
	ch = str2.back();
	str2.back() = '1';      //str2-"abcdefg1"
	ch = str8.back();  
	//str8.back() = '1';
	str2.back() = ch;         ////str2-"abcdefgh"
	//(4)front

	//3.iterator
	//(1)begin
	//(2)end
	string::iterator it = str2.begin();
	while (it != str2.end()) {
		*it = *it - 'a' + '1';
		cout << *it << " ";
		++it;
	}                             //str2-"12345678" 
	cout << endl;
	for (auto& ch: str2) {
		ch = ch - '1' + 'a';
		cout << ch << " ";
	}
	cout << endl;         //str2-"abcdefgh"
	for (size_t i = 0; i < str2.size(); i++) {
		str2[i] = str2[i] - 'a'+ '1';
		cout << str2[i] << " ";
	}
	cout << endl;                   //str2-"12345678"
	string::const_iterator it2 = str8.begin();
	while (it2 != str8.end()) {
		//*it2 = *it2 - '1' + 'a';
		cout << *it2 << " ";
		it2++;
	}
	cout << endl;
	for (const auto& ch : str8) {
		cout << ch << " ";
	}
	cout << endl;
	for (size_t i = 0; i < str8.size(); i++) {
		cout << str8[i] << " ";
	}
	cout << endl;
	//(3)rbegin
	//(4)rend
	string::reverse_iterator rit = str2.rbegin();
	while (rit != str2.rend()) {
		*rit = *rit - '1' + 'a';
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	string::const_reverse_iterator rit2 = str8.rbegin();
	while (rit2 != str8.rend()) {
		cout << *rit2 << " ";
		++ rit2;
	}
	cout << endl;

	//(5)cbegin
	//(6)cend
	//(7)crbegin
	//(8)crend
	string::const_iterator it3 = str2.cbegin();
	while (it3 != str2.cend()) {
		//*it3 = 'a';
		cout << *it3 << " ";
		it3++;
	}
	cout << endl;
	string::const_reverse_iterator rit3 = str2.crbegin();
	while (rit3 != str2.crend()) {
		cout << *rit3 << " ";
		++rit3;
	}
	cout << endl;

	//4.capacity
	//(1)size
	size_t sz = str2.size();
	//(2)resize
	str2.resize(9);     //str2 -"abcdefgh\0"
	sz = str2.size();
	str2.resize(3);   //str2-"abc"
	sz = str2.size();
	str2.resize(8, 'a');       //str2-"abca aaaa"
	sz = str2.size();   
	//(3)capacity
	size_t cap = str2.capacity();
	//(4)reserve
	str2.reserve(20);
	cap = str2.capacity();
	str2.reserve(5);
	cap = str2.capacity();
	//(5)shrink_to_fit
	str2.shrink_to_fit();
	cap = str2.capacity();
	sz = str2.size();
	//(6)str8.clear();
	str3.clear();
	sz = str3.size();
	cap = str3.capacity();

	//(7)empty
	bool e = str3.empty();
	e = str2.empty();

}