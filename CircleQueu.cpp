#include <iostream>
#include <Windows.h>

using namespace std;

template <class T>
class Queue {
	T* _arr;
	int _top;
	int _capacity;
	const int _MIN{ -1 };

public:
	Queue(int capacity) {
		_arr = new T[capacity];
		_top = _MIN;
		_capacity = capacity;
	}

	bool is_empty() {
		return _top == _MIN;
	}

	bool is_full() {
		return _top == _capacity - 1;
	}

	void push(T value) {
		if (is_full()) {
			cout << "is full" << endl;
			exit(1);
		}

		_arr[++_top] = value;
	}

	T pop() {
		if (is_empty()) {
			cout << "is empty" << endl;
			exit(1);
		}

		auto first = _arr[0];
		for (size_t i = 0; i < _top; i++)
			swap(_arr[i], _arr[i + 1]);

		return first;
	}

	T& front() {
		if (is_empty()) {
			cout << "is empty" << endl;
			exit(1);
		}

		return _arr[0];
	}
};

int main() {
	setlocale(0, "");
	SetConsoleCP(1251);

	Queue<int> q(3);

	q.push(1);
	q.push(2);
	q.push(3);

	for (size_t i = 0; i < 20; i++) {
		system("cls");
		cout << q.pop() << endl;
		Sleep(10 * i);
	}
	auto first = q.front();

	for (size_t i = 0; i < 20; i++) {
		system("cls");
		cout << first << ' ' << q.pop() << endl;
		Sleep(10 * i);
	}

	return 0;
}