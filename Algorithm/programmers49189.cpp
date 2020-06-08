//���� �� ���
//�׷���
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 20001;
vector<int> graph[MAX];
int visited[MAX]; //����
int max_dist = -1;

//1�� ��忡�� ���� �ָ� ������ ����� ����
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

				//���� �ִ� ����
				if (visited[next] > max_dist)
					max_dist = visited[next];
			}
		}
	}
	int max_cnt = 0;
	for (int i = 1; i <= n; i++) {
		//�ִ� ���̿� ������ ī��Ʈ ����
		if (max_dist == visited[i])
			max_cnt++;
	}

	return max_cnt;
}