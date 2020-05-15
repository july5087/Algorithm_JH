//색종이2
#include <iostream>
using namespace std;

#define MAX 101
bool map[MAX][MAX];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };
int N, result;

void bfs(int x, int y) {
	//빈 공간인 경우
	if (!map[x][y]) {
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			//범위 벗어났는지 체크
			if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX) continue;
			//빈 공간에서 상하좌우에 색종이랑 맞닿는 면의 개수를 센다.
			if (map[nx][ny]) result++;
		}
	}
}

int main() {
	//1. 입력
	cin >> N;

	while (N--) {
		int x, y;
		cin >> x >> y;

		//색종이 붙임
		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				//방문 표시
				if (!map[i][j]) map[i][j] = true;
			}
		}
	}

	//2. 탐색
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			bfs(i, j);
		}
	}

	//3. 출력
	cout << result << "\n";

	return 0;
}