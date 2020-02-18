//모든 순열
#include<iostream>
using namespace std;

int N;
int permu[8];
bool visited[8];

void dfs(int cnt) {
	if (cnt == N) {
		for (int i = 0; i < N; i++) {
			cout << permu[i] << " ";
		}
		cout << "\n";
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			permu[cnt] = i;

			dfs(cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	dfs(0);
}