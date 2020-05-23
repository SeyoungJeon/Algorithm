#include <iostream>

using namespace std;

int main() {
	int arr[10] = { 1,10,2,9,3,5,4,8,7,6 };		// 정렬할 대상

	for (int i = 0; i < 10; i++) {
		int min = 9999, index = i;
		for (int j = i; j < 10; j++) {	// 최솟값과 해당 최솟값의 인덱스를 찾기
			if (min > arr[j]) {
				min = arr[j];
				index = j;
			}
		}

		// 선택된 최솟값을 앞으로 가져오기
		int temp = arr[i];		
		arr[i] = min;
		arr[index] = temp;
	}

	// 정렬된 배열 출력
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';

	return 0;
}