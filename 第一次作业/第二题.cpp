#include<iostream>
using namespace std;
int main() {
	int n;
	cout << " 输入整数的个数： " << endl;
	cin >> n ;
	int* data = new int[n];
	//动态数组的初始化
	for (int i = 0; i < n; i++) {
		cout << "输入第" << i + 1 << "个整数的值" << endl;
		cin >> data[i];
	}
	for (int i = 0; i < n-1; i++) {
		int min = i;
		for (int j = i; j < n; j++) {
			if (data[i] > data[j]) {
				min = j;
			}
		}
		swap(data[i], data[min]);
	}
	for (int i = 0; i < n; i++) {
		cout << data[i] <<"  ";
	}
	delete[] data;
}