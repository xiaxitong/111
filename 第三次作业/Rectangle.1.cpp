#include<iostream>
using namespace std;
class Rectangle {
private:
	int r_length;
	int r_width;
public:
	void SetLength(int length);
	void SetWidth(int width);
	int GetSpace();
	int GetPerimeter();
};
void Rectangle::SetLength(int length) {
	r_length = length;
}
void Rectangle::SetWidth(int width) {
	r_width = width;
}
int Rectangle::GetSpace() {
	int space = 0;
	space = r_length * r_width;
	return space;
}
int Rectangle::GetPerimeter() {
	int perimeter = 0;
	perimeter = (r_length + r_width) * 2;
	return perimeter;
}
void main() {
	Rectangle r1, r2;
	r1.SetLength(10);
	r1.SetWidth(20);
	cout << "��һ�����ε�������ܳ��ֱ��ǣ�" << r1.GetSpace() << "  " << r1.GetPerimeter() << endl;
	r2.SetLength(30);
	r2.SetWidth(40);
	cout << "�ڶ������ε�������ܳ��ֱ��ǣ�" << r2.GetSpace() << "  " << r2.GetPerimeter() << endl;

}