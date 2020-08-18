//블랙잭
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m; //n:카드갯수, m:카드 3장 합 한도
vector<int> input;
int result = 0;

//조합
//idx:input 배열 인덱스, cnt:더한 원소 갯수, sum:원소 합
void dfs(int idx, int cnt, int sum) {
	if (cnt == 3 && sum <= m) {
		result = max(result, sum);
		return;
	}
	if (idx >= n || cnt > 3 || sum > m) return;

	dfs(idx + 1, cnt + 1, sum + input[idx]); //해당 인덱스 원소 더함
	dfs(idx + 1, cnt, sum); //해당 인덱스 원소 더하지 않음
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		input.push_back(num);
	}

	dfs(0, 0, 0);

	cout << result << "\n";

	return 0;
}