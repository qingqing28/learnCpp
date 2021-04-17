#include<iostream>
using namespace std;

class SeqList {
public:
	SeqList(int* pData=(int*)malloc(sizeof(int)*5), int size = 0, int capacity = 5) {
		_pData = pData;
		_size = size;
		_capacity = capacity;
		cout << "SeqList(int* int int)" << endl;
	}
	~SeqList() {
		if (_pData) {
			free(_pData);
			_pData = nullptr;
			_size = 0;
			_capacity = 0;
		}
		cout << "~SeqList" << endl;
	}
private:
	int* _pData;
	int _size;
	int _capacity;
};

void testSeq() {
	SeqList sq;
}