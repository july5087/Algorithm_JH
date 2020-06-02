//좋은 수열
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string answer;
bool flag;

//부분수열 같은지 확인
bool isGood(string s) {
	for (int len = 1; len <= s.length() / 2; len++) { //길이
		for (int start = 0; start + len < s.length(); start++) { //시작점
			string first = s.substr(start, len);
			string second = s.substr(start + len, len);
			if (first == second) return false;
		}
	}
	return true;
}

void dfs(string cur, int cnt) {
	//정답 나왔으면 종료
	if (flag) return;

	if (cnt == N) {
		flag = true;
		cout << cur << "\n";
		return;
	}

	for (int i = 1; i <= 3; i++) {
		//좋은 수열이면 숫자 넣고 다음 탐색
		if (isGood(cur + to_string(i))) {
			dfs(cur + to_string(i), cnt + 1);
		}
	}
}

//1,2,3으로 이뤄진 수열에서 부분수열이 동일한 것 있으면 나쁜 수열
//그렇지 않으면 좋은 수열
int main() {
	cin >> N;

	dfs("", 0);
}