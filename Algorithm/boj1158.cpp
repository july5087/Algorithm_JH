//�����۽� ����
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

	//1. �� 1�� �����ϰ� 1~N������ push()
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << "<";

	//2. ���� �� ������ �ݺ�
	while (!q.empty()) {
		//K-1��ŭ �� �� ��� pop�ؼ� �� �ڿ� push
		for (int i = 0; i < k - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		if (q.size() > 1)
			cout << q.front() << ", ";
		//ť ������ 1�̸�(���������) ��� �� ����
		else
			cout << q.front() << ">\n";

		q.pop();
	}
}