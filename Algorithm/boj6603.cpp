//로또
//조합 이용
#include<iostream>
#include<vector>
using namespace std;
#define LOTTO_NUMBER_COUNT 6

int N;
vector<int> output;
bool visited[13];

void DFS(int idx, int cnt, vector<int> v) {
	if (cnt == LOTTO_NUMBER_COUNT) {
		for (int i = 0; i < output.size(); i++) {
			cout << output[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = idx; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			output.push_back(v[i]);
			DFS(i, cnt + 1, v);

			//초기화
			visited[i] = false;
			output.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while(1){
		cin >> N;
		if (N == 0)  break;

		vector<int> input; //테스트케이스마다 벡터 초기화

		for (int i = 0; i < N; i++) {
			int number;
			cin >> number;
			input.push_back(number);
		}
		DFS(0, 0, input);
		cout << "\n";
	}
}