//N과 M(7)
//순열, 중복가능, 입력받은 수
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
vector<int> numbers;
vector<int> v;

void Print() {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
}

void DFS(int cnt) {
	if (cnt == M) {
		Print();
		return;
	}
	for (int i = 0; i < N; i++) {
		v.push_back(numbers[i]);
		DFS(cnt + 1);

		//초기화
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		numbers.push_back(number);
	}
	//입력받은 N개 숫자들 오름차순 정렬
	sort(numbers.begin(), numbers.end());

	DFS(0);
}