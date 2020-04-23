//연결 요소의 개수
#include <iostream>
#include <vector>
#include <queue>

#define MAX 1000+1
using namespace std;

vector<int> graph[MAX]; //연결리스트
bool visited[MAX]; //방문 여부

void dfs(int node) {
	visited[node] = true; //방문 표시
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if(!visited[next])
			dfs(next);
	}
}

void bfs(int node) {
	queue<int> q;
	q.push(node);
	visited[node] = true; //방문 표시
	
	while (!q.empty()) {
		//현재 노드 꺼냄
		int curr = q.front();
		q.pop();

		//현재 노드와 연결된 다음 노드 탐색
		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i];
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 0; //연결 요소 개수
	int N, M; // N:정점, M:간선
	cin >> N >> M; //정점, 간선
	
	int a, b; //시작 노드, 끝 노드

	//인접리스트에 간선 저장
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	//각 정점에서 시작(방문 시 연결된 그래프)
	//memset(visited, false, sizeof(visited));
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) { //방문 안한 노드(연결되지 않은)만 탐색
			//한 번 탐색할 때마다 연결된 노드는 visited 표시
			//bfs(i);
			dfs(i);
			cnt++; 
		}
	}
	cout << cnt;
	return 0;
}