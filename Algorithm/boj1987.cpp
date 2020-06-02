//알파벳
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
char arr[21][21];
bool alpha[26];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };
int answer = 1;

void dfs(int x, int y, int cnt) {

	answer = max(answer, cnt);

	for (int i = 0; i<4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		int nch = arr[nx][ny] - 'A';

		if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

		if (!alpha[nch]) {
			alpha[nch] = true;

			dfs(nx, ny, cnt + 1);

			alpha[nch] = false;
		}
	}
}

int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}
	//처음 위치 방문 표시
	int ch = arr[0][0] - 'A';
	alpha[ch] = true;

	dfs(0, 0, 1);

	cout << answer << "\n";

	return 0;
}