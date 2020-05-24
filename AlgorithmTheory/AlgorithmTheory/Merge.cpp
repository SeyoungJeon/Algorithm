#include <iostream>

using namespace std;

int sorted[10];

void Merge(int data[], int left, int mid, int right) {
	int Lindex = left, Rindex = mid + 1, idx = left;

	// 작은 순서대로 데이터 삽입
	while (Lindex <= mid && Rindex <= right) {
		if (data[Lindex] <= data[Rindex]) {
			sorted[idx++] = data[Lindex++];
		} else {
			sorted[idx++] = data[Rindex++];
		}
	}

	// 남은 데이터 삽입
	if (Lindex > mid ) {
		for (int i = Rindex; i <= right; i++) {
			sorted[idx++] = data[i];
		}
	} else {
		for (int i = Lindex; i <= mid; i++) {
			sorted[idx++] = data[i];
		}
	}

	// 정렬된 배열 삽입
	for (int i = left; i <= right; i++) {
			data[i] = sorted[i];
	}
}

void MergeSort(int data[], int left, int right) {
	// 분할된 배열의 크기가 1보다 큰 경우
	if (left < right) {
		int middle = (left + right) / 2;
		MergeSort(data, left, middle);
		MergeSort(data, middle + 1, right);
		Merge(data, left, middle, right);
	}
}

int main() {
	int arr[8] = { 7,6,5,8,3,5,9,1 };		// 정렬할 대상

	MergeSort(arr, 0, 7);

	// 정렬된 배열 출력
	for (int i = 0; i < 8; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';

	return 0;
}