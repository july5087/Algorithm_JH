//이중우선순위큐
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	deque<int> dq;

	for (int i = 0; i<operations.size(); i++) {
		string line = operations[i];
		char op = line[0];

		if (op == 'I') {
			int number = stoi(line.substr(2, line.size() - 1));
			//숫자 입력
			dq.push_back(number);
			sort(dq.begin(), dq.end());
		}

		if (op == 'D') {
			int max_min = stoi(line.substr(2, line.size() - 1));
			//최대값 제거
			if (max_min == 1 && !dq.empty()) {
				dq.pop_back();
			}
			//최소값 제거
			else if (max_min == -1 && !dq.empty()) {
				dq.pop_front();
			}
		}
	}
	if (dq.empty()) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		int max_val = dq.front();
		int min_val = dq.back();

		answer.push_back(min_val);
		answer.push_back(max_val);
	}

	return answer;
}