//안전 영역
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 101
int N;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };
int cnt = 0, maxHeight = 0, result = 0;

void bfs(int a, int b, int limit) {
	queue<pair<int, int>> q;
	q.push({ a, b });
	visited[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		//4방향 탐색
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			//map 영역 벗어나는지 체크
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			//방문하지 않았고 잠기지 않는지 확인
			if (!visited[nx][ny] && map[nx][ny] > limit) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	//1. 입력
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			//최대높이 저장
			if (maxHeight < map[i][j]) maxHeight = map[i][j];
		}
	}

	//2. 탐색
	for (int k = 1; k <= maxHeight; k++) {
		//초기화
		memset(visited, false, sizeof(visited));
		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && map[i][j] > k) {
					bfs(i, j, k);
					cnt++;
				}
			}
		}
		//최대값 저장
		if (result < cnt) result = cnt;
	}
	//아무 지역도 물에 잠기지 않을 때 전체가 안전영역, 안전영역 갯수는 1
	if (result == 0) result = 1;
	
	cout << result << "\n";

	return 0;
}