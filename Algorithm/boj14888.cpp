//������ �����ֱ�
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int number[12];
int p, s, m, d;
//�ִ񰪰� �ּڰ��� �׻� -10�ﺸ�� ũ�ų� ����, 10�ﺸ�� �۰ų� ���� ����� ������ �Է¸� �־�����.
int maxval = -1000000000;
int minval = 1000000000;

void dfs(int cnt, int plus, int sub, int mul, int div, int res) {
	if (cnt == N) {
		maxval = max(maxval, res);
		minval = min(minval, res);
		return;
	}
	if (plus < p)
		dfs(cnt + 1, plus + 1, sub, mul, div, res + number[cnt]);
	if (sub < s)
		dfs(cnt + 1, plus, sub + 1, mul, div, res - number[cnt]);
	if (mul < m)
		dfs(cnt + 1, plus, sub, mul + 1, div, res * number[cnt]);
	if (div < d)
		dfs(cnt + 1, plus, sub, mul, div + 1, res / number[cnt]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> number[i];
	}
	cin >> p >> s >> m >> d;
	dfs(1, 0, 0, 0, 0, number[0]);
	cout << maxval << "\n" << minval << "\n";
}