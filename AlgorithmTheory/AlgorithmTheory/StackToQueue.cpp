#include <iostream>
#include <stack>

using namespace std;


template <typename T>
class Queue {

private:
	stack<T> in;
	stack<T> out;
	int size = 0;

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

	void Push(T value) {
		in.push(value);
		size++;
	}

	T Front() {
		ShitftInToOut();
		T item = NULL;
		if (!out.empty()) {
			item = out.top();
		}
		return item;
	}

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

	int Size() {
		return size;
	}

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