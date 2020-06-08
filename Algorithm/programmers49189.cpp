//가장 먼 노드
//그래프
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 20001;
vector<int> graph[MAX];
int visited[MAX] = { 0, }; //길이
int max_dist = 0, max_cnt = 0;

void bfs(int start, int n) {
	queue<int> q;
	q.push(start);
	visited[start] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i<graph[cur].size(); i++) {
			if (visited[graph[cur][i]] == 0) {
				visited[graph[cur][i]] = visited[cur] + 1;
				q.push(i);
			}
			//거리 최댓값 갱신
			if (visited[graph[cur][i]] > max_dist) {
				max_dist = visited[graph[cur][i]];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		//최대길이면 카운트 증가
		if (max_dist == visited[i])
			max_cnt++;
	}
}

int solution(int n, vector<vector<int>> edge) {

	for (int i = 0; i<edge.size(); i++) {
		int u = edge[i][0];
		int v = edge[i][1];
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	memset(visited, 0, sizeof(visited));
	bfs(1, n);

	return max_cnt;
}