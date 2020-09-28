//����� �賶
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, K; //��ǰ ��, ��ƿ �� �ִ� ����
	int item[101][2];
	int dp[101][100001]; //i��°���� ���� ������ �� j�� �� �� ��ġ���� max

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> item[i][0] >> item[i][1]; //����, ��ġ
	}

	for (int i = 1; i <= N; i++) { //��ǰ ��
		int weight = item[i][0], value = item[i][1];

		for (int j = 1; j <= K; j++) { //����
			if (j < weight) dp[i][j] += dp[i - 1][j];
			//DP[i]][j - �ش� ���� ���� ����] + �ش� ���� ���� ��ġ, DP[i - 1][j] �� ū ��
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value);
		}
	}

	cout << dp[N][K];

	return 0;
}