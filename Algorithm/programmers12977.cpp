#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

vector<int> input;
bool visitied[50];
int answer;

bool isPrime(int sum) {
	for (int k = 2; k <= sqrt(sum); k++) {
		if (sum % k == 0)
			return false;
	}
	return true;
}

void DFS(int idx, int cnt, int sum) {
	if (cnt == 3) {
		if (isPrime(sum))
			answer++;
		return;
	}
	for (int i = idx; i < input.size(); i++) {
		if (visitied[i] == true) continue;
		visitied[i] = true;
		sum += input[i];
		DFS(i, cnt + 1, sum);
		//ÃÊ±âÈ­
		visitied[i] = false;
		sum -= input[i];
	}
}

int solution(vector<int> nums) {
	input = nums;
	DFS(0, 0, 0);
	return answer;
}