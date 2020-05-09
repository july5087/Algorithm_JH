//����
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 301

int N, M;
int map[MAX][MAX];
int c_map[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };

void bfs(int start_x, int start_y) {
	queue<pair<int, int>> q;
	q.push({ start_x, start_y });
	visited[start_x][start_y] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			//���� ������� Ȯ��
			if (nx < 0 || nx >= N || ny < 0 || ny > M) continue;
			//�湮 ���߰� �����̸�
			if (!visited[nx][ny] && map[nx][ny] != 0) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

int melt(int x, int y) {
	int cnt = 0;
	for (int i = 0; i<4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (map[nx][ny] == 0) cnt++;
	}
	return cnt;
}

int main() {
	//1. �Է�
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	//2. Ž��
	// (1. ���� ���� �� -> 2. 2���� year ��� -> 3. �ƴϸ� ���� ���� -> 4. year ����) �ݺ�
	int year = 0;
	while (true) {
		//�ʱ�ȭ
		int icebergCnt = 0;
		memset(visited, false, sizeof(visited));
		memset(c_map, 0, sizeof(c_map));

		//2-1. ó�� ���� ���� ��
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[i][j] && map[i][j] != 0) {
					bfs(i, j);
					icebergCnt++;
				}
			}
		}

		//2-2. ���� ���� Ȯ��
		if (icebergCnt >= 2) break;
		if (icebergCnt == 0) {
			year = 0;
			break;
		}

		//2-3. ���� ����
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] != 0) {
					c_map[i][j] = map[i][j] - melt(i, j);
					if (c_map[i][j] < 0) c_map[i][j] = 0;
				}
			}
		}
		//�迭 ����(���� ��� ���� �迭 ���� �ʿ�)
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = c_map[i][j];
			}
		}

		//2-4. �޼� ����
		year++;
	}

	//3. ���
	cout << year << "\n";

	return 0;
}