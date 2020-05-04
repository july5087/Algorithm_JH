//�̷� Ž��
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX 101 

int n, m;
int graph[MAX][MAX];
int check[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));

	//�湮 ǥ��(����)
	check[a][b] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//3. (n, m) �����ϸ� ���
		if (x == n - 1 && y == m - 1) {
			printf("%d", check[n - 1][m - 1]);
			return;
		}

		//4���� Ž��(�̵��� ĭ ã��)
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			//�̵��� ĭ�� �׷��� ����� ��� ����
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			//�̵��� ĭ�� ������ �� ���� ĭ�� ���, �湮�� ��� ����
			if (graph[nx][ny] == 0 || check[nx][ny] > 0) continue;

			//�湮 üũ
			check[nx][ny] = check[x][y] + 1;
			q.push(make_pair(nx, ny));
		}
	}
}

//(1, 1)���� ����� (N, M)�� ��ġ�� �̵��� �� ������ �ϴ� �ּ� ĭ ��
int main() {
	scanf("%d %d", &n, &m);

	//1. �׷��� �Է�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//�׷��� �Է��� ������� �־���
			scanf("%1d", &graph[i][j]);
		}
	}
	//2. bfs Ž��
	bfs(0, 0);

	return 0;
}