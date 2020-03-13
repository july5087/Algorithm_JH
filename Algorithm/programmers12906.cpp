//같은 숫자는 싫어
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;

	int start = arr.front();
	answer.push_back(start);

	for (int k = 1; k<arr.size(); k++) {
		if (arr[k] != start)
			answer.push_back(arr[k]);
		start = arr[k];
	}
	return answer;
}