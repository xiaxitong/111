#include "loans.h"
#include<math.h>
Equivalent::Equivalent(double month_rate, double amount, int period) :Loan(month_rate, amount, period)
{
	
}
double Equivalent::GetX()
{
	double x = 0;
	x = pow(1 + Loan::GetRate(), Loan::GetPeriod());//指数的计算用pow（）函数实现。
	return x;
}
double Equivalent::Getfenzi()
{
	double fenzi = 0;
	fenzi = Loan::GetRate() * Equivalent::GetX() * Loan::GetAmount();
	return fenzi;
}
double Equivalent::Getfenmu()
{
	double fenmu = 0;
	fenmu = Equivalent::GetX() - 1;
	return fenmu;
}
double Equivalent::Calulate()
{
	m_repayment = Equivalent::Getfenzi() / Equivalent::Getfenmu();
	return m_repayment;
}
