//평범한 배낭
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, K; //물품 수, 버틸 수 있는 무게
	int item[101][2];
	int dp[101][100001]; //i번째까지 담을 물건의 합 j라 할 떄 가치합의 max

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> item[i][0] >> item[i][1]; //무게, 가치
	}

	for (int i = 1; i <= N; i++) { //물품 수
		int weight = item[i][0], value = item[i][1];

		for (int j = 1; j <= K; j++) { //무게
			if (j < weight) dp[i][j] += dp[i - 1][j];
			//DP[i]][j - 해당 차례 물건 무게] + 해당 차례 물건 가치, DP[i - 1][j] 중 큰 것
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value);
		}
	}

	cout << dp[N][K];

	return 0;
}