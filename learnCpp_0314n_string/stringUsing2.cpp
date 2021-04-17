#include<iostream>
#include<string>
using namespace std;

void testStringUsing2() {
	//5.modifiers
	//(1)operator +=
	string str;
	string str2 = "123";
	str += str2;     //"123"
	str += "abcd";    //"123abcd"
	str += 'e';     //"123abcde"

	//(2)append
	str.append(str2);  //"123abcde123"
	str.append(str2, 1, 1);   //"123abcde1232"
	str.append("abc");  //"123abcde1232abc"
	str.append("abcd", 2);  //"123abcde1232abcab"
	str.append(5, '1');  //"123abcde1232abcab11111"
	str.append(++str2.begin(), --str2.end());  //"123abcde1232abcab111112"

	//(3)push_back
	str = "";
	str.push_back('y');   //"y";  

	//(4)pop_back
	str.pop_back();

	//(5)insert
	str.insert(0 , str2);  //"123"
	str.insert(1, str2, 1, 1);  //"1223"
	str.insert(0, "abc");   //"abc1223"
	str.insert(6, "abc", 2);  //"abc122ab3"
	str.insert(0, 3, 'a');  //"aaaabc122ab3"
	//str.insert(0, ++str2.begin(), --str2.end()); 
	//str.insert(str.begin(), str2);
	//str.insert(str.begin(), "abc");
	str.insert(str.begin(), 3, 'a');      //"aaaaaaabc122ab3"
	str.insert(str.begin(), 'a');          //"aaaaaaaabc122ab3"
	str.insert(str.begin(), ++str2.begin(), --str2.end());      //"2aaaaaaaabc122ab3"

	str.erase(0, 5);   //"aaaabc122ab3"
	str.erase(str.begin());   //"aaabc122ab3"
	str.erase(++str.begin(), --str.end());   //"a3"
	
	//(6) replace
	str = "abcdef";
	str.replace(0, 3, str2);     //"123def"
	str.replace(3,1,str2,1,1);    //"1232ef"
	str.replace(4, 2, "aaa");   //"1232aaa"
	str.replace(0, 2, "abcd", 2);   //"ab32aaa"
	str.replace(0, 1, 3, 'c');     //"cccb32aaa"
	str.replace(++str.begin(), --str.end(), "abc");  //"cabca"

	//(7)swap
	str.swap(str2);    //str-"123"  str2-"cabca"

	//(8)assign
	str.assign(str2);   //"cabca"
	str.assign(str2, 1, 4);   //"abca"
	str.assign("abcd");    //"abcd"
	str.assign("abcd", 1, 3);  //"bcd"
	str.assign(5, 'a'); // "aaaaa"
	str.assign(++str2.begin(), --str2.end());   //"abc"

	//6. string operations
	//(1)c_str
	//(2)data
	str.resize(20);
	const char* p = str.c_str();
	const char* p2 = str.data();
	//(2.5)copy
	char pp[20];
	memset(pp, '1', sizeof(char) * 20);
	str.copy(pp, 3, 0);
	//(3)find
	str = "1234567812345123";
	str2 = "123";
	size_t pos = str.find(str2 , 1);
	pos = str.find("123", 0);
	pos = str.find("1235", 1, 3);
	pos = str.find('7',3);
	//(4)rfind
	pos = str.rfind(str2);
	pos = str.rfind("123");
	pos = str.rfind("1234", str.size(), 3);
	pos = str.rfind('5');

	//(5)find_first_of
	pos = str.find_first_of("adceo5");
	pos = str.find_first_of(str);
	//(6)find_last_of
	pos = str.find_last_of("sne3");
	//(7)find_first_not_of
	//(8)find_last_not_of
	pos = str.find_first_not_of("12364237a");
	pos = str.find_last_not_of("29574ev");


	//(9)substr
	string s = str.substr(0, 3);

	str2 = "http://www.cplusplus.com/reference";
	size_t pos1 = str2.find("://");
	size_t end = str2.find('/',pos1+3);
	str = str2.substr(pos1 + 3, end - pos1 - 3);

	string file = "test.tar.gz.txt";
	pos = file.rfind('.');
	str = file.substr(pos + 1);

	//7 non-member function overloads
	//(1)relational operators
	//(2)swap
	//(3)operator>>
	cin >> str;
	cout << str << endl;

	getline(cin, str);
	cout << str << endl;
	getline(cin, str, ',');
	cout << str << endl;
}