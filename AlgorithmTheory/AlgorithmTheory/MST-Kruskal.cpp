#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int s;
	int e;
	int cost;

	bool operator < (Edge &edge) {
		return this->cost < edge.cost;
	}
};


int getParent(int parent[], int num) {
	if (parent[num] == num)
		return num;
	return parent[num] = getParent(parent,parent[num]);
}

void Union(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	a < b ? parent[b] = a : parent[a] = b;
}

bool IsEqualSet(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b)
		return true;
	return false;
}

int main() {
	int n = 7;		// 정점 개수
	int m = 11;		// 간선 개수
	int parent[8];	// 집합을 표현하는 배열

	// 간선 정보
	vector<Edge> edges;
	edges.push_back({ 1,7,12 });
	edges.push_back({ 1,4,28 });
	edges.push_back({ 1,2,67 });
	edges.push_back({ 1,5,17 });
	edges.push_back({ 2,4,24 });
	edges.push_back({ 2,5,62 });
	edges.push_back({ 3,5,20 });
	edges.push_back({ 3,6,37 });
	edges.push_back({ 4,7,13 });
	edges.push_back({ 5,6,45 });
	edges.push_back({ 5,7,73 });

	// 간선 오름차순
	sort(edges.begin(), edges.end());

	// 각 집합을 자기 자신으로 초기화
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	int sum = 0;
	// 간선 순회
	for (auto k : edges) {
		if (!IsEqualSet(parent, k.s, k.e)) {
			// 각 정점을 연결했을 때, 싸이클이 생성되지 않는다면
			sum += k.cost;
			Union(parent, k.s, k.e);	// 각 정점을 한 집합으로 묶기
		}
	}
	
	cout << sum << '\n';

	return 0;
}