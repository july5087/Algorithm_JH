#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[11];
int w[11][11]; //����ġ
int n, start_idx, ans = 987654321;

void dfs(int idx, int cnt, int sum) {
	if (cnt == n - 1) {
		//���������� -> ó������ ��� �ִ��� Ȯ��
		if (w[idx][start_idx]) {
			ans = min(ans, sum + w[idx][start_idx]);
			return;
		}
	}
	//���� ������ �������� ���� X
	for (int i = 0; i < n; i++) {
		if (w[idx][i] && !visited[i]) {
			visited[i] = true;
			dfs(i, cnt + 1, sum + w[idx][i]);
			visited[i] = false;
		}
	}
}
int main() {
	//1. �Է�
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}

	//2. ���� 0 ~ N ������� ������ dfs Ž��
	for (int i = 0; i < n; i++) {
		start_idx = i;
		visited[i] = true;
		dfs(i, 0, 0); //������
		visited[i] = false;
	}

	//3. ���
	cout << ans << endl;

	return 0;
}