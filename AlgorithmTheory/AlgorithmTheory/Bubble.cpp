#include <iostream>

using namespace std;

int main() {
	int arr[10] = { 1,10,2,9,3,5,4,8,7,6 };		// ������ ���

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9 - i; j++) {	// ����Ŭ ���� ���� ū ���� �ڷ� ���� ������
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	// ���ĵ� �迭 ���
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';

	return 0;
}