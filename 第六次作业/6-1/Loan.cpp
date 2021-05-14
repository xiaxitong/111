#include "loans.h"
#include<math.h>
Loan::Loan(double month_rate, double amount, int period)
{
	m_month_rate = month_rate;
	m_amount = amount;
	m_period = period;
}
double Loan::GetRate()
{
	return m_month_rate;
}
double Loan::GetAmount()
{
	return m_amount;
}
int Loan::GetPeriod()
{
	return m_period;
}
double Loan::Calulate()
{
	return 0;
}

