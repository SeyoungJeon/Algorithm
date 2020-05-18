#include <iostream>

using namespace std;

int parent[11];

// 해당 노드의 부모가 누구인지
int GetParent(int num) {
	// 자기 자신이 부모일 경우
	if (parent[num] == num) {
		return num;
	}

	return parent[num] = GetParent(parent[num]);
}

// 각 집합들을 하나의 집합으로 합치기
void Union(int a, int b) {
	int aParent = GetParent(a);
	int bParent = GetParent(b);
	
	// 더 작은 숫자로 집합 설정하기
	if (a < b) {			
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

bool Find(int a, int b) {
	int aParent = GetParent(a);
	int bParent = GetParent(b);
	// a와 b의 부모가 같다면 같은 집합
	if (aParent == bParent) {	
		return true;
	}
	// a와 b의 부모가 다르다면 다른 집합
	return false;				
}

int main() {
	// 처음에는 자기 자신이 독립적인 집합이므로 자기 자신으로 초기화
	for(int i=1; i <= 10; i++){
		parent[i] = i;
	}

	Union(2, 5);
	Union(1, 5);
	Union(3, 6);
	Union(4, 3);

	// 같은 집합인지 확인
	cout << Find(6, 4) << '\n';
	cout << Find(1, 10) << '\n';

	return 0;
}