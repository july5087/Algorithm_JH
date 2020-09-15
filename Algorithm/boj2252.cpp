//줄세우기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100001

int main() {
	int N, M; //학생 수, 비교 수(정점, 간선)
	int inDegree[MAX]; //진입 차수
	vector<int> a[MAX]; //방향 그래프
	queue<int> q; 
	
	cin >> N >> M;

	//간선 입력
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B; //A->B (A > B)
		a[A].push_back(B);
		inDegree[B]++;
	}
	
	//모든 간선 검사해 진입차수가 0인 노드 큐에 삽입
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	while(!q.empty()){
		int x = q.front();
		q.pop();
		cout << x << " "; //큐에서 뽑은 간선 출력

		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i]; //연결된 간선
			inDegree[y]--; //간선 삭제

			if (inDegree[y] == 0) q.push(y);
		}
	}
	cout << "\n";

	return 0;
}