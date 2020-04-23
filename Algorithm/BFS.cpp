#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 9 + 1; //최대값 + 1

int N, M; //N:정점, M:간선
int K; //탐색 시작 노드

bool visit[MAX];  //방문 여부 검사
				  //int check[MAX]; //최단 거리 저장 시 1)최단 경로 찾기 2)간선 가중치=1 인 경우

vector<int> graph[MAX]; //인접 리스트

void bfs(int start) {
	queue<int> q; //경로 탐색 시 노드 저장할 큐
	q.push(start);
	visit[start] = true; //방문 표시
						 //check[start] = 0; //시작점까지 최단거리는 0

						 // 큐에 값이 있을 경우 계속 반복
						 //큐에 값이 있다. => 아직 방문하지 않은 노드가 존재 한다.
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		//printf("%d ", node); //동작(출력)

		for (int i = 0; i< graph[node].size(); i++) { //인접 리스트 안에 들은 노드 갯수만큼 반복
			int next = graph[node][i];
			if (!visit[next]) { // 방문하지 않았다면
								//if(check[next] == -1)
				q.push(next); // 큐에 넣음
				visit[next] = true;
				//check[next] = check[node] + 1;
			}
		}
	}
}

int main(void) {
	cin >> N >> M; //정점, 간선 수 입력
	cin >> K; //탐색 시작할 노드 입력

			  //인접리스트에 간선 저장
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	//bfs 탐색 실행
	bfs(K); // 노드 K부터 탐색 시작

	return 0;
}