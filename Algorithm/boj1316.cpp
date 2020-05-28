//그룹 단어 체커
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//그룹 단어:단어에 존재하는 모든 문자에 대해 각 문자가 연속해서 나타나는 경우
int main() {
	bool used[27] = { false, }; //알파벳 사용 여부
	int N, cnt = 0;
	cin >> N;

	while (N--) {
		string input;
		cin >> input;

		//테스트케이스마다 초기화
		bool groupword = true;
		memset(used, false, sizeof(used));

		for (int i = 1; i<input.size(); i++) {
			char prev = input[i - 1];
			used[input[i - 1] - 'a' + 1] = true;
			//이전 알파벳과 같지 않고 사용한 적 있으면 그룹단어가 아님
			if (prev != input[i] && used[input[i] - 'a' + 1]) {
				groupword = false;
				break;
			}
		}
		if (groupword) cnt++;
	}
	cout << cnt;

	return 0;
}