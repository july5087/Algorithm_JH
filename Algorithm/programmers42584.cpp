//주식가격
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;

	for (int i = 0; i<prices.size(); i++) {
		int rise = 0;
		for (int j = i + 1; j<prices.size(); j++) {
			if (prices[i] <= prices[j])
				rise++;
			else {
				rise++; //1초 뒤에 떨어져도 1초 count에 ++
				break;
			}

		}
		answer.push_back(rise);
	}
	return answer;
}