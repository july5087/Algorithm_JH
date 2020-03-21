//기능개발
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	deque<int> temp;
	int front;
	int count;

	for (int i = 0; i<progresses.size(); i++) {
		int remain = 100 - progresses[i];
		int day = ceil((double)remain / (double)speeds[i]);
		temp.push_back(day);
	}

	front = temp[0]; //맨 앞(front) 기능 작업일
	for (int j = 0; j<temp.size(); j++) {
		if (front < temp[j]) { //다음 작업이 더 오래 걸리면 배포
			answer.push_back(count);
			count = 1; //count 초기화
			front = temp[j]; //front 초기화
		}
		else { //더 적게 걸리면 count++
			count++;
		}
		if (j == temp.size() - 1) { //마지막 기능일 때 그 동안의 count 값을 push
			answer.push_back(count);
		}
	}
	return answer;
}