//N과 M(3)
#include<iostream>
#include<vector>
using namespace std;

int N, M;
int visited[7];
vector<int> v;

void Print() {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
}

void DFS(int cnt) {
	if (cnt == M) { //N : RANGE, M : COUNT
		Print();
		return;
	}
	for (int i = 1; i <= N; i++) {
		//if (visited[i] == true) continue;
		//visited[i] = true;
		v.push_back(i);
		DFS(cnt + 1);

		//초기화
		v.pop_back();
		//visited[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	DFS(0);
}