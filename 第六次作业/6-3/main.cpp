#include <iostream>
using namespace std;
template <typename T>
class Compare
{
	T m_x;
	T m_y;
	T m_max;
	T m_min;
public:
	Compare(T x, T y);
	void Max();
	void Min();
};
template <typename T>
Compare<T>::Compare(T x, T y)
{
	m_x = x;
	m_y = y;
}
template <typename T>
void Compare<T>::Max()
{
	if (m_x > m_y)
	{
		m_max = m_x;
	}
	else
	{
		m_max = m_y;
	}
	cout << "最大值是：" << m_max << endl;
}
template <typename T>
void Compare<T>::Min()
{
	if (m_x < m_y)
	{
		m_min = m_x;
	}
	else
	{
		m_min = m_y;
	}
	cout << "最小值是：" << m_min << endl;
}
void main()
{
	Compare<int> c1(2, 5);
	c1.Max();
	c1.Min();
	Compare<double> c2(2.0, 4.0);
	c2.Max();
	c2.Min();
}