#include <iostream>
#include <vector>

using namespace std;

vector<int> temp;
bool visit[5];

// depth : ���� Ƚ��, end : ��� ���� ������
// cur : ���� ���� ��ȣ
void DFS(int depth, int end, int cur) {
	if (depth >= end) {
		for (auto k : temp) {
			cout << k << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = cur; i < 5; i++) {
		int next = i;

		// �̹� ���� �� �� ���� �ʱ�
		if (visit[next])
			continue;

		// �� �����ϱ�
		visit[next] = true;
		temp.push_back(next);

		// ���� �� ���� ���ʷ� �Ѿ��
		DFS(depth + 1, end, next);

		// �����߾��� �� �����ϱ�
		temp.pop_back();
		visit[next] = false;
	}
}

int main() {
	
	// 3�� ����
	DFS(0, 3, 0);

	return 0;
}