//네트워크
#include <string>
#include <vector>

#define MAX 200+1
using namespace std;

bool visited[MAX];

void dfs(int start, vector<vector<int>> computers, int n) {
	visited[start] = true; //방문 표시
	for (int i = 0; i < n; i++) {
		//방문 안했고 연결되어 있으면 방문
		if (!visited[i] && computers[start][i])
			dfs(i, computers, n);
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	
	for (int i = 0; i < n ; i++) {
		if (!visited[i]) { //방문 안한 노드만 dfs 탐색(연결요소 + 1)
			dfs(i, computers, n);
			answer++;
		}
	}
	return answer;
}