#include<iostream>
using namespace std;
template <typename T>
class Stack
{
private:
	T arr[10];
	int top ;
public:
	Stack() :top(0) {};

	void push(T temp)
	{
		arr[top+1] = temp;
		top++;
	}
	T pop()
	{
		T temp;
		temp = arr[top];
		arr[top-1]==NULL;
		top--;
		return temp;
	}
	bool empty()
	{
		if (top == 0)
			return false;
		else
			return true;
	}
	bool full()
	{
		if (top == 10)
			return false;
		else
			return true;
	}
};
void main()
{
	string type = "";
	int i ;
	int length = 0;
	char tempChar;
	int tempInt;
	cin >> type;
	cin >> length;
	if (type == "char")
	{
		Stack<char>  C_char;
		for (i = 0; i < length; i++)
		{
			cin >> tempChar;
			if (C_char.full())
			{
				C_char.push(tempChar);
			}
			else
			{
				cout << "Õ»ÒÑÂú£¡" << endl;
			}
		}
		for (i = 0; i < length; i++)
		{
			if (C_char.empty())
			{
				cout << C_char.pop() << endl;
			}
			else
			{ 
				cout << "Õ»ÒÑ¿Õ£¡" << endl;
			}
		}
	}
	if (type == "int")
	{
		Stack<int>  C_int;
		for (i = 0; i < length; i++)
		{
			cin >> tempInt;
			if (C_int.full())
			{
				C_int.push(tempInt);
			}
			else
			{
				cout << "Õ»ÒÑÂú£¡" << endl;
			}
		}
		for (i = 0; i < length; i++)
		{
			if (C_int.empty())
			{
				cout << C_int.pop() << endl;
			}
			else
			{
				cout << "Õ»ÒÑ¿Õ£¡" << endl;
			}
		}
	}
}