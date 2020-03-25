//프린터
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;

	queue<pair<int, int>> que;
	priority_queue<int> que2;
	for (int i = 0; i < priorities.size(); i++) {
		que.push(make_pair(i, priorities[i]));
		que2.push(priorities[i]);
	}

	while (!que.empty()) {
		if (que.front().second == que2.top()) {
			if (que.front().first == location) {
				return answer + 1;
			}
			else {
				answer++;
				que.pop(); que2.pop();
			}
		}
		else {
			que.push(que.front());
			que.pop();
		}
	}
	return answer;
}
