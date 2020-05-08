//숨바꼭질
#include <iostream>
#include <queue>
using namespace std;

int N, K; //N:수빈이 위치, K:동생 위치
int sum;
int visited[100001] = { 0, };
int cnt = 0;

void bfs() {
	queue<int> q;
	q.push(N);
	visited[N] = 1;

	while (!q.empty()) {
		int subin = q.front();
		q.pop();
		//수빈이가 동생 위치인지 확인
		if (subin == K) {
			cnt = visited[subin] - 1;
			return;
		}
		//걷기(위치 + 1)
		if (subin + 1 >= 0 && subin + 1 <= 100000 && !visited[subin + 1]) {
			visited[subin + 1] = visited[subin] + 1;
			q.push(subin + 1);
		}
		//걷기(위치 - 1)
		if (subin - 1 >= 0 && subin - 1 <= 100000 && !visited[subin - 1]) {
			visited[subin - 1] = visited[subin] + 1;
			q.push(subin - 1);
		}
		//순간 이동(위치 * 2)
		if (subin * 2 >= 0 && subin * 2 <= 100000 && !visited[subin * 2]) {
			visited[subin * 2] = visited[subin] + 1;
			q.push(subin * 2);
		}
	}
}

int main() {
	//1. 입력
	cin >> N >> K;
	//2. 탐색
	bfs();
	//3. 출력
	cout << cnt << "\n";

	return 0;
}