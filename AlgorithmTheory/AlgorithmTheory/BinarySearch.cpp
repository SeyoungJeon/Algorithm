#include <iostream>
#include <vector>

using namespace std;

// �ݺ����� Ȱ���� ����Ž��
int BinarySearch_Iter(vector<int> data, int key) {
	int left = 0, right = data.size() - 1, mid;

	while (left <= right) {
//		mid = (left + right) / 2;			// �Ϲ����� mid �� ���ϱ�
		mid = left + (right - left) / 2;	// �����÷ο� �߻� ����
		
		if (data[mid] < key) {
			// Ž���� ���� ã������ ������ �۴ٸ�
			left = mid + 1;
		}
		else if (data[mid] > key) {
			// Ž���� ���� ã������ ������ ũ�ٸ�
			right = mid - 1;
		}
		else {
			// ã������ ���� Ž���ߴٸ�
			break;
		}
	}

	// ã�� �� �迭�� ��ġ�� ��ȯ
	return mid;
}


// ��͸� Ȱ���� ����Ž��
int BinarySearch_Recur(vector<int> data, int left, int right, int key) {
	// ���� �� ���� Ž���Ϸ��� ���� ã�� ���Ѵٸ�
	if (left > right) {
		return -1;
	}
	
	//		mid = (left + right) / 2;			// �Ϲ����� mid �� ���ϱ�
	int mid = left + (right - left) / 2;	// �����÷ο� �߻� ����

	// Ž���� ���� ã������ ������ �۴ٸ�
	if (data[mid] < key) {
		return BinarySearch_Recur(data, mid + 1, right, key);
	}
	// Ž���� ���� ã������ ������ ũ�ٸ�
	else if (data[mid] > key) {
		return BinarySearch_Recur(data, left, mid - 1, key);
	}
	// ã������ ���� ã�Ҵٸ� �迭 ��ġ ��ȯ
	else {
		return mid;
	}

}

int main() {
	vector<int> data;
	// 1 ~ 1000�� ������������ �����͸� ������ ����
	for (int i = 0; i < 1000; i++) {
		data.push_back(i + 1);
	}

	// �ݺ����� Ȱ���� ����Ž��
	cout << BinarySearch_Iter(data, 429) << '\n';

	// ��͸� ȣ����� ����Ž��
	cout << BinarySearch_Recur(data, 0, data.size()-1, 429) << '\n';

	return 0;
}