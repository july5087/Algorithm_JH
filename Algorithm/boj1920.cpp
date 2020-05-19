//수 찾기
//이분탐색
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[100001];

int binary_search(int input) {
	int start = 0;
	int end = N - 1;
	int mid;

	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid] == input) return 1;
		else if (arr[mid] > input) end = mid - 1;
		else start = mid + 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//입력
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	//정렬
	sort(arr, arr + N);

	cin >> M;
	int start = 0, end = N - 1;
	int mid;
	for (int i = 0; i < M; i++) {
		int input;
		cin >> input;
		//이분탐색
		int result = binary_search(input);
		cout << result << "\n";
	}
	return 0;
}