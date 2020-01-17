//외판원 순회2
//순열 이용
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int W[11][11];
int minValue = 987654321;
vector<int> temp;
bool visited[11];

//거리 비용 합 구함
int Calculate() {
	int costSum = 0;
	int startCity = temp[0];
	int lastCity = temp[N - 1];

	for (int i = 0; i < N - 1; i++) {
		//
		//cout << W[temp[i]][temp[i + 1]] << " ";
		//
		if (!(W[lastCity][startCity]) || !(W[temp[i]][temp[i + 1]])) {
			return -1;
		}
		costSum += W[temp[i]][temp[i + 1]];
	}
	//
	//cout << W[lastCity][startCity] << " ";
	//

	costSum += W[lastCity][startCity];

	//
	//cout << "sum="  << costSum << "\n";
	//
	return costSum;
}

void DFS(int cnt) {
	if (cnt == N) {
		/*if (Calculate() == -1)
		cout << "건너뜀 ";*/
		if (Calculate() != -1) minValue = min(minValue, Calculate());

		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			temp.push_back(i);

			DFS(cnt + 1);

			temp.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int cost;
			cin >> cost;
			W[i][j] = cost;
		}
	}

	DFS(0);

	//cout << "\nmin:" << minValue << "\n";
	cout << minValue << "\n";
}