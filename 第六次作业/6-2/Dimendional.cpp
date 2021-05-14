#include "Dimendional.h"
#include<math.h>
Dimensional::Dimensional()
{}
Dimensional::Dimensional(int x, int y, int z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}
Dimensional Dimensional::operator+(const Dimensional &d)
{
	sum_x = m_x + d.m_x;
	sum_y = m_y + d.m_y;
	sum_z = m_z + d.m_z;
	return *this;
}
Dimensional Dimensional::operator-(const Dimensional &d)
{
	remain_x = abs(m_x - d.m_x);
	remain_y = abs(m_y - d.m_y);
	remain_z = abs(m_z - d.m_z);
	return *this;
}