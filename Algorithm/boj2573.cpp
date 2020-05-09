//빙산
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 301

int N, M;
int map[MAX][MAX];
int c_map[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };

void bfs(int start_x, int start_y) {
	queue<pair<int, int>> q;
	q.push({ start_x, start_y });
	visited[start_x][start_y] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			//범위 벗어나는지 확인
			if (nx < 0 || nx >= N || ny < 0 || ny > M) continue;
			//방문 안했고 빙산이면
			if (!visited[nx][ny] && map[nx][ny] != 0) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

int melt(int x, int y) {
	int cnt = 0;
	for (int i = 0; i<4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (map[nx][ny] == 0) cnt++;
	}
	return cnt;
}

int main() {
	//1. 입력
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	//2. 탐색
	// (1. 빙산 갯수 셈 -> 2. 2개면 year 출력 -> 3. 아니면 빙산 녹음 -> 4. year 증가) 반복
	int year = 0;
	while (true) {
		//초기화
		int icebergCnt = 0;
		memset(visited, false, sizeof(visited));
		memset(c_map, 0, sizeof(c_map));

		//2-1. 처음 빙산 갯수 셈
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[i][j] && map[i][j] != 0) {
					bfs(i, j);
					icebergCnt++;
				}
			}
		}

		//2-2. 빙산 갯수 확인
		if (icebergCnt >= 2) break;
		if (icebergCnt == 0) {
			year = 0;
			break;
		}

		//2-3. 빙산 녹음
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] != 0) {
					c_map[i][j] = map[i][j] - melt(i, j);
					if (c_map[i][j] < 0) c_map[i][j] = 0;
				}
			}
		}
		//배열 복사(연차 계산 위해 배열 복사 필요)
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = c_map[i][j];
			}
		}

		//2-4. 햇수 증가
		year++;
	}

	//3. 출력
	cout << year << "\n";

	return 0;
}