//수들의 합2
//투포인터 알고리즘
#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N, M, answer = 0;
	int arr[10001];

	//1. 입력
	cin >> N >> M;
	for (long long i = 0; i < N; i++) {
		cin >> arr[i];
	}

	//2. 투포인터
	long long left = 0, right = 0, sum = 0;
	 while(1) {
		 //1) 현재 부분합이 M 이상이면 left++
		 if (sum >= M){
	        sum -= arr[left];
			left++;
		 }
		 //2) 범위 벗어나면 break
		 else if (right == N) break;
		 //3) 그렇지 않으면 right++
		 else {
			 sum += arr[right];
			 right++;
		 }
		 //4) 현재 부분합이 M과 같으면 결과++
		 if (sum == M) answer++;
	 }

	//3. 출력
	cout << answer;
	return 0;
}
