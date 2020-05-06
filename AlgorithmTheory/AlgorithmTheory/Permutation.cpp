#include <iostream>
#include <vector>

using namespace std;

vector<int> temp;
bool visit[5];

// depth : ���� Ƚ��, end : ��� ���� ������
void DFS(int depth,int end) {
	if (depth >= end) {
		for (auto k : temp) {
			cout << k << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < 5; i++) {
		int next = i;

		// �̹� ���õ� ���� ���� �ʱ�
		if (visit[next])
			continue;

		// �� �����ϱ�		
		visit[next] = true;
		temp.push_back(next);

		// ���� �� ���� ���ʷ� �Ѿ��
		DFS(depth + 1, end);

		// �����߾��� �� �����ϱ�
		temp.pop_back();
		visit[next] = false;
	}
}
int main() {
	
	// 3�� �����ϱ�
	DFS(0, 3);

	return 0;
}