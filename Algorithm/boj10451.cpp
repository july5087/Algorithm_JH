//순열 사이클
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int N;
int numbers[1001]; //인덱스:from, 값:to
int visited[1001];

//순열
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
		//1. 초기화
		memset(visited, false, sizeof(visited));
		memset(numbers, 0, sizeof(numbers));
		int cnt = 0;

		//2. 입력
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> numbers[i];
		}

		//3. dfs탐색
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