//���� ����
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 101
int N;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };
int cnt = 0, maxHeight = 0, result = 0;

void bfs(int a, int b, int limit) {
	queue<pair<int, int>> q;
	q.push({ a, b });
	visited[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		//4���� Ž��
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			//map ���� ������� üũ
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			//�湮���� �ʾҰ� ����� �ʴ��� Ȯ��
			if (!visited[nx][ny] && map[nx][ny] > limit) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	//1. �Է�
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			//�ִ���� ����
			if (maxHeight < map[i][j]) maxHeight = map[i][j];
		}
	}

	//2. Ž��
	for (int k = 1; k <= maxHeight; k++) {
		//�ʱ�ȭ
		memset(visited, false, sizeof(visited));
		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && map[i][j] > k) {
					bfs(i, j, k);
					cnt++;
				}
			}
		}
		//�ִ밪 ����
		if (result < cnt) result = cnt;
	}
	//�ƹ� ������ ���� ����� ���� �� ��ü�� ��������, �������� ������ 1
	if (result == 0) result = 1;
	
	cout << result << "\n";

	return 0;
}