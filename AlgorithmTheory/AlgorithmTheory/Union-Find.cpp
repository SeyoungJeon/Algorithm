#include <iostream>

using namespace std;

int parent[11];

// �ش� ����� �θ� ��������
int GetParent(int num) {
	// �ڱ� �ڽ��� �θ��� ���
	if (parent[num] == num) {
		return num;
	}

	return parent[num] = GetParent(parent[num]);
}

// �� ���յ��� �ϳ��� �������� ��ġ��
void Union(int a, int b) {
	int aParent = GetParent(a);
	int bParent = GetParent(b);
	
	// �� ���� ���ڷ� ���� �����ϱ�
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
	// a�� b�� �θ� ���ٸ� ���� ����
	if (aParent == bParent) {	
		return true;
	}
	// a�� b�� �θ� �ٸ��ٸ� �ٸ� ����
	return false;				
}

int main() {
	// ó������ �ڱ� �ڽ��� �������� �����̹Ƿ� �ڱ� �ڽ����� �ʱ�ȭ
	for(int i=1; i <= 10; i++){
		parent[i] = i;
	}

	Union(2, 5);
	Union(1, 5);
	Union(3, 6);
	Union(4, 3);

	// ���� �������� Ȯ��
	cout << Find(6, 4) << '\n';
	cout << Find(1, 10) << '\n';

	return 0;
}