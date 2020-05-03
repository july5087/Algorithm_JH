//조이스틱
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
	string a(name.size(), 'A');
	int answer = 0;
	int cur = 0, right, left;
	while (name != a) {
		if (name[cur] != 'A') {
			//위, 아래 방향 정해서 answer 더함
			answer += min(name[cur] - 'A', 'Z' - name[cur] + 1);
			//A로 변경
			name[cur] = 'A';
		}

		//현재 위치 기준 반만(각각 왼쪽, 오른쪽) 이동
		for (int i = 1; i <= name.size() / 2; i++) {
			right = cur + i;
			left = cur - i;
			if (right >= name.size())
				right -= name.size();
			if (left < 0) 
				left += name.size();

			//왼쪽, 오른쪽 방향 정해서 이동 길이만큼 answer 더함
			if (name[right] != 'A') {
				answer += i;
				cur = right;
				break;
			}
			else if (name[left] != 'A') {
				answer += i;
				cur = left;
				break;
			}
		}
	}
	return answer;
}