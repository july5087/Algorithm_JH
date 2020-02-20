//부분수열의 합
#include <iostream>
using namespace std;

int N, S;
int sequence[20];
int result;

void subset(int idx, int sum) {
	sum += sequence[idx]; //해당 인덱스 숫자 더함
	//기저 사례 : 범위 초과
	if (idx >= N)
		return;
	if (sum == S)
		result++;
	subset(idx + 1, sum); //해당 인덱스 숫자 더한 경우
	subset(idx + 1, sum - sequence[idx]); //해당 인덱스 숫자 제외하고 더한 경우
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> sequence[i];
	
	subset(0, 0);
	
	cout << result << "\n";
}