//문자열
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//A의 길이가 B를 넘어가지 않을 동안 starting position을 변경해가면서 A와 B의 차이 최솟값 찾기
int main() {
	string a, b;
	cin >> a >> b;
	int answer = 50; //최대값 : A, B 모두 다른 경우

	for (int i = 0; i <= b.size() - a.size(); i++) {
		int cnt = 0;
		for (int k = 0; k < a.size(); k++) {
			if (a[k] != b[k + i]) cnt++;
		}
		answer = min(answer, cnt);
	}
	cout << answer << "\n";

	return 0;
}