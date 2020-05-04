//미로 탐색
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

	//방문 표시(길이)
	check[a][b] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//3. (n, m) 도착하면 출력
		if (x == n - 1 && y == m - 1) {
			printf("%d", check[n - 1][m - 1]);
			return;
		}

		//4방향 탐색(이동할 칸 찾음)
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			//이동할 칸이 그래프 벗어나는 경우 제외
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			//이동할 칸이 지나갈 수 없는 칸인 경우, 방문한 경우 제외
			if (graph[nx][ny] == 0 || check[nx][ny] > 0) continue;

			//방문 체크
			check[nx][ny] = check[x][y] + 1;
			q.push(make_pair(nx, ny));
		}
	}
}

//(1, 1)에서 출발해 (N, M)의 위치로 이동할 때 지나야 하는 최소 칸 수
int main() {
	scanf("%d %d", &n, &m);

	//1. 그래프 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//그래프 입력이 공백없이 주어짐
			scanf("%1d", &graph[i][j]);
		}
	}
	//2. bfs 탐색
	bfs(0, 0);

	return 0;
}