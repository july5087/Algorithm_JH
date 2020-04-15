//카펫
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	int all = brown + red;
	int limit = (int)sqrt(all);

	//가로, 세로 항상 3이상
	for (int i = 3; i <= limit; i++) {
		//넓이의 약수인 경우
		if (all % i == 0) {
			int temp = all / i; // temp > i
			//(전체 가로 - 2) * (전체 세로 - 2) == red 크기이면
			if ((temp - 2) * (i - 2) == red) {
				answer.push_back(temp);
				answer.push_back(i);
				break;
			}
		}
	}
	return answer;
}