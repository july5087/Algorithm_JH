//타겟 넘버
#include <string>
#include <vector>
using namespace std;

int answer = 0;
void dfs(vector<int> numbers, int target, int sum, int count) {
	//재귀 탈출 조건
	if (count == numbers.size()) {
		if (sum == target) answer++;
		return;
	}
	//해당 원소 더했을 때 비교
	dfs(numbers, target, sum + numbers[count], count + 1);
	//해당 원소 뺐을 때 비교
	dfs(numbers, target, sum - numbers[count], count + 1);
}

int solution(vector<int> numbers, int target) {
	dfs(numbers, target, 0, 0);
	return answer;
}