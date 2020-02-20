//���
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int T[16]; //�ɸ��� �Ⱓ
int P[16]; //�ݾ�
int maxMoney;

void dfs(int day, int money) {
	//�������:�����
	if (day >= N) {
		maxMoney = max(money, maxMoney);
		return;
	}
	//day�� ��� �����ϸ�(����� ������ ������) ����
	if (day + T[day] <= N) {
		dfs(day + T[day], money + P[day]);
	}
	//day�� ������� ����
	dfs(day + 1, money);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}

	dfs(0, 0);
	cout << maxMoney << "\n";
}