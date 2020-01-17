//N°ú M(2)
#include<iostream>
#include<vector>
#define MAX 9
using namespace std;

int N, M;
bool visited[MAX];
vector<int> v;

void Print() {
	for (int i = 0; i < M; i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
}

void DFS(int idx, int cnt) {
	if (cnt == M) {
		Print();
		return;
	}
	for (int i = idx; i <= N; i++) {
		if (visited[i] == true) continue;
		visited[i] = true;
		v.push_back(i);
		DFS(i, cnt + 1);

		v.pop_back();
		visited[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	DFS(1, 0);
}