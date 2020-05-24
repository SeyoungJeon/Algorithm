#include <iostream>

using namespace std;

void QuickSort(int *data, int start, int end) {
	if (start >= end) return;	// 분할되어진 원소가 1개 인 경우

	int key = start;			// pivot 값 설정
	int left = start + 1, right = end, temp;

	while (left <= right) {
		while (left <= end && data[left] <= data[key]) left++;		// pivot 값보다 큰 수를 만날 때 까지
		while (right > start && data[right] >= data[key]) right--;	// pivot 값 보다 작은 수를 만날 때 까지
		
		if (left > right) {
			// 엇갈렸을 경우 키 값과 교체
			temp = data[right];
			data[right] = data[key];
			data[key] = temp;
		}
		else {
			// 엇갈리지 않았다면 left와 right 교체
			temp = data[right];
			data[right] = data[left];
			data[left] = temp;
		}
	}

	QuickSort(data, right + 1, end);
	QuickSort(data, start, right - 1);
}

int main() {
	int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };		// 정렬할 대상

	QuickSort(arr, 0, 9);

	// 정렬된 배열 출력
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';

	return 0;
}