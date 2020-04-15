//라면공장
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<int> pq;

	for (int day = 0, j = 0; day < k; day++) {
		//공급 가능한 날인지 확인
		if (day == dates[j]) {
			//우선순위에 밀가루 수량 추가
			pq.push(supplies[j]);
			j++;
		}
		//수량 모자라면 공급 받음
		if (!stock) {
			stock += pq.top();
			pq.pop();
			answer++;
		}
		//수량 감소
		stock--;
	}
	return answer;
}