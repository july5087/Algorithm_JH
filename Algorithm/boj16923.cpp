//다음 다양한 단어
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//다양한 단어 : 모두 다른 알파벳 소문자로만 이루어진 단어
//다양한 단어 S 주어졌을 때, 사전 순으로 S의 바로 다음에 오는 다양한 단어 출력
//없으면 -1 출력
int main() {
	string s;
	char cp_s[26];
	char alpha[] = "abcdefghijklmnopqrstuvwxyz";
	//문자열 S 입력
	cin >> s;
	int length = s.size();
	//문자열 복사
	for (int i = 0; i<length; i++) {
		cp_s[i] = s[i];
	}

	//a ~ z 모두 쓰인 경우
	if (length == 26) {
		//사전순 다음 단어 출력
		//배열 크기 + 1 문자열 끝(널)도 순열에 포함
		if (next_permutation(cp_s, cp_s + 27)) {
			cout << cp_s << "\n";
		}
		//다음 순열 없으면(a~z 이거나 z~a)
		else cout << "-1\n";
	}

	else {
		//문자열 알파벳순 정렬
		sort(cp_s, cp_s + length);
		//빠진 알파벳 체크
		char to_add = ' ';
		int idx = 0;
		for (int i = 0; i < 26; i++) {
			if (cp_s[i] != alpha[i]) {
				to_add = alpha[i];
				idx = i;
				break;
			}
		}
		if (to_add == ' ')
			to_add = ++cp_s[length - 1];
		s += to_add;
		cout << s << "\n";
	}
	return 0;
}