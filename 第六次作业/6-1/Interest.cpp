#include "loans.h"
#include<math.h>
Interest::Interest(double month_rate, double amount, int period, double return_amount) :Loan(month_rate, amount, period)
{
	m_return_amount = return_amount;
}
double Interest::Calulate()
{
	m_repayment = Interest::GetFirst() + Interest::GetNext();
	return m_repayment;
}
double Interest::GetFirst()
{
	double first = 0;
	first = Loan::GetAmount() / Loan::GetPeriod();
	return first;
}
double Interest::GetNext()
{
	double next = 0;
	next = (Loan::GetAmount() - m_return_amount) * Loan::GetRate();
	return next;
}