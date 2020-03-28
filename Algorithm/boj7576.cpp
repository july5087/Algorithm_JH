//�丶��
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N;
int tomato[1001][1001]; //�׷��� ����
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };
queue<pair<int, int>> q; //���� �丶�� ����

//1:���� �丶��, 0:���� ���� �丶��, -1:�丶�䰡 ������� ���� ĭ
//�Ϸ� ������ ���� �丶���� ����, ������, ��, �Ʒ�ĭ�� �丶�䰡 ����
void bfs() {
	//ť�� ������ġ�� ���� �丶�� ����
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		//�ش� ��ġ �ֺ� Ȯ��
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			//���� ����� �ʰ�, �� ���� �丶���̸� ť�� ����
			if (nx >= 0 && ny >= 0 && nx < N && ny < M && tomato[nx][ny] == 0) {
				tomato[nx][ny] = tomato[x][y] +  1; //��¥ ����
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main() {
	int result = 0;

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) //���� �丶�� ť�� ����
				q.push(make_pair(i, j));
		}
	}
	bfs();

	//��¥ ���
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//�� ���� �丶�� �ִ� ���
			if (tomato[i][j] == 0) {
				cout << "-1" << "\n";
				return 0;
			}
			//�� ���� ��� �ɸ� �ϼ� �ִ밪 ã��
			if (result < tomato[i][j]) {
				result = tomato[i][j];
			}
		}		
	}

	//result : ��� �丶�䰡 ���� ������ ��
	//1���� ���������Ƿ�  �� -1�� ��
	cout << result-1 << "\n";
	return 0;
}