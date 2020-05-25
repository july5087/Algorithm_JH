//땅따먹기
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
	int answer = 0;

	for (int i = 1; i < land.size(); ++i) {
		for (int j = 0; j < 4; ++j) {
			int cur_max = 0;
			for (int k = 0; k < 4; ++k) {
				//같은 열을 연속해서 밟을 수 없음
				if (j == k) continue;
				//현재 라인 위의 값들 중 최대값 찾음
				cur_max = max(cur_max, land[i - 1][k]);
			}
			// 현재 위치에 누적
			land[i][j] += cur_max;
		}
	}
	//최종으로 누적된 값 중 최대값 찾음
	for (int i = 0; i < 4; ++i) {
		answer = max(answer, land[land.size() - 1][i]);
	}

	return answer;
}