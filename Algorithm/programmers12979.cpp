//기지국 설치
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;
	int idx = 0;
	int location = 1;

	while (location <= n) {
		//기지국 전파 미치는 범위(가장 왼쪽)안에 현재 위치 있는지 확인
		if (idx<stations.size() && location >= stations[idx] - w) {
			location = stations[idx] + w + 1;
			idx++;
		}
		//범위 안에 없으면 
		else {
			//기지국 설치
			answer++;
			//전파 길이만큼 현재 위치 이동
			location += (2 * w) + 1;
		}
	}
	return answer;
}