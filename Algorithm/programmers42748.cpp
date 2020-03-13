//K¹øÂ° ¼ö
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int i = 0; i<commands.size(); i++) {
		vector<int> subset;
		for (int j = commands[i][0] - 1; j<commands[i][1]; j++) {
			subset.push_back(array[j]);
		}
		sort(subset.begin(), subset.end());
		answer.push_back(subset[commands[i][2] - 1]);
	}
	return answer;
}