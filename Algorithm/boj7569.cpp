//토마토2
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

#define MAX 101
int m, n, h;
int tomato[MAX][MAX][MAX];

int dx[] = { -1, 1, 0, 0, 0, 0 }; //면
int dy[] = { 0, 0, -1, 1, 0, 0 }; //행
int dz[] = { 0, 0, 0, 0, -1, 1 }; //열

struct info {
	int x, y, z;
};

queue<info> q; //익은 토마토 저장할 큐

void bfs() {
	while (!q.empty()) {
		//info cur = q.front();
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();

		//6방향 탐색
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			//공간 벗어난 경우 제외
			if (nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m) continue;
			//익은 토마토, 토마토 없으면 제외
			if (tomato[nx][ny][nz] != 0) continue;

			//날짜 더함
			tomato[nx][ny][nz] = tomato[x][y][z] + 1;
			//큐에 넣음
			q.push({ nx, ny, nz });
		}
	}
}

int main() {
	//1. 입력
	int ripe = 0;
	scanf("%d %d %d", &m, &n, &h);
	for (int k = 0; k < h; k++) { //면
		for (int i = 0; i < n; i++) { //행
			for (int j = 0; j < m; j++) { //열
				scanf("%d", &tomato[k][i][j]);
				if (tomato[k][i][j] == 1) {
					//익은 토마토 좌표 저장
					q.push({ k, i, j });
				}
				//안 익은 토마토
				if (tomato[k][i][j] == 0) ripe++;
			}
		}
	}
	//저장될 때부터 모든 토마토가 익어있는 상태면 0 출력
	if (ripe == 0) {
		printf("0\n");
		return 0;
	}

	//2. bfs 탐색
	bfs();

	//3. 날짜 계산
	int day = 0;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				//토마토가 모두 익지는 못하면 -1 출력
				if (tomato[k][i][j] == 0) {
					printf("-1\n");
					return 0;
				}
				//최대 날짜 계산
				if (tomato[k][i][j] > day)
					day = tomato[k][i][j];
			}
		}
	}

	//4. 출력
	printf("%d\n", day - 1);
	return 0;
}