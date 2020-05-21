#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[11];
int w[11][11]; //가중치
int n, start_idx, ans = 987654321;

void dfs(int idx, int cnt, int sum) {
	if (cnt == n - 1) {
		//마지막도시 -> 처음도시 경로 있는지 확인
		if (w[idx][start_idx]) {
			ans = min(ans, sum + w[idx][start_idx]);
			return;
		}
	}
	//아직 마지막 지점까지 도달 X
	for (int i = 0; i < n; i++) {
		if (w[idx][i] && !visited[i]) {
			visited[i] = true;
			dfs(i, cnt + 1, sum + w[idx][i]);
			visited[i] = false;
		}
	}
}
int main() {
	//1. 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}

	//2. 각각 0 ~ N 출발지로 설정후 dfs 탐색
	for (int i = 0; i < n; i++) {
		start_idx = i;
		visited[i] = true;
		dfs(i, 0, 0); //시작점
		visited[i] = false;
	}

	//3. 출력
	cout << ans << endl;

	return 0;
}