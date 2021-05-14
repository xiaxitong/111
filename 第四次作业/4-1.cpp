#include <iostream>
using namespace std;
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
};
Rectangle::Rectangle(int length, int width)
{
	m_length = length;
	m_width = width;
}
int Rectangle::Getarea()
{
	m_area = m_length * m_width ;
	return m_area;
}
int Rectangle::Getperimeter()
{
	m_perimeter = (m_length + m_width) * 2;
	return m_perimeter;
}
class Cuboid :public Rectangle
{
private:
	int m_height;
	int m_volume;
public:
	Cuboid(int length, int width,int height);
	int Getvolume();
};
Cuboid::Cuboid(int length, int width,int height):Rectangle(length, width)
{
	m_height = height;
}
int Cuboid::Getvolume()
{
	m_volume = Rectangle::Getarea() * m_height;
	return m_volume;
}
void main()
{
	Rectangle r(10,10);
	Cuboid c(10, 10, 10);
	cout << "矩形的面积为" << r.Getarea() << '\n' << "矩形的周长为：" << r.Getperimeter() <<'\n'<<
		"长方体的体积为："<<c.Getvolume()<<endl;

}