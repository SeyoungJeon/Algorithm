#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

vector<pair<int,int>> graph[10000];		// �� ��忡 ���� ���� ����
int visit[10000];	// �ּ� ��� �迭

int Dijkstra(int num) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,num });		// ��� ���� ����
	fill_n(visit, 10000, INT_MAX);	// ��� ���� ��� �ʱ�ȭ
	visit[num] = 0;			

	while (!pq.empty()) {
		int num = pq.top().second;
		/*
			C++ �켱���� ť�� �ִ��� top���� �����ϱ� ������
			- �� ����, �ּڰ��� top���� �����ϰ� ��ȯ�� ���̴�.
		*/
		int cost = -pq.top().first;	

		pq.pop();

		// ���� ��忡 ����Ǿ��ִ� ��뺸�� ����� ũ�ٸ�
		if (visit[num] < cost)
			continue;

		for (int i = 0; i < graph[num].size(); i++) {
			int next = graph[num][i].second;
			int nc = graph[num][i].first + cost;

			// ���� ��忡 ����� ����� �� �۴ٸ�
			if (visit[next] > nc) {
				visit[next] = nc;	// �ּ� ��� �迭 ����
				pq.push({ -nc,next });
			}
		}
	}

	// �ش� ������ �ּ� ��� �� ��ȯ
	return visit[6];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	graph[1].push_back({ 2,2 });
	graph[1].push_back({ 5,3 });
	graph[1].push_back({ 1,4 });

	graph[2].push_back({ 2,1 });
	graph[2].push_back({ 3,3 });
	graph[2].push_back({ 2,4 });

	graph[3].push_back({ 5,1 });
	graph[3].push_back({ 3,2 });
	graph[3].push_back({ 3,4 });
	graph[3].push_back({ 1,5 });
	graph[3].push_back({ 5,6 });


	graph[4].push_back({ 1,1 });
	graph[4].push_back({ 2,2 });
	graph[4].push_back({ 3,3 });
	graph[4].push_back({ 1,5 });

	graph[5].push_back({ 1,3 });
	graph[5].push_back({ 1,4 });
	graph[5].push_back({ 2,6 });


	graph[6].push_back({ 5,3 });
	graph[6].push_back({ 2,5 });

	// ��� 1���� �ּ� ����� ���ϱ�
	Dijkstra(1);

	// ��� 1 �������� �ٸ� ����� �ּ� ��� ���
	for (int i = 1; i <= 6; i++) {
		cout << visit[i] << ' ';
	}
	cout << '\n';

	return 0;
}