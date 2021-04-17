#include<iostream>
using namespace std;
void testStringUsing2();
void testStringUsing1();
string addStrings(string num1, string num2) {
    int step = 0;
    string ret;
    int end1 = num1.size() - 1;
    int end2 = num2.size() - 1;
    while (end1 >= 0 || end2 >= 0) {
        int curret = step;
        if (end1 >= 0) {
            curret += num1[end1] - '0';
            --end1;
        }
        if (end2 >= 0) {
            curret += num2[end2] - '0';
            --end2;
        }
        if (curret > 9) {
            curret -= 10;
            step = 1;
        }
        else {
            step = 0;
        }
        ret.insert(0, 1, curret + '0');
    }
    if (step == 1) {
        ret.insert(0, 1, '1');
    }
    return ret;
}

string multiply(string num1, string num2) {
    int end1 = num1.size() - 1;
    int end2 = num2.size() - 1;
    string ret;
    while (end2 >= 0) {
        int end = end1;
        string str(num2.size() - 1 - end2, '0');
        int curret = 0;
        int step = 0;
        while (end >= 0) {
            curret = (num1[end] - '0') * (num2[end2] - '0');
            curret += step;
            if (curret > 9) {
                step = curret / 10;
                curret = curret % 10;
            }
            else {
                step = 0;
            }
            str.insert(0, 1, curret + '0');
            --end;
        }
        ret = addStrings(ret, str);
        --end2;
    }
    return ret;
}
int main()
{
	//testStringUsing2();
	//testStringUsing1();
    string num1 = "3";
    string num2 = "2";
    cout << multiply(num1, num2);
	return 0;
}