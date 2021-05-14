#include"Dimendional.h"
#include<iostream>
using namespace std;
void main()
{
	Dimensional d1(1, 2, 3), d2(2, 3, 4),d3,d4;
	d3 = d1 + d2;
	cout << "x,y,z的和分别是："<<d3.sum_x<<','<<d3.sum_y<<','<<d3.sum_z<<endl;
	d4 = d1 - d2;
	cout << "x,y,z的差分别是：" << d4.remain_x << ',' << d4.remain_y << ',' << d4.remain_z << endl;

}