//N°ú M(1)
#include<iostream>
#include<vector>
#define MAX 9
using namespace std;

int N, M;
bool visited[MAX];
vector<int> v;

void Print() {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
}

void DFS(int cnt) {
	if (cnt == M) {
		Print();
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i] == true) continue;
		visited[i] = true;
		v.push_back(i);
		DFS(cnt + 1);
		v.pop_back();
		visited[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	DFS(0);
}