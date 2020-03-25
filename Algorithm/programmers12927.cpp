//�߱� ����
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

long long solution(int n, vector<int> works) {
	priority_queue<int> pq(works.begin(), works.end());
	long long answer = 0;

	for (int i = 0; i < n; i++) { //vector�� �ִ밪�� 1�� ����
		if (pq.top() > 0) {
			int work = pq.top();
			pq.pop();
			pq.push(work - 1);
		}
	}	
	while (!pq.empty()) {
		answer += pow((long long)pq.top(), 2);
		pq.pop();
	}
	return answer;
}