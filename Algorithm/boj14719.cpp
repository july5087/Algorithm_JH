//빗물
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int H, W, rain = 0;
	int map[501]; //블록 높이

	cin >> H >> W; //세로, 가로
	for (int i = 0; i < W; i++) {
		cin >> map[i];
	}

	//현재 블록 기준 왼쪽 가장 높은 블럭과 오른쪽 가장 높은 블럭 찾음
	//있으면 (그 중 작은 높이 - 현재 블록 높이)만큼 빗물 채움
	for (int i = 1; i < W - 1; i++) {
		int cur = map[i];
		//최대값 현재 높이로 초기화(현재 높이가 가장 높으면 빗물 0)
		int left_max = cur, right_max = cur;

		//왼쪽 가장 높은 블럭
		for (int l = 0; l < i; l++) {
			left_max = max(left_max, map[l]);
		}
		//오른쪽 가장 높은 블럭
		for (int r = i + 1; r <= W - 1; r++) {
			right_max = max(right_max, map[r]);
		}
		rain += min(left_max, right_max) - cur;
	}
	cout << rain << "\n";

	return 0;
}