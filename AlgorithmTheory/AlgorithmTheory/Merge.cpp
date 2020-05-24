#include <iostream>

using namespace std;

int sorted[10];

void Merge(int data[], int left, int mid, int right) {
	int Lindex = left, Rindex = mid + 1, idx = left;

	// ���� ������� ������ ����
	while (Lindex <= mid && Rindex <= right) {
		if (data[Lindex] <= data[Rindex]) {
			sorted[idx++] = data[Lindex++];
		} else {
			sorted[idx++] = data[Rindex++];
		}
	}

	// ���� ������ ����
	if (Lindex > mid ) {
		for (int i = Rindex; i <= right; i++) {
			sorted[idx++] = data[i];
		}
	} else {
		for (int i = Lindex; i <= mid; i++) {
			sorted[idx++] = data[i];
		}
	}

	// ���ĵ� �迭 ����
	for (int i = left; i <= right; i++) {
			data[i] = sorted[i];
	}
}

void MergeSort(int data[], int left, int right) {
	// ���ҵ� �迭�� ũ�Ⱑ 1���� ū ���
	if (left < right) {
		int middle = (left + right) / 2;
		MergeSort(data, left, middle);
		MergeSort(data, middle + 1, right);
		Merge(data, left, middle, right);
	}
}

int main() {
	int arr[8] = { 7,6,5,8,3,5,9,1 };		// ������ ���

	MergeSort(arr, 0, 7);

	// ���ĵ� �迭 ���
	for (int i = 0; i < 8; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';

	return 0;
}