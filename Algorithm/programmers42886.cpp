//저울
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> weight) {
	int answer = 0;

	//추 무게 기준 오름차순 정렬
	sort(weight.begin(), weight.end());

	for (int i = 0; i < weight.size(); i++) {
		//누적된 추 무게 합보다 더 큰 추가 나오면 만들 수 없는 무게
		if (answer < weight[i]) break;
		
		//추 무게 누적
		answer += weight[i];
	}
	//answer-1 : 앞의 추로 만들 수 있는 최대의 수
	return answer - 1;
}
