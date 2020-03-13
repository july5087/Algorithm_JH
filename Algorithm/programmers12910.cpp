//나누어 떨어지는 숫자 배열
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
	vector<int> answer;
	int count = 0;

	sort(arr.begin(), arr.end());
	for (int i = 0; i<arr.size(); i++) {
		if (arr[i] % divisor == 0) {
			answer.push_back(arr[i]);
			count++;
		}
	}
	if (count == 0)
		answer.push_back(-1);

	return answer;
}