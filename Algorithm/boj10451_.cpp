//순열 사이클
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int T, N;
bool visited[1001];
int arr[1001][1001]; //인접리스트

void dfs(int from) {
	//from:인덱스
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
		//1. 초기화
		int cnt = 0;

		//2. 입력
		cin >> N;
		for (int i = 0; i < N; i++) {
			int to;
			cin >> to;
			arr[i][to] = 1;
		}
		//3. 탐색
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				dfs(i);
				cnt++;
			}
		}
	}
}