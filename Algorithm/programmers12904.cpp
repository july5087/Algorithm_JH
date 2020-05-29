//가장 긴 팰린드롬
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solution(string s)
{
	for (int len = s.size(); len > 1; len--) { //부분문자열 길이
		for (int start = 0; start + len <= s.size(); start++) { //s의 시작점
			bool flag = true;

			//팰린드롬 여부 검사(문자열 길이의 반까지)
			for (int i = 0; i<len / 2; i++) {
				if (s[start + i] != s[start + len - i - 1]) {
					flag = false;
					break;
				}
			}
			if (flag) return len;
		}
	}
	return 1;
}