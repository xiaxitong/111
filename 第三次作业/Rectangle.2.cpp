#include<iostream>
using namespace std;
class Rectangle {
private:
	int r_length;
	int r_width;
	int r_space;
	int r_perimeter;
public:
	Rectangle(int length = 0, int width = 0);
	void SetLength(int length);
	void SetWidth(int width);
	int GetSpace();
	int GetPerimeter();
	void DisplayInfo();
};
Rectangle::Rectangle(int length, int width) {
	r_length = length;
	r_width = width;
	r_space = r_length * r_width;
	r_perimeter = (r_length + r_width) * 2;
}
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
void Rectangle::DisplayInfo() {
	cout << "第二个矩形的面积和周长分别是：" << r_space << "  " << r_perimeter << endl;
}
void main() {
	Rectangle r1;
	Rectangle r2(30,40);
	r1.SetLength(10);
	r1.SetWidth(20);
	cout << "第一个矩形的面积和周长分别是：" << r1.GetSpace() << "  " << r1.GetPerimeter() << endl;
	r2.DisplayInfo();
}