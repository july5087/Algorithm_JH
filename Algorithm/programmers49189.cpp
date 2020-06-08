//가장 먼 노드
//그래프
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 20001;
vector<int> graph[MAX];
int visited[MAX]; //길이
int max_dist = -1;

//1번 노드에서 가장 멀리 떨어진 노드의 갯수
int solution(int n, vector<vector<int>> edge) {

	for (int i = 0; i<edge.size(); i++) {
		int u = edge[i][0];
		int v = edge[i][1];
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	//BFS
	queue<int> q;
	int start = 1;
	memset(visited, -1, sizeof(visited));
	q.push(1);
	visited[1] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i<graph[cur].size(); i++) {
			int next = graph[cur][i];

			if (visited[next] == -1) {
				visited[next] = visited[cur] + 1;
				q.push(next);

				//길이 최댓값 갱신
				if (visited[next] > max_dist)
					max_dist = visited[next];
			}
		}
	}
	int max_cnt = 0;
	for (int i = 1; i <= n; i++) {
		//최대 길이와 같으면 카운트 증가
		if (max_dist == visited[i])
			max_cnt++;
	}

	return max_cnt;
}