//���� ����
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string answer;
bool flag;

//�κм��� ������ Ȯ��
bool isGood(string s) {
	for (int len = 1; len <= s.length() / 2; len++) { //����
		for (int start = 0; start + len < s.length(); start++) { //������
			string first = s.substr(start, len);
			string second = s.substr(start + len, len);
			if (first == second) return false;
		}
	}
	return true;
}

void dfs(string cur, int cnt) {
	//���� �������� ����
	if (flag) return;

	if (cnt == N) {
		flag = true;
		cout << cur << "\n";
		return;
	}

	for (int i = 1; i <= 3; i++) {
		//���� �����̸� ���� �ְ� ���� Ž��
		if (isGood(cur + to_string(i))) {
			dfs(cur + to_string(i), cnt + 1);
		}
	}
}

//1,2,3���� �̷��� �������� �κм����� ������ �� ������ ���� ����
//�׷��� ������ ���� ����
int main() {
	cin >> N;

	dfs("", 0);
}