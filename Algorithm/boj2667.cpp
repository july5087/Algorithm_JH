//������ȣ ���̱�
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
	queue<pair<int, int>> q; //���� ��ǥ �ִ� ť
	int cnt = 0;

	q.push(make_pair(x, y));
	map[x][y] += 1; //�湮 ǥ��(1�� �ƴ� ����)
	cnt++; //�� �� ����

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			//���� �ְ� �湮���� ���� ���
			if (map[nx][ny] == 1) {
				map[nx][ny] += 1; //�湮 ǥ��(1�� �ƴѼ���)
				q.push(make_pair(nx, ny));
				cnt++; //�� �� ����
			}
		}
	}
	house.push_back(cnt);
}

//ù ��° �ٿ� �� ������ ���
//�� ��° �ٺ��� �� ������ ���� ���� ������������ ������ �� �پ� ���
int main() {

	//1. �Է�
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	//2. bfs Ž��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				bfs(i, j);
				complex++; //BFS Ž���� ������ ���� �� ����
			}
		}
	}

	//3. ���� �� ���
	printf("%d\n", complex);

	//4. ���� �� �� �� �������� ���
	sort(house.begin(), house.end());
	for (int i = 0; i < house.size(); i++) {
		printf("%d\n", house[i]);
	}
}