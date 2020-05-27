#include <iostream>
#include <queue>
using namespace std;

#define INF 1e9
#define MAX 20000

int main()
{
	int V, E, start;
	cin >> V >> E; //노드 갯수, 정점 갯수
	cin >> start; //시작점
	vector<pair<int, int> > arr[MAX];

	for (int i = 0; i<E; i++) {
		int from, to, val;
		cin >> from >> to >> val;
		arr[from].push_back({ to,val });
	}
	
	int dist[MAX]; //최단 거리 갱신할 배열
	fill(dist, dist + V + 1, INF); //무한대로 전체 초기화
	priority_queue<pair<int, int> > pq;

	pq.push({ 0,start }); //우선순위 큐에 시작점 push
	dist[start] = 0; //시작점의 최단거리 갱신 

	while (!pq.empty()) {
		//우선순위큐를 최소힙으로 변경하기 위해 -를 곱해서 큐에 넣고 꺼낼 때 다시 -를 곱해서 꺼냄
		//(또는 priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > pq;)
		int cost = -pq.top().first; //다음 방문할 점의 dist
		int cur = pq.top().second; //방문할 점의 번호

		pq.pop();

		for (int i = 0; i < arr[cur].size(); i++) {
			int next = arr[cur][i].first;
			int nextcost = arr[cur][i].second;

			if (dist[next] > dist[cur] + nextcost) {
				//현재 next에 저장된 dist보다 현재의 점을 거쳐서 가는 경우
				//더 짧으면 갱신하고 큐에 입력 
				dist[next] = dist[cur] + nextcost;
				pq.push({ -dist[next],next });
			}
		}
	}
	//결과 출력
	for (int i = 1; i <= V; i++) {
		cout << dist[i] << "\n";
	}
}