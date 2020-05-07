//���� ���ø鼭 �ɾ��
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int t, n; //n:������ ��
bool visited[101];
vector<pair<int, int> > location; //��� ������ ��ǥ
bool isHappy = false;

//����ź �Ÿ�
bool dist(int x1, int y1, int x2, int y2) {
	if (abs(x1 - x2) + abs(y1 - y2) <= 1000) return true;
	return false;
}

void dfs(int cur) {
	visited[cur] = true;

	//������, ������ Ž��
	for (int i = 1; i <= n + 2; i++) {
		//�湮 ���߰� �� �� �ִ� �Ÿ��̸� ���
		if (!visited[i] && dist(location[cur].first, location[cur].second, location[i].first, location[i].second)) {
			dfs(i);
		}
	}
}

void bfs() {
	queue<pair<int, int> > q;
	q.push({ location[0].first, location[0].second }); //����� ��ǥ

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//�������� break
		if (x == location[n + 1].first && y == location[n + 1].second) {
			isHappy = true;
			break;
		}
		//������, ������ Ž��
		for (int i = 1; i < n + 2; i++) {
			if (!visited[i] && dist(x, y, location[i].first, location[i].second)) {
				visited[i] = true;
				q.push({ location[i].first, location[i].second });
			}
		}
	}
}

int main() {
	cin >> t;

	while (t--) {
		//1. �Է�
		cin >> n;

		//2. �ʱ�ȭ
		location.clear();
		memset(visited, false, sizeof(visited));
		isHappy = false;

		for (int i = 0; i < n + 2; i++) {
			int x, y;
			cin >> x >> y;
			location.push_back({ x, y });
		}

		//3. Ž��
		//dfs(0);
		bfs();

		//4. ���
		//���� ���� �湮������
		if (isHappy) cout << "happy\n";
		else cout << "sad\n";

		//if (visited[n + 1]) cout << "happy\n";
		//else cout << "sad\n";
	}
	return 0;
}