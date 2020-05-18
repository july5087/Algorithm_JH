//구간 합 구하기4
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	int arr[100001];
	vector<int> v;
	
	//1. 입력
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	//2. 구간합 구하기
	int left = 0, right = 0, sum = 0;
	v.push_back(0);
	for (int i = 1; i <= N; i++) {
		sum += arr[i];
		v.push_back(sum);
	}

	//3. 출력
	for (int i = 0; i < M; i++) {
		int left, right;
		cin >> left >> right;
		cout << v[right] - v[left - 1] << "\n";
	}

	return 0;
}