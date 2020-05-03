//구명보트
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int visited[50001];

int solution(vector<int> people, int limit) {
	int answer = 0;
	int cnt = 0;
	//무게 기준 오름차순 정렬
	sort(people.begin(), people.end());

	int light = 0;
	int heavy = people.size() - 1;

	while (light <= heavy) {
		//최소 + 최대 같이 타는 경우
		if (people[light] + people[heavy] <= limit) {
			//최소, 최대 같이 탐
			light++;
			heavy--;
		}
		//최소 + 최대 같이 못타는 경우
		else {
			//최대 혼자 탐
			heavy--;
		}
		//최소 + 최대 같이 타는 경우 => 1대 추가
		//최소 + 최대 같이 못타는 경우:최대 혼자 탐 => 1대 추가
		answer++;
	}
	return answer;
}