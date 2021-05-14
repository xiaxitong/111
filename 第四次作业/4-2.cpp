#include <iostream>
using namespace std;
//矩形类
class Rectangle
{
private:
	int m_length;
	int m_width;
	int m_area;
	int m_perimeter;
public:
	Rectangle(int length, int width);
	int Getarea();
	int Getperimeter();
	int Getlength();
	int Getwidth();
};
Rectangle::Rectangle(int length, int width)
{
	m_length = length;
	m_width = width;
}
int Rectangle::Getlength()
{
	return m_length;
}
int Rectangle::Getwidth()
{
	return m_width;
}
int Rectangle::Getarea()
{
	m_area = m_length * m_width;
	return m_area;
}
int Rectangle::Getperimeter()
{
	m_perimeter = (m_length + m_width) * 2;
	return m_perimeter;
}
//长方体类
class Cuboid :public Rectangle
{
private:
	int m_height;
	int m_volume;
public:
	Cuboid(int length, int width, int height);
	int Getvolume();
};
Cuboid::Cuboid(int length, int width, int height) :Rectangle(length, width)
{
	m_height = height;
}
int Cuboid::Getvolume()
{
	m_volume = Rectangle::Getarea() * m_height;
	return m_volume;
}
/*二维点类
class Coordinate :public Cuboid
{
	char m_x;
	char m_y;
public:
	Coordinate();
	char GetX_position();
	char GetY_position();
};
char Coordinate::GetX_position()
{
	m_x = Rectangle::Getlength();
	return m_x;
}
char Coordinate::GetY_position()
{
	m_y = Rectangle::Getwidth();
	return m_y;
}*/
void main()
{
	Rectangle r(10, 10);
	Cuboid c(10, 10, 10);
//	Coordinate c_position;
	cout << "矩形的面积为" << r.Getarea() << '\n' << "矩形的周长为：" << r.Getperimeter() << '\n' <<
		"长方体的体积为：" << c.Getvolume() << endl;
	//	'\n'<< "长方体的横纵坐标为：" << c_position.GetX_position() << c_position.GetY_position() <<
}