#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class Queue {

private:
	stack<T> in;	// 입력 Stack
	stack<T> out;	// 출력 Stack
	int size = 0;	// 큐 Size

	// 입력 Stack에서 Out Stack으로 담기
	void ShitftInToOut() {
		if (out.empty()) {
			while (!in.empty()) {
				out.push(in.top());
				in.pop();
			}
		}
	}

public:
	Queue() {}
	~Queue() {}

	// 원소 삽입
	void Push(T value) {
		in.push(value);
		size++;
	}

	// 처음 원소 가리키기
	T Front() {
		ShitftInToOut();
		T item = NULL;
		if (!out.empty()) {
			item = out.top();
		}
		return item;
	}

	// 원소 삭제
	T Pop() {
		ShitftInToOut();
		T item = NULL;
		if (!out.empty()) {
			item = out.top();
			out.pop();
			size--;
		}

		return item;
	}

	// 큐 사이즈 반환
	int Size() {
		return size;
	}

	// 큐 상태
	bool Empty() {
		return size == 0;
	}

};

int main() {
	Queue<int> q;
	q.Push(3);
	q.Push(2);
	q.Push(1);

	cout << q.Front() << '\n';
	cout << q.Front() << '\n';
	cout << q.Front() << '\n';
	
	return 0;
}