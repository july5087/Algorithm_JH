//������
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100001

int main() {
	int N, M; //���� ��, ���� ��(����, ����)
	vector<int> graph[MAX]; //����׷���
	int degree[MAX]; //��������
	priority_queue<int, vector<int>, greater<int>> pq; //1~N�� ����� ���� ���� ����(������)���� ����ϱ� ���� �ּ��� pq ���

	cin >> N >> M;

	//���� �Է�
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		degree[b]++;
	}

	//���������� 0�� ���� ť�� ����
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) pq.push(i);
	}

	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		cout << cur << " ";

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			degree[next]--; //ť���� �� ������ �̾��� ��� ���� ����

			//���������� 0�� ���ο� ���� ť�� ����
			if (degree[next] == 0) pq.push(next);
		}
	}

	return 0;
}