#include<iostream>
using namespace std;
int main() {
	int n;
	cout << " ���������ĸ����� " << endl;
	cin >> n ;
	int* data = new int[n];
	//��̬����ĳ�ʼ��
	for (int i = 0; i < n; i++) {
		cout << "�����" << i + 1 << "��������ֵ" << endl;
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