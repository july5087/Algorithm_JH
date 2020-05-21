//차이를 최대로
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, answer;
vector<int> v;
int numbers[9];
bool visited[9];

//차이 합 계산
int Calculate() {
	int diffSum = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		diffSum += abs(v[i + 1] - v[i]);
	}
	return diffSum;
}

//순열
void dfs(int cnt) {
	if (cnt == N) {
		//차이의 합 구하기
		answer = max(answer, Calculate());
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(numbers[i]);

			dfs(cnt + 1);
			
			//초기화
			visited[i] = false;
			v.pop_back();

		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}

	dfs(0);

	cout << answer << "\n";
}