//���� ����Ŭ
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int T, N;
bool visited[1001];
int arr[1001][1001]; //��������Ʈ

void dfs(int from) {
	//from:�ε���
	for (int i = 1; i <= N; i++) {
		if (!visited[i] && arr[from][i] == 1) {
			visited[i] = true;
			dfs(i);
		}
	}
}

int main() {
	
	cin >> T;

	while (T--) {
		//1. �ʱ�ȭ
		int cnt = 0;

		//2. �Է�
		cin >> N;
		for (int i = 0; i < N; i++) {
			int to;
			cin >> to;
			arr[i][to] = 1;
		}
		//3. Ž��
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				dfs(i);
				cnt++;
			}
		}
	}
}