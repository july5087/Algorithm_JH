#include <iostream>
#include <queue>
using namespace std;

#define INF 1e9
#define MAX 20000

int main()
{
	int V, E, start;
	cin >> V >> E; //��� ����, ���� ����
	cin >> start; //������
	vector<pair<int, int> > arr[MAX];

	for (int i = 0; i<E; i++) {
		int from, to, val;
		cin >> from >> to >> val;
		arr[from].push_back({ to,val });
	}
	
	int dist[MAX]; //�ִ� �Ÿ� ������ �迭
	fill(dist, dist + V + 1, INF); //���Ѵ�� ��ü �ʱ�ȭ
	priority_queue<pair<int, int> > pq;

	pq.push({ 0,start }); //�켱���� ť�� ������ push
	dist[start] = 0; //�������� �ִܰŸ� ���� 

	while (!pq.empty()) {
		//�켱����ť�� �ּ������� �����ϱ� ���� -�� ���ؼ� ť�� �ְ� ���� �� �ٽ� -�� ���ؼ� ����
		//(�Ǵ� priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > pq;)
		int cost = -pq.top().first; //���� �湮�� ���� dist
		int cur = pq.top().second; //�湮�� ���� ��ȣ

		pq.pop();

		for (int i = 0; i < arr[cur].size(); i++) {
			int next = arr[cur][i].first;
			int nextcost = arr[cur][i].second;

			if (dist[next] > dist[cur] + nextcost) {
				//���� next�� ����� dist���� ������ ���� ���ļ� ���� ���
				//�� ª���� �����ϰ� ť�� �Է� 
				dist[next] = dist[cur] + nextcost;
				pq.push({ -dist[next],next });
			}
		}
	}
	//��� ���
	for (int i = 1; i <= V; i++) {
		cout << dist[i] << "\n";
	}
}