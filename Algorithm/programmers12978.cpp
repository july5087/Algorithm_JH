//배달
//Dijkstra
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9

//1번에서 배달 시간 K 이하로 걸리는 마을 갯수 return
int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	vector<pair<int, int> > v[51];
	priority_queue<pair<int, int> >pq;

	//1. 간선 정보 저장
	for (int i = 0; i<road.size(); i++) {
		int from = road[i][0];
		int to = road[i][1];
		int val = road[i][2];
		//무방향 그래프
		v[from].push_back({ to, val });
		v[to].push_back({ from, val });
	}

	//2. 최대값으로 초기화
	int dist[51];
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}

	//3. 시작점 설정
	pq.push({ 1, 0 }); //시작점, dist
	dist[1] = 0; //시작점의 dist 초기화

	//3. 각 정점에서 최소 거리 찾음
	while (!pq.empty()) {
		int cur = pq.top().first; //정점
		int cost = -pq.top().second; //거리
		pq.pop();

		for (int i = 0; i<v[cur].size(); i++) {
			int next = v[cur][i].first;
			int next_cost = v[cur][i].second;
			//거리 최소값 갱신
			if (dist[next] > dist[cur] + next_cost) {
				dist[next] = dist[cur] + next_cost;
				pq.push({ next, -dist[next] });
			}
		}
	}

	//3. 거리 K 이하인 마을 수 count
	for (int i = 1; i <= N; i++) {
		if (dist[i] <= K) answer++;
	}

	return answer;
}