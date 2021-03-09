#include<iostream>
using namespace std;
struct Complex {
	int real;
	int img;
};
void r_swap(int& cr1, int& cr2) {
	int t;
	t = cr1;
	cr1 = cr2;
	cr2 = t;
}
void i_swap(int& ci1, int& ci2) {
	int t;
	t = ci1;
	ci1 = ci2;
	ci2 = t;
}
int main() {
	Complex c1, c2;
	cout << "输入第一个复数的实部和虚部：" << endl;
	cin >> c1.real >> c1.img;
	cout << "输入第二个复数的实部和虚部：" << endl;
	cin >> c2.real >> c2.img;
	r_swap(c1.real, c2.real);
	i_swap(c1.img, c2.img);
	cout << c1.real << "+" << c1.img << "i" << endl;
	cout << c2.real << "+" << c2.img << "i" << endl;
	return 0;
}