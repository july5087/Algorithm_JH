//연구소3
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 51
int N, M;
int map[MAX][MAX];
int dist[MAX][MAX];
bool visited[10];
vector<pair<int, int>> v; //전체 바이러스
queue<pair<int, int>> q; //확산된 바이러스 좌표
int min_time = -1, empty_cnt = 0;
int answer = 987654321;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };

//바이러스 확산
void bfs() {
	int virus = 0, total_time = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//4방향 탐색
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			//전염은 빈칸(0(활성화)->1->2->...), 활성화 안된 바이러스(-1->0(활성화)->1->2...) 모두 일어남
			//방문하지 않았고 벽이 아니면 큐에 넣음(바이러스 확산)
			if (dist[nx][ny] == -1 && map[nx][ny] != 1) {
				//시간 더함
				dist[nx][ny] = dist[x][y] + 1;
				//확산된 바이러스 좌표 넣음
				q.push({ nx, ny });				

				//빈 칸일때만 시간 갱신(벽이나 바이러스는 X)
				if (map[nx][ny] == 0) {
					virus++;
					total_time = dist[nx][ny]; //dist 내 가장 큰 값(마지막 확산)이 저장됨
				}
			}
		}
	}
	//모든 공간 전염됐으면 최솟값 갱신(bfs 실행할 때마다 변경)
	if (virus == empty_cnt && answer > total_time)
		answer = total_time;
}

//전체 바이러스 중 M개 활성화
void dfs(int idx, int cnt) {
	if (cnt == M) {
		//초기화
		memset(dist, -1, sizeof(dist));

		for (int i = 0; i < v.size(); i++) {
			if (visited[i]) {
				q.push({ v[i].first, v[i].second }); //탐색 시작 좌표
				dist[v[i].first][v[i].second] = 0; //0 : 활성화
			}
		}
		//bfs 탐색
		bfs();
		return;
	}
	//조합
	for (int i = idx; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i + 1, cnt + 1); //재귀
			visited[i] = false;
		}
	}
}

int main() {
	//1. 입력
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j]; //0:빈 칸, 1:벽, 2:바이러스
			//바이러스 좌표 저장
			if (map[i][j] == 2) v.push_back({ i, j });
			//빈 공간 갯수 저장
			if (map[i][j] == 0) empty_cnt++;
		}
	}

	//2. 탐색
	dfs(0, 0);

	//3. 출력
	if (answer == 987654321) answer = -1;
	cout << answer << "\n";
}