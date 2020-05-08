#include <iostream>
#include <vector>

using namespace std;

// 반복문을 활용한 이진탐색
int BinarySearch_Iter(vector<int> data, int key) {
	int left = 0, right = data.size() - 1, mid;

	while (left <= right) {
//		mid = (left + right) / 2;			// 일반적인 mid 값 구하기
		mid = left + (right - left) / 2;	// 오버플로우 발생 방지
		
		if (data[mid] < key) {
			// 탐색한 값이 찾으려는 값보다 작다면
			left = mid + 1;
		}
		else if (data[mid] > key) {
			// 탐색한 값이 찾으려는 값보다 크다면
			right = mid - 1;
		}
		else {
			// 찾으려는 값을 탐색했다면
			break;
		}
	}

	// 찾은 값 배열의 위치를 반환
	return mid;
}


// 재귀를 활용한 이진탐색
int BinarySearch_Recur(vector<int> data, int left, int right, int key) {
	// 끝날 때 까지 탐색하려는 값을 찾지 못한다면
	if (left > right) {
		return -1;
	}
	
	//		mid = (left + right) / 2;			// 일반적인 mid 값 구하기
	int mid = left + (right - left) / 2;	// 오버플로우 발생 방지

	// 탐색한 값이 찾으려는 값보다 작다면
	if (data[mid] < key) {
		return BinarySearch_Recur(data, mid + 1, right, key);
	}
	// 탐색한 값이 찾으려는 값보다 크다면
	else if (data[mid] > key) {
		return BinarySearch_Recur(data, left, mid - 1, key);
	}
	// 찾으려는 값을 찾았다면 배열 위치 반환
	else {
		return mid;
	}

}

int main() {
	vector<int> data;
	// 1 ~ 1000을 오름차순으로 데이터를 가지는 벡터
	for (int i = 0; i < 1000; i++) {
		data.push_back(i + 1);
	}

	// 반복문을 활용한 이진탐색
	cout << BinarySearch_Iter(data, 429) << '\n';

	// 재귀를 호라용한 이진탐색
	cout << BinarySearch_Recur(data, 0, data.size()-1, 429) << '\n';

	return 0;
}