#include<iostream>
using namespace std;
class Phone {
private:
	char model[10];
	char colour[5];
	char number[20];
public:
	void Buy_ph(int number);
	void Use_ph(char* app);
};