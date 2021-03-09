#include <iostream>
#include <cmath>
using namespace std;
void DisplayInfo(short int s_int);
void DisplayInfo( int i);
void DisplayInfo(double d);
int main() {
	short int s_int=0;
	int i=0;
	double d=0;
	DisplayInfo(s_int);
	DisplayInfo(i);
	DisplayInfo(d);
	return 0;
}
void DisplayInfo(short int s_int) {
	cout << "输入短整数的值：" << endl;
	cin >> s_int;
	int a_s_int;
	a_s_int = abs(s_int);
	cout << a_s_int << endl;
}
void DisplayInfo(int i) {
	cout << "输入整数的值：" << endl;
	cin >> i;
	int a_i;
	a_i = abs(i);
	cout << a_i << endl;
}
void DisplayInfo(double d) {
	cout << "输入双精度数的值：" << endl;
	cin >> d;
	int a_d;
	a_d = fabs(d);
	cout << a_d << endl;
}
