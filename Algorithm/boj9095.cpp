//1, 2, 3 더하기
#include<iostream>
using namespace std;

int cnt;
int number;

void solution(int sum) {
	if (sum > number)
		return;
	if (sum == number)
		cnt++;
	solution(sum + 1);
	solution(sum + 2);
	solution(sum + 3);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> number;
		cnt = 0; //초기화 해줘야 함
		solution(0);
		cout << cnt << "\n";
	}
}