#include <iostream>

using namespace std;

int heap[9] = { 7,6,5,8,3,5,9,1,6 };

int main() {
	
	// �� ���� �����
	for (int i = 1; i < 9 ; i++) {
		int child = i;
		do {
			int root = (child - 1) / 2;
			if (heap[root] < heap[child]) {
				int temp = heap[root];
				heap[root] = heap[child];
				heap[child] = temp;
			}

			child = root;
		} while (child != 0);
	}

	// ũ�⸦ �پ�� �ݺ������� �� ����
	for (int i = 8; i >= 0; i--) {
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;

		int root = 0;
		int child = 1;
		do {
			child = root * 2 + 1;

			// �ڽ� �߿� �� ū �� ã��
			if (child < i - 1 && heap[child] < heap[child + 1]) child++;

			// �θ𺸴� �ڽ��� �� ũ�ٸ� ��ȯ
			if (child < i && heap[root] < heap[child]) {
				temp = heap[root];
				heap[root] = heap[child];
				heap[child] = temp;
			}

			root = child;
		} while (child < i);
	}
	
	// ���ĵ� �迭 ���
	for (int i = 0; i < 9; i++) {
		cout << heap[i] << ' ';
	}
	cout << '\n';

	return 0;
}