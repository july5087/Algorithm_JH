//단지번호 붙이기
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 26

int n, complex;
int map[MAX][MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

vector<int> house;

void bfs(int x, int y) {
	queue<pair<int, int>> q; //집의 좌표 넣는 큐
	int cnt = 0;

	q.push(make_pair(x, y));
	map[x][y] += 1; //방문 표시(1이 아닌 수로)
	cnt++; //집 수 증가

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			//집이 있고 방문하지 않은 경우
			if (map[nx][ny] == 1) {
				map[nx][ny] += 1; //방문 표시(1이 아닌수로)
				q.push(make_pair(nx, ny));
				cnt++; //집 수 증가
			}
		}
	}
	house.push_back(cnt);
}

//첫 번째 줄에 총 단지수 출력
//두 번째 줄부터 각 단지내 집의 수를 오름차순으로 정렬해 한 줄씩 출력
int main() {

	//1. 입력
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	//2. bfs 탐색
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				bfs(i, j);
				complex++; //BFS 탐색할 때마다 단지 수 증가
			}
		}
	}

	//3. 단지 수 출력
	printf("%d\n", complex);

	//4. 단지 내 집 수 오름차순 출력
	sort(house.begin(), house.end());
	for (int i = 0; i < house.size(); i++) {
		printf("%d\n", house[i]);
	}
}