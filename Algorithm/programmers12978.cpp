//���
//Dijkstra
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9

//1������ ��� �ð� K ���Ϸ� �ɸ��� ���� ���� return
int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	vector<pair<int, int> > v[51];
	priority_queue<pair<int, int> >pq;

	//1. ���� ���� ����
	for (int i = 0; i<road.size(); i++) {
		int from = road[i][0];
		int to = road[i][1];
		int val = road[i][2];
		//������ �׷���
		v[from].push_back({ to, val });
		v[to].push_back({ from, val });
	}

	//2. �ִ밪���� �ʱ�ȭ
	int dist[51];
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}

	//3. ������ ����
	pq.push({ 1, 0 }); //������, dist
	dist[1] = 0; //�������� dist �ʱ�ȭ

	//3. �� �������� �ּ� �Ÿ� ã��
	while (!pq.empty()) {
		int cur = pq.top().first; //����
		int cost = -pq.top().second; //�Ÿ�
		pq.pop();

		for (int i = 0; i<v[cur].size(); i++) {
			int next = v[cur][i].first;
			int next_cost = v[cur][i].second;
			//�Ÿ� �ּҰ� ����
			if (dist[next] > dist[cur] + next_cost) {
				dist[next] = dist[cur] + next_cost;
				pq.push({ next, -dist[next] });
			}
		}
	}

	//3. �Ÿ� K ������ ���� �� count
	for (int i = 1; i <= N; i++) {
		if (dist[i] <= K) answer++;
	}

	return answer;
}