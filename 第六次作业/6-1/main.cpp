#include "loans.h"
#include<math.h>
#include<iostream>
using namespace std;
void Show(Loan* l)
{
	cout<<"������Ϊ��"<<l->Calulate()<<endl;
}
void main()
{
	Equivalent e(0.29, 2900, 12);
	cout << "�ȶϢ��" ;
	Show(&e);
	Interest i(0.39, 2900, 12, 0);
	cout << "�ȶ���" ;
	Show(&i);
}