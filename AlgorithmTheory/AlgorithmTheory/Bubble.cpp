#include <iostream>

using namespace std;

int main() {
	int arr[10] = { 1,10,2,9,3,5,4,8,7,6 };		// 정렬할 대상

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9 - i; j++) {	// 싸이클 마다 가장 큰 값이 뒤로 가기 때문에
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	// 정렬된 배열 출력
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';

	return 0;
}