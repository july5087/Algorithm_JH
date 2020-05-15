//������2
#include <iostream>
using namespace std;

#define MAX 101
bool map[MAX][MAX];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };
int N, result;

void bfs(int x, int y) {
	//�� ������ ���
	if (!map[x][y]) {
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			//���� ������� üũ
			if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX) continue;
			//�� �������� �����¿쿡 �����̶� �´�� ���� ������ ����.
			if (map[nx][ny]) result++;
		}
	}
}

int main() {
	//1. �Է�
	cin >> N;

	while (N--) {
		int x, y;
		cin >> x >> y;

		//������ ����
		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				//�湮 ǥ��
				if (!map[i][j]) map[i][j] = true;
			}
		}
	}

	//2. Ž��
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			bfs(i, j);
		}
	}

	//3. ���
	cout << result << "\n";

	return 0;
}