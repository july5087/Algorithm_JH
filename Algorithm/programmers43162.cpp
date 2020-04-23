//��Ʈ��ũ
#include <string>
#include <vector>

#define MAX 200+1
using namespace std;

bool visited[MAX];

void dfs(int start, vector<vector<int>> computers, int n) {
	visited[start] = true; //�湮 ǥ��
	for (int i = 0; i < n; i++) {
		//�湮 ���߰� ����Ǿ� ������ �湮
		if (!visited[i] && computers[start][i])
			dfs(i, computers, n);
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	
	for (int i = 0; i < n ; i++) {
		if (!visited[i]) { //�湮 ���� ��常 dfs Ž��(������ + 1)
			dfs(i, computers, n);
			answer++;
		}
	}
	return answer;
}