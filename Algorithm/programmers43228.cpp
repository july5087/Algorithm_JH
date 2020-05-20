//입국심사
//이분탐색
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
	//시간 오름차순 정렬
	sort(times.begin(), times.end());
	//최소시간 = 심사하는데 가장 짧게 걸리는 시간
	long long min = times[0];
	//최대시간 = 심사하는데 가장 오래 걸리는 시간 * 인원수
	long long max = (long long)(times[times.size() - 1]) * n;
	long long answer = max;

	//이분탐색
	while (min <= max) {
		//mid:총 걸린시간
		long long mid = (min + max) / 2;
		//sum:총 입국자 수
		long long sum = 0;

		//심사관 당 입국자 수 더함
		for (int i = 0; i < times.size(); i++)
			sum += mid / times[i];

		//n과 비교
		//불가능한 경우 시간 늘림
		if (n > sum) min = mid + 1;
		//가능한 경우
		else {
			//최소값 갱신
			if (mid <= answer) answer = mid;
			//시간 줄임
			max = mid - 1;
		}
	}
	return answer;
}