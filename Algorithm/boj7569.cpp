//�丶��2
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

#define MAX 101
int m, n, h;
int tomato[MAX][MAX][MAX];

int dx[] = { -1, 1, 0, 0, 0, 0 }; //��
int dy[] = { 0, 0, -1, 1, 0, 0 }; //��
int dz[] = { 0, 0, 0, 0, -1, 1 }; //��

struct info {
	int x, y, z;
};

queue<info> q; //���� �丶�� ������ ť

void bfs() {
	while (!q.empty()) {
		//info cur = q.front();
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();

		//6���� Ž��
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			//���� ��� ��� ����
			if (nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m) continue;
			//���� �丶��, �丶�� ������ ����
			if (tomato[nx][ny][nz] != 0) continue;

			//��¥ ����
			tomato[nx][ny][nz] = tomato[x][y][z] + 1;
			//ť�� ����
			q.push({ nx, ny, nz });
		}
	}
}

int main() {
	//1. �Է�
	int ripe = 0;
	scanf("%d %d %d", &m, &n, &h);
	for (int k = 0; k < h; k++) { //��
		for (int i = 0; i < n; i++) { //��
			for (int j = 0; j < m; j++) { //��
				scanf("%d", &tomato[k][i][j]);
				if (tomato[k][i][j] == 1) {
					//���� �丶�� ��ǥ ����
					q.push({ k, i, j });
				}
				//�� ���� �丶��
				if (tomato[k][i][j] == 0) ripe++;
			}
		}
	}
	//����� ������ ��� �丶�䰡 �;��ִ� ���¸� 0 ���
	if (ripe == 0) {
		printf("0\n");
		return 0;
	}

	//2. bfs Ž��
	bfs();

	//3. ��¥ ���
	int day = 0;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				//�丶�䰡 ��� ������ ���ϸ� -1 ���
				if (tomato[k][i][j] == 0) {
					printf("-1\n");
					return 0;
				}
				//�ִ� ��¥ ���
				if (tomato[k][i][j] > day)
					day = tomato[k][i][j];
			}
		}
	}

	//4. ���
	printf("%d\n", day - 1);
	return 0;
}