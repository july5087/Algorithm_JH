//섬 연결하기
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_INT 101

int p[MAX_INT];

//루트 노드 찾음
int Find(int x) {
	if (x == p[x])
		return x;
	else
		return p[x] = Find(p[x]);
}

bool cmp(vector<int> &a, vector<int> &b) {
	//간선 가중치
	return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	//1. Disjoint set 초기화
	for (int i = 0; i < n; i++) {
		p[i] = i;
	}
	//2. 가중치 기준 오름차순 정렬
	sort(costs.begin(), costs.end(), cmp);

	//3. 모든 간선 검사
	for (int i = 0; i < costs.size(); i++) {
		int start = costs[i][0]; //시작 노드의 루트노드
		int end = costs[i][1]; //끝 노드의 루트노드
		int cost = costs[i][2];
		//4. start와 end가 아직 연결되지 않았다면(루트 노드가 같지 않으면)
		if (start != end) {
			//1) start의 부모노드를 end로 설정
			p[start] = end;
			//2) 간선의 가중치를 결과에 더해줌
			answer += cost;
		}
	}
	return answer;
}