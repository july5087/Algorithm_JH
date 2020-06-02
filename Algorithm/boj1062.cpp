//가르침
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, T, answer = 0;
vector<string> v;

//읽을 수 있는 알파벳
bool alpha[26]; 

//읽을 수 있는 단어 갯수
int canReadNum() {
	int wordcnt = 0;

	for (int i = 0; i<v.size(); i++) {
		bool flag = true;

		for (int j = 0; j<v[i].size(); j++) {
			int ch = v[i][j] - 'a';
			if (!alpha[ch]) {
				flag = false;
				break;
			}
		}
		if (flag) wordcnt++;
	}
	return wordcnt;
}

//조합
void dfs(int idx, int cnt) {
	if (cnt == T - 5) {
		answer = max(answer, canReadNum());
	}
	//인덱스 설정 안하면 시간초과
	for (int i = idx; i < 26; i++) {
		if (!alpha[i]) {
			alpha[i] = true;
			dfs(i, cnt + 1);
			alpha[i] = false;
		}
	}
}

int main() {
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;
		v.push_back(word);
	}

	//a, n, t, i, c는 무조건 가르침
	alpha['a' - 'a'] = true;
	alpha['n' - 'a'] = true;
	alpha['t' - 'a'] = true;
	alpha['i' - 'a'] = true;
	alpha['c' - 'a'] = true;

	//5개 미만이면 읽을 수 있는 단어 X
	if (T < 5) answer = 0;
	else dfs(0, 0);

	cout << answer << "\n";

	return 0;
}