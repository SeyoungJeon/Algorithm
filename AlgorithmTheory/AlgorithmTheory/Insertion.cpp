#include <iostream>

using namespace std;

int main() {
	int arr[10] = { 1,10,2,9,3,5,4,8,7,6 };		// ������ ���

	for (int i = 0; i < 10; i++) {
		int index = i;
		while (index > 0 && arr[index] > arr[index+1]) {	// ��������
			int temp = arr[index];
			arr[index] = arr[index + 1];
			arr[index + 1] = temp;
			index--;
		}
	}

	// ���ĵ� �迭 ���
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';

	return 0;
}