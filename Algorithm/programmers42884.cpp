#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
	//단속카메라는 무조건 1대 이상 설치, 1로 초기화
	int answer = 1;
	//차량이 들어오는 시점 기준 오름차순 정렬
	sort(routes.begin(), routes.end());
	//초기값(첫번째 차 나가는 위치)
	int temp = routes[0][1];
	for (int i = 0; i<routes.size() - 1; i++) {
		//현재차 나가는 위치와 다음차 나가는 위치중 작은값 temp에 저장
		if (temp > routes[i][1]) temp = routes[i][1];
		//현재차 또는 다음차 나간 뒤 다음차 들어오면 카메라 설치
		if (temp < routes[i + 1][0]) {
			answer++;
			//다음차 나가는 위치를 temp에 저장(다음 루프에 비교하기 위해)
			temp = routes[i + 1][1];
		}
	}
	return answer;
}