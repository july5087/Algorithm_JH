#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int n, m, startNum; //노드, 간선, 탐색시작 노드번호
int arr[1001][1001];
bool visited[1001];
queue<int> q;

void dfs(int nodeNum) {
	//인접 행렬 이용한 구현
	visited[nodeNum] = true;
	cout << nodeNum << " ";
	//다음 노드 찾는 과정
	for (int i = 1; i <= n; i++) { //0은 모두 비움(주의) => 인덱스 1부터
		if (arr[nodeNum][i] == 1 && visited[i] == false) {
			dfs(i);
		}
	}
}

void bfs(int nodeNum) {
	//인접 행렬 이용한 구현
	visited[nodeNum] = true;
	q.push(nodeNum);

	while (!q.empty()) {
		//탐색 시작노드 큐에 넣고 출력
		int x = q.front();
		cout << x << " ";
		q.pop();
		//다음 노드 검색
		for (int i = 1; i <= n; i++) {
			if (arr[x][i] == 1 && visited[i] == false) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> startNum;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = arr[y][x] = 1;
	}

	dfs(startNum);
	cout << "\n";

	memset(visited, false, sizeof(visited)); //방문 확인하는 배열 초기화

	bfs(startNum);
}