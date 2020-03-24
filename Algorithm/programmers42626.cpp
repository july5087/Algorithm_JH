//더 맵게
#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	int newsco = 0;
	priority_queue<int, vector<int>, greater<int> > newscoville;

	for (int i = 0; i<scoville.size(); i++) {
		newscoville.push(scoville[i]);
	}

	while (newscoville.top() < K) {
		if (newscoville.size() == 1) //더이상 바꿀 수 없으면 -1 리턴
			return -1;
		int front = newscoville.top();
		newscoville.pop();
		newsco = front + (newscoville.top() * 2);
		newscoville.pop();
		newscoville.push(newsco);
		answer++;
	}
	return answer;
}