#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> budgets, int M) {
	long long sum = 0;
	sort(budgets.begin(), budgets.end());
	for (int i = 0; i<budgets.size(); i++) {
		sum += budgets[i];
	}
	if (sum < M)
		return *(budgets.end() - 1);

	long long hap = 0;
	int size = budgets.size();
	long long avg = M / size;

	for (int i = 0; i<budgets.size(); i++) {
		//평균 넘는 경우
		if (budgets[i] > avg) return avg;
		//평균 이하인 경우
		hap += budgets[i];
		size--;
		avg = (M - hap) / size;
	}
}