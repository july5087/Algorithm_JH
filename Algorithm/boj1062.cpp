//����ħ
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, T, answer = 0;
vector<string> v;

//���� �� �ִ� ���ĺ�
bool alpha[26]; 

//���� �� �ִ� �ܾ� ����
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

//����
void dfs(int idx, int cnt) {
	if (cnt == T - 5) {
		answer = max(answer, canReadNum());
	}
	//�ε��� ���� ���ϸ� �ð��ʰ�
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

	//a, n, t, i, c�� ������ ����ħ
	alpha['a' - 'a'] = true;
	alpha['n' - 'a'] = true;
	alpha['t' - 'a'] = true;
	alpha['i' - 'a'] = true;
	alpha['c' - 'a'] = true;

	//5�� �̸��̸� ���� �� �ִ� �ܾ� X
	if (T < 5) answer = 0;
	else dfs(0, 0);

	cout << answer << "\n";

	return 0;
}