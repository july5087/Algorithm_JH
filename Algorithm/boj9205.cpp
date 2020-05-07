//맥주 마시면서 걸어가기
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int t, n; //n:편의점 수
bool visited[101];
vector<pair<int, int> > location; //모든 지점의 좌표
bool isHappy = false;

//맨하탄 거리
bool dist(int x1, int y1, int x2, int y2) {
	if (abs(x1 - x2) + abs(y1 - y2) <= 1000) return true;
	return false;
}

void dfs(int cur) {
	visited[cur] = true;

	//편의점, 도착지 탐색
	for (int i = 1; i <= n + 2; i++) {
		//방문 안했고 갈 수 있는 거리이면 재귀
		if (!visited[i] && dist(location[cur].first, location[cur].second, location[i].first, location[i].second)) {
			dfs(i);
		}
	}
}

void bfs() {
	queue<pair<int, int> > q;
	q.push({ location[0].first, location[0].second }); //출발지 좌표

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//도착지면 break
		if (x == location[n + 1].first && y == location[n + 1].second) {
			isHappy = true;
			break;
		}
		//편의점, 도착지 탐색
		for (int i = 1; i < n + 2; i++) {
			if (!visited[i] && dist(x, y, location[i].first, location[i].second)) {
				visited[i] = true;
				q.push({ location[i].first, location[i].second });
			}
		}
	}
}

int main() {
	cin >> t;

	while (t--) {
		//1. 입력
		cin >> n;

		//2. 초기화
		location.clear();
		memset(visited, false, sizeof(visited));
		isHappy = false;

		for (int i = 0; i < n + 2; i++) {
			int x, y;
			cin >> x >> y;
			location.push_back({ x, y });
		}

		//3. 탐색
		//dfs(0);
		bfs();

		//4. 출력
		//도착 지점 방문됐으면
		if (isHappy) cout << "happy\n";
		else cout << "sad\n";

		//if (visited[n + 1]) cout << "happy\n";
		//else cout << "sad\n";
	}
	return 0;
}