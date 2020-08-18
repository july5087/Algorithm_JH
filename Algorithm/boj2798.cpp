//����
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m; //n:ī�尹��, m:ī�� 3�� �� �ѵ�
vector<int> input;
int result = 0;

//����
//idx:input �迭 �ε���, cnt:���� ���� ����, sum:���� ��
void dfs(int idx, int cnt, int sum) {
	if (cnt == 3 && sum <= m) {
		result = max(result, sum);
		return;
	}
	if (idx >= n || cnt > 3 || sum > m) return;

	dfs(idx + 1, cnt + 1, sum + input[idx]); //�ش� �ε��� ���� ����
	dfs(idx + 1, cnt, sum); //�ش� �ε��� ���� ������ ����
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