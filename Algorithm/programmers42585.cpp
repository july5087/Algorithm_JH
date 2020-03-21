#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string arrangement) {
	int answer = 0;
	stack<char> pipe;

	for (int i = 0; i<arrangement.size(); i++) {
		if (arrangement[i] == '(') {
			pipe.push(arrangement[i]);
		}
		else { // ')'
			pipe.pop();
			if (arrangement[i - 1] == '(') //레이저
				answer += pipe.size();
			else //쇠막대기
				answer += 1;
		}
	}
	return answer;
}