//N과 M(4)
//조합 오름차순으로 출력(중복 허용)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
int visited[8];
vector<int> v;

void Print() {
	sort(v.begin(), v.end()); //오름차순 정렬

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
}

void DFS(int idx, int cnt) {
	if (cnt == M) { //N:RANGE, M:COUNT
		Print();
		return;
	}
	for (int i = idx; i <= N; i++) {
		//if (visited[i] == true) continue;
		//visited[i] = true;
		v.push_back(i);
		DFS(i, cnt + 1);

		//초기화
		v.pop_back();
		//visited[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	DFS(1, 0);
}