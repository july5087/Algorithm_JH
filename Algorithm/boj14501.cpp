//퇴사
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int T[16]; //걸리는 기간
int P[16]; //금액
int maxMoney;

void dfs(int day, int money) {
	//기저사례:퇴사일
	if (day >= N) {
		maxMoney = max(money, maxMoney);
		return;
	}
	//day의 상담 가능하면(퇴사일 이전에 끝나면) 진행
	if (day + T[day] <= N) {
		dfs(day + T[day], money + P[day]);
	}
	//day의 상담하지 않음
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