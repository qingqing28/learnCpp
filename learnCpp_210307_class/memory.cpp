//#include<iostream>
//using namespace std;
//
//
//int main() {
//	char* ptr = (char*)malloc(sizeof(char) * 3);
//	for (int i = 0; i < 3; i++) {
//		ptr[i] = i + 'a';
//	}
//	ptr[3] = '\0';
//	char* ptr2 = (char*)realloc(ptr , sizeof(char) * 1000);
//	for (int i = 2; i < 1000; i++) {
//		ptr2[i] = i + 'a';
//	}
//	ptr2[9] = '\0';
//	cout << ptr[2] << "  " << ptr2[2] << endl;
//	cout << ptr[6] << endl;
//
//
//	return 0;
//}
//
//
////
////int globalVal = 1;
////static int staticGlobalVal = 1;
//
////int main() {
////	static int staticVal = 1;
////	int localVal = 1;
////
////	int num1[10] = { 1,2,3,4 };
////	char char2[] = "abcd";
////	const char* pChar3 = "abcd";
////	int* ptr1 = (int*)malloc(sizeof(int) * 4);
////	return 0;
////}
//
