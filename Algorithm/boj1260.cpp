#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int n, m, startNum; //���, ����, Ž������ ����ȣ
int arr[1001][1001];
bool visited[1001];
queue<int> q;

void dfs(int nodeNum) {
	//���� ��� �̿��� ����
	visited[nodeNum] = true;
	cout << nodeNum << " ";
	//���� ��� ã�� ����
	for (int i = 1; i <= n; i++) { //0�� ��� ���(����) => �ε��� 1����
		if (arr[nodeNum][i] == 1 && visited[i] == false) {
			dfs(i);
		}
	}
}

void bfs(int nodeNum) {
	//���� ��� �̿��� ����
	visited[nodeNum] = true;
	q.push(nodeNum);

	while (!q.empty()) {
		//Ž�� ���۳�� ť�� �ְ� ���
		int x = q.front();
		cout << x << " ";
		q.pop();
		//���� ��� �˻�
		for (int i = 1; i <= n; i++) {
			if (arr[x][i] == 1 && visited[i] == false) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> startNum;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = arr[y][x] = 1;
	}

	dfs(startNum);
	cout << "\n";

	memset(visited, false, sizeof(visited)); //�湮 Ȯ���ϴ� �迭 �ʱ�ȭ

	bfs(startNum);
}