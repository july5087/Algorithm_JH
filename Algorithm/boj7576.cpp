//토마토
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N;
int tomato[1001][1001]; //그래프 저장
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };
queue<pair<int, int>> q; //익은 토마토 저장

//1:익은 토마토, 0:익지 않은 토마토, -1:토마토가 들어있지 않은 칸
//하루 지나면 익은 토마토의 왼쪽, 오른쪽, 위, 아래칸의 토마토가 익음
void bfs() {
	//큐의 현재위치의 익은 토마토 꺼냄
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		//해당 위치 주변 확인
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			//지도 벗어나지 않고, 안 익은 토마토이면 큐에 삽입
			if (nx >= 0 && ny >= 0 && nx < N && ny < M && tomato[nx][ny] == 0) {
				tomato[nx][ny] = tomato[x][y] +  1; //날짜 증가
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main() {
	int result = 0;

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) //익은 토마토 큐에 삽입
				q.push(make_pair(i, j));
		}
	}
	bfs();

	//날짜 계산
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//안 익은 토마토 있는 경우
			if (tomato[i][j] == 0) {
				cout << "-1" << "\n";
				return 0;
			}
			//다 익은 경우 걸린 일수 최대값 찾음
			if (result < tomato[i][j]) {
				result = tomato[i][j];
			}
		}		
	}

	//result : 모든 토마토가 익은 마지막 날
	//1부터 시작했으므로  에 -1을 뺌
	cout << result-1 << "\n";
	return 0;
}