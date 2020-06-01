//시리얼 번호
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//1. 시리얼번호 짧은것 먼저
//2. 만약 서로 길이가 같다면, A의 모든 자리수의 합과 B의 모든 자리수 합 비교해 작은 것이 먼저옴(숫자인 것만 더함)
//3. 만약 1,2번으로 비교 안되면 사전순 비교(숫자가 알파벳보다 사전순으로 작다)

bool cmp(string a, string b) {
	//길이 다르면 길이순 오름차순 정렬
	if (a.size() != b.size()) {
		return a.size() < b.size();
	}

	//길이 같으면 숫자합 비교
	else {
		int sum_a = 0, sum_b = 0;
		for (int i = 0; i < a.length(); i++) {
			if (a[i] >= '0' && a[i] <= '9') sum_a += a[i] - '0';
			if (b[i] >= '0' && b[i] <= '9') sum_b += b[i] - '0';
		}
		//숫자합 같으면 사전순 정렬
		if (sum_a == sum_b) return a < b;
		//숫자합 다르면 숫자합 기준 정렬
		else return sum_a < sum_b;
	}
}

int main() {
	int N;
	vector<string> numbers;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		numbers.push_back(str);
	}

	//정렬
	sort(numbers.begin(), numbers.end(), cmp);

	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << "\n";
	}

	return 0;
}