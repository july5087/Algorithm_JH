//���� ����Ŭ
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int N;
int numbers[1001]; //�ε���:from, ��:to
int visited[1001];

//����
void dfs(int from) {
	visited[from] = true;
	int to = numbers[from];
	if (!visited[to]) {
		dfs(to);
	}
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		//1. �ʱ�ȭ
		memset(visited, false, sizeof(visited));
		memset(numbers, 0, sizeof(numbers));
		int cnt = 0;

		//2. �Է�
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> numbers[i];
		}

		//3. dfsŽ��
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				dfs(i);
				cnt++;
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}