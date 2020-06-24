//최고의 집합
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
	vector<int> answer;
	vector<int> temp;

	//n개로 합이 s인 집합 만들 수 없는 경우
	if (s / n <= 0) {
		answer.push_back(-1);
		return answer;
	}

	for (int i = 0; i<n; i++) {
		temp.push_back(s / n);
	}

	//나머지만큼 원소에 1 더함
	int diff = s % n;
	for (int i = 0; i<diff; i++) {
		temp[temp.size() - 1 - i]++;
	}
	answer = temp;

	return answer;
}