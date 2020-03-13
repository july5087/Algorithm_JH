#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;

bool mysort(string a, string b) {
	if (a.at(N) != b.at(N)) {
		return a.at(N) < b.at(N);   //N인덱스의 문자로 정렬
	}
	else {
		return a < b;   //사전순으로 정렬
	}
	//음수 또는 0이면 객체의 자리가 그대로 유지되며, 양수인 경우에는 두 객체의 자리가 바뀐다.
}

vector<string> solution(vector<string> strings, int n) {
	vector<string> answer;
	N = n;
	answer = strings;
	sort(answer.begin(), answer.end(), mysort);
	return answer;
}