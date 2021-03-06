#include <iostream>
#include <vector>

using namespace std;

vector<int> temp;
bool visit[5];

// depth : 뽑은 횟수, end : 몇개를 뽑을 것인지
// cur : 현재 뽑은 번호
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

		// 이미 선택 된 수 뽑지 않기
		if (visit[next])
			continue;

		// 수 선택하기
		visit[next] = true;
		temp.push_back(next);

		// 다음 수 뽑을 차례로 넘어가기
		DFS(depth + 1, end, next);

		// 선택했었던 수 제외하기
		temp.pop_back();
		visit[next] = false;
	}
}

int main() {
	
	// 3개 선택
	DFS(0, 3, 0);

	return 0;
}