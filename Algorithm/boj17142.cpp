//������3
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 51
int N, M;
int map[MAX][MAX];
int dist[MAX][MAX];
bool visited[10];
vector<pair<int, int>> v; //��ü ���̷���
queue<pair<int, int>> q; //Ȯ��� ���̷��� ��ǥ
int min_time = -1, empty_cnt = 0;
int answer = 987654321;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };

//���̷��� Ȯ��
void bfs() {
	int virus = 0, total_time = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//4���� Ž��
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			//������ ��ĭ(0(Ȱ��ȭ)->1->2->...), Ȱ��ȭ �ȵ� ���̷���(-1->0(Ȱ��ȭ)->1->2...) ��� �Ͼ
			//�湮���� �ʾҰ� ���� �ƴϸ� ť�� ����(���̷��� Ȯ��)
			if (dist[nx][ny] == -1 && map[nx][ny] != 1) {
				//�ð� ����
				dist[nx][ny] = dist[x][y] + 1;
				//Ȯ��� ���̷��� ��ǥ ����
				q.push({ nx, ny });				

				//�� ĭ�϶��� �ð� ����(���̳� ���̷����� X)
				if (map[nx][ny] == 0) {
					virus++;
					total_time = dist[nx][ny]; //dist �� ���� ū ��(������ Ȯ��)�� �����
				}
			}
		}
	}
	//��� ���� ���������� �ּڰ� ����(bfs ������ ������ ����)
	if (virus == empty_cnt && answer > total_time)
		answer = total_time;
}

//��ü ���̷��� �� M�� Ȱ��ȭ
void dfs(int idx, int cnt) {
	if (cnt == M) {
		//�ʱ�ȭ
		memset(dist, -1, sizeof(dist));

		for (int i = 0; i < v.size(); i++) {
			if (visited[i]) {
				q.push({ v[i].first, v[i].second }); //Ž�� ���� ��ǥ
				dist[v[i].first][v[i].second] = 0; //0 : Ȱ��ȭ
			}
		}
		//bfs Ž��
		bfs();
		return;
	}
	//����
	for (int i = idx; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i + 1, cnt + 1); //���
			visited[i] = false;
		}
	}
}

int main() {
	//1. �Է�
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j]; //0:�� ĭ, 1:��, 2:���̷���
			//���̷��� ��ǥ ����
			if (map[i][j] == 2) v.push_back({ i, j });
			//�� ���� ���� ����
			if (map[i][j] == 0) empty_cnt++;
		}
	}

	//2. Ž��
	dfs(0, 0);

	//3. ���
	if (answer == 987654321) answer = -1;
	cout << answer << "\n";
}