//조세퍼스 문제
#include<iostream>
#include<deque>
#include<queue>
#include<string>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> dq;
	queue<int> q;

	int n = 0, k = 0;
	cin >> n >> k;

	//1. 덱 1개 선언하고 1~N번까지 push()
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << "<";

	//2. 덱이 빌 때까지 반복
	while (!q.empty()) {
		//K-1만큼 맨 앞 요소 pop해서 맨 뒤에 push
		for (int i = 0; i < k - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		if (q.size() > 1)
			cout << q.front() << ", ";
		//큐 사이즈 1이면(마지막요소) 출력 후 종료
		else
			cout << q.front() << ">\n";

		q.pop();
	}
}