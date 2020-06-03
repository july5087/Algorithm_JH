//�ҹ��� ĥ����
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };

char map[5][5]; //25�� Y, S
bool seven[25]; //7������ üũ

int ret = 0;

bool isConnected() { //���õ� 7���� �������ִ��� üũ(BFS)
	bool visited[25] = { false, }; //�������� üũ
	queue<int> q;
	int cnt = 0;

	int start;
	for (int i = 0; i < 25; i++) {
		if (seven[i]) {
			start = i;
			break;
		}
	}
	//������
	q.push(start);
	visited[start] = true;
	cnt++;

	while (!q.empty()) {
		int idx = q.front();
		int x = idx / 5;
		int y = idx % 5;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nidx = nx * 5 + ny;

			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
			//���� �湮 ���߰�, 7���� 1���̸�
			if (!visited[nidx] && seven[nidx]) {
				visited[nidx] = true;
				q.push(nidx);
				cnt++;
			}
		}
		if (cnt == 7) return true;
	}
	return false;
}

void dfs(int cnt, int idx) { //25�� �� 7�� ���� ����
	if (cnt == 7) {
		int cnt_s = 0; //�ټ��� ��
		for (int i = 0; i < 25; i++) {
			if (seven[i]) {
				int x = i / 5;
				int y = i % 5;
				if (map[x][y] == 'S') cnt_s++;
			}
		}
		//�ټ��� 4�� �̻��� ���� ���� ����Ǿ��ִ��� �˻�
		if (cnt_s >= 4) {
			if (isConnected() == true) ret++;
		}
		return;
	}

	for (int i = idx; i < 25; i++) {
		seven[i] = true;
		//���տ� 1�� �߰�, ���� �ε������� �˻�
		dfs(cnt + 1, i + 1);
		seven[i] = false;
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}
	dfs(0, 0);

	cout << ret << "\n";
}