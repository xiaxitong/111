#include "loans.h"
#include<math.h>
#include<iostream>
using namespace std;
void Show(Loan* l)
{
	cout<<"还款金额为："<<l->Calulate()<<endl;
}
void main()
{
	Equivalent e(0.29, 2900, 12);
	cout << "等额本息的" ;
	Show(&e);
	Interest i(0.39, 2900, 12, 0);
	cout << "等额本金的" ;
	Show(&i);
}