//위상 정렬
#include <iostream>
#include <vector>
#include <queue>
#define MAX 10
using namespace std;

int N; //간선 갯수
int inDegree[MAX]; //각 노드의 진입 차수
vector<int> a[MAX]; //연결 그래프

void TopologySort() {
	//int result[MAX]; //위상정렬 결과
	queue<int> q;
	
	//진입 차수가 0인 노드를 큐에 삽입
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	//N개의 노드를 방문 => 모두 방문하면 위상 정렬 종료
	for (int i = 1; i <= N; i++) {
		//N개를 방문하기 전에 큐가 비면 사이클 발생 
		if (q.empty()) return;

		//큐에서 원소 꺼냄
		int x = q.front();
		q.pop();
		//result[i] = x;
		cout << x << " "; //결과 출력
		
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			inDegree[y]--; //연결된 간선 삭제

			// 3. 새롭게 진입차수가 0이 된 정점을 큐에 삽입 
			if (inDegree[y] == 0)
				q.push(y);
		}
	}
	/*for (int i = 1; i <= N; i++) {
		cout << result[i] << "\n";
	}*/
}

int main(void) {
	cin >> N; //간선 갯수 입력

	for (int i = 0; i < N; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		a[v1].push_back(v2); //v1 -> v2 간선 입력
		inDegree[v2]++; //v2 진입차수 증가
	}
	//위상 정렬
	TopologySort();
}