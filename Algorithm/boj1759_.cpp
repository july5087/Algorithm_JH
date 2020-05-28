//��ȣ �����
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C, answer;
char alpha[16];
bool visited[16];
vector<char> v;

void dfs(int cnt) {
	if (cnt == L) {
		int mo = 0, ja = 0;
		bool flag = true;
		//��ȣ ����2 �˻� : �ּ� 2�� ����, 1�� ����
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') mo++;
			else ja++;
		}
		// 3. ���
		if (ja >= 2 && mo >= 1) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i];
			}
			cout << "\n";
		}
	}

	for (int i = 0; i < C; i++) {
		if (!visited[i]) {
			//��ȣ ����1 �˻�:��������
			//�� ���Ͱ� �ƴϰ� ���� ���ĺ��� �� ������ continue
			if(!v.empty() && alpha[i] < v[v.size()-1]) continue;

			visited[i] = true;
			v.push_back(alpha[i]);

			dfs(cnt + 1);

			visited[i] = false;
			v.pop_back();
		}
	}
}

int main() {
	//1. �Է�
	cin >> L >> C; //C�� ���ĺ� �� L�� ����� ��ȣ ����
	for (int i = 0; i < C; i++) {
		cin >> alpha[i];
	}
	//�������� ����
	sort(alpha, alpha + C);

	//2. Ž��
	dfs(0);

	return 0;
}