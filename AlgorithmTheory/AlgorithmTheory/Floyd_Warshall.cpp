#include <iostream>

#define MAX 1e9

using namespace std;

int dist[4][4], map[4][4] = {{0,5,MAX,8}, {7,0,9,MAX},{2,MAX,0,4},{MAX,MAX,3,0} };

// O(N*N*N)
void floydWarshall() {
	// 거리 배열 초기화
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			dist[i][j] = map[i][j];
		}
	}

	for (int k = 0; k < 4; k++) {	// 거쳐가는 노드
		for (int i = 0; i < 4; i++) {	// 출발 노드
			for (int j = 0; j < 4; j++) {	// 도착 노드
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	floydWarshall();
	
	// 모든 정점에서 다른 정점까지 최소 비용 배열 출력
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}