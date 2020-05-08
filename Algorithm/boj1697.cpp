//���ٲ���
#include <iostream>
#include <queue>
using namespace std;

int N, K; //N:������ ��ġ, K:���� ��ġ
int sum;
int visited[100001] = { 0, };
int cnt = 0;

void bfs() {
	queue<int> q;
	q.push(N);
	visited[N] = 1;

	while (!q.empty()) {
		int subin = q.front();
		q.pop();
		//�����̰� ���� ��ġ���� Ȯ��
		if (subin == K) {
			cnt = visited[subin] - 1;
			return;
		}
		//�ȱ�(��ġ + 1)
		if (subin + 1 >= 0 && subin + 1 <= 100000 && !visited[subin + 1]) {
			visited[subin + 1] = visited[subin] + 1;
			q.push(subin + 1);
		}
		//�ȱ�(��ġ - 1)
		if (subin - 1 >= 0 && subin - 1 <= 100000 && !visited[subin - 1]) {
			visited[subin - 1] = visited[subin] + 1;
			q.push(subin - 1);
		}
		//���� �̵�(��ġ * 2)
		if (subin * 2 >= 0 && subin * 2 <= 100000 && !visited[subin * 2]) {
			visited[subin * 2] = visited[subin] + 1;
			q.push(subin * 2);
		}
	}
}

int main() {
	//1. �Է�
	cin >> N >> K;
	//2. Ž��
	bfs();
	//3. ���
	cout << cnt << "\n";

	return 0;
}