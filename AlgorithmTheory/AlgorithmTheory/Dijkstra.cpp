#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

vector<pair<int,int>> graph[10000];		// 각 노드에 대한 연결 정보
int visit[10000];	// 최소 비용 배열

int Dijkstra(int num) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,num });		// 출발 정점 설정
	fill_n(visit, 10000, INT_MAX);	// 출발 정점 비용 초기화
	visit[num] = 0;			

	while (!pq.empty()) {
		int num = pq.top().second;
		/*
			C++ 우선순위 큐는 최댓값을 top으로 지정하기 때문에
			- 를 통해, 최솟값을 top으로 지정하게 변환한 것이다.
		*/
		int cost = -pq.top().first;	

		pq.pop();

		// 현재 노드에 저장되어있는 비용보다 비용이 크다면
		if (visit[num] < cost)
			continue;

		for (int i = 0; i < graph[num].size(); i++) {
			int next = graph[num][i].second;
			int nc = graph[num][i].first + cost;

			// 다음 노드에 저장될 비용이 더 작다면
			if (visit[next] > nc) {
				visit[next] = nc;	// 최소 비용 배열 갱신
				pq.push({ -nc,next });
			}
		}
	}

	// 해당 목적지 최소 비용 값 반환
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

	// 노드 1부터 최소 비용을 구하기
	Dijkstra(1);

	// 노드 1 기준으로 다른 노드의 최소 비용 출력
	for (int i = 1; i <= 6; i++) {
		cout << visit[i] << ' ';
	}
	cout << '\n';

	return 0;
}