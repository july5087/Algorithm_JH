//유기농 배추
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int M, N, K; //가로, 세로, 배추 갯수
int lettuce;
int area[51][51];
bool visited[51][51];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
			if (!visited[nx][ny] && area[nx][ny] == 1) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

void dfs(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
		if (!visited[nx][ny] && area[nx][ny] == 1) {
			visited[nx][ny] = true;
			dfs(nx, ny);
		}
	}
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		cin >> M >> N >> K;
		//초기화
		memset(visited, false, sizeof(visited));
		memset(area, 0, sizeof(area));

		//입력
		for (int i = 0; i < K; i++) {
			int x, y; //M N
			cin >> x >> y;
			area[x][y] = 1;
		}
		//bfs 수행
		int worm = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				//배추가 있고 방문하지 않은 곳
				if (!visited[i][j] && area[i][j] == 1) {
					bfs(i, j);
					//dfs(i, j);
					worm++;
				}
			}
		}
		cout << worm << "\n";
	}

	return 0;
}