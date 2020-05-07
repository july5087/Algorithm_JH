//�̼� ���
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m; //n:��ü ��� ��, m:���� ��
int a, b; //�̼� ����� 2��
int relation[101][101];
int visited[101] = { 0, };
int cnt = 0;

void bfs(int start) {
	queue<int> q;

	visited[start] = 1;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 1; i < n; i++) {
			if (!visited[i] && relation[cur][i] == 1) {
				visited[i] = visited[cur] + 1;
				q.push(i);
			}
		}
	}
}

int main() {
	cin >> n;
	cin >> a >> b;
	cin >> m;

	//x y:�θ� �ڽ�
	for (int i = 0; i < m; i++) {
		//1. �Է�
		int x, y;
		cin >> x >> y;
		relation[x][y] = 1;
		relation[y][x] = 1;
	}

	bfs(a);
	
	if (visited[b] == 0) cout << "0\n";
	else cout << visited[b] << "\n";

	return 0;
}