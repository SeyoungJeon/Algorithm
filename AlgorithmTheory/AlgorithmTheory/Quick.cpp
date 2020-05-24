#include <iostream>

using namespace std;

void QuickSort(int *data, int start, int end) {
	if (start >= end) return;	// ���ҵǾ��� ���Ұ� 1�� �� ���

	int key = start;			// pivot �� ����
	int left = start + 1, right = end, temp;

	while (left <= right) {
		while (left <= end && data[left] <= data[key]) left++;		// pivot ������ ū ���� ���� �� ����
		while (right > start && data[right] >= data[key]) right--;	// pivot �� ���� ���� ���� ���� �� ����
		
		if (left > right) {
			// �������� ��� Ű ���� ��ü
			temp = data[right];
			data[right] = data[key];
			data[key] = temp;
		}
		else {
			// �������� �ʾҴٸ� left�� right ��ü
			temp = data[right];
			data[right] = data[left];
			data[left] = temp;
		}
	}

	QuickSort(data, right + 1, end);
	QuickSort(data, start, right - 1);
}

int main() {
	int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };		// ������ ���

	QuickSort(arr, 0, 9);

	// ���ĵ� �迭 ���
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';

	return 0;
}