//모의고사
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;

	int one[] = { 1,2,3,4,5 };
	int two[] = { 2,1,2,3,2,4,2,5 };
	int three[] = { 3,3,1,1,2,2,4,4,5,5 };

	int count[3] = { 0,0,0 };
	int maxval = 0;

	for (int i = 0; i<answers.size(); i++) {
		if (answers[i] == one[i % 5]) count[0]++;
		if (answers[i] == two[i % 8]) count[1]++;
		if (answers[i] == three[i % 10]) count[2]++;
	}
	maxval = max(max(count[0], count[1]), count[2]);
	for (int i = 0; i < 3; i++) {
		if (count[i] == maxval)
			answer.push_back(i + 1);
	}
	return answer;
}