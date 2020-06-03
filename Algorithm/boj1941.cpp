//소문난 칠공주
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };

char map[5][5]; //25명 Y, S
bool seven[25]; //7명인지 체크

int ret = 0;

bool isConnected() { //선택된 7명이 인접해있는지 체크(BFS)
	bool visited[25] = { false, }; //인접한지 체크
	queue<int> q;
	int cnt = 0;

	int start;
	for (int i = 0; i < 25; i++) {
		if (seven[i]) {
			start = i;
			break;
		}
	}
	//시작점
	q.push(start);
	visited[start] = true;
	cnt++;

	while (!q.empty()) {
		int idx = q.front();
		int x = idx / 5;
		int y = idx % 5;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nidx = nx * 5 + ny;

			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
			//아직 방문 안했고, 7명중 1명이면
			if (!visited[nidx] && seven[nidx]) {
				visited[nidx] = true;
				q.push(nidx);
				cnt++;
			}
		}
		if (cnt == 7) return true;
	}
	return false;
}

void dfs(int cnt, int idx) { //25명 중 7명 조합 선택
	if (cnt == 7) {
		int cnt_s = 0; //다솜파 수
		for (int i = 0; i < 25; i++) {
			if (seven[i]) {
				int x = i / 5;
				int y = i % 5;
				if (map[x][y] == 'S') cnt_s++;
			}
		}
		//다솜파 4명 이상일 때만 서로 연결되어있는지 검사
		if (cnt_s >= 4) {
			if (isConnected() == true) ret++;
		}
		return;
	}

	for (int i = idx; i < 25; i++) {
		seven[i] = true;
		//조합에 1명 추가, 다음 인덱스부터 검사
		dfs(cnt + 1, i + 1);
		seven[i] = false;
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}
	dfs(0, 0);

	cout << ret << "\n";
}