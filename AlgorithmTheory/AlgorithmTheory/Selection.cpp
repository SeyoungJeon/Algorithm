#include <iostream>

using namespace std;

int main() {
	int arr[10] = { 1,10,2,9,3,5,4,8,7,6 };		// ������ ���

	for (int i = 0; i < 10; i++) {
		int min = 9999, index = i;
		for (int j = i; j < 10; j++) {	// �ּڰ��� �ش� �ּڰ��� �ε����� ã��
			if (min > arr[j]) {
				min = arr[j];
				index = j;
			}
		}

		// ���õ� �ּڰ��� ������ ��������
		int temp = arr[i];		
		arr[i] = min;
		arr[index] = temp;
	}

	// ���ĵ� �迭 ���
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';

	return 0;
}