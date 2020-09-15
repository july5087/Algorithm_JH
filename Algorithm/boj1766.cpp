//문제집
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100001

int main() {
	int N, M; //문제 수, 정보 수(정점, 간선)
	vector<int> graph[MAX]; //방향그래프
	int degree[MAX]; //진입차수
	priority_queue<int, vector<int>, greater<int>> pq; //1~N순 어려운 문제 쉬운 문제(작은수)부터 출력하기 위해 최소힙 pq 사용

	cin >> N >> M;

	//간선 입력
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		degree[b]++;
	}

	//진입차수가 0인 정점 큐에 삽입
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) pq.push(i);
	}

	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		cout << cur << " ";

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			degree[next]--; //큐에서 뺀 정점과 이어진 모든 간선 삭제

			//진입차수가 0인 새로운 정점 큐에 삽입
			if (degree[next] == 0) pq.push(next);
		}
	}

	return 0;
}