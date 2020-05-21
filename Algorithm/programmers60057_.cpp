#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

string press(string s, int size) {
	string press_str = "";
	string temp = "";
	int cnt = 1;

	for (int i = 0; i < s.size(); i += size) {
		string cur = s.substr(i, size).c_str();
		string next = "";
		if (i + size < s.size())
			next = s.substr(i + size, size).c_str();

		//압축 가능한 경우 압축 횟수 셈
		if (cur == next) cnt++;
		//압축 불가능한 경우
		else {
			//이전에 압축된 경우의 압축횟수 붙임
			if (cnt >= 2) press_str += to_string(cnt);
			//size만큼 자른 문자열 붙임
			press_str += cur;
			
			//압축횟수 초기화
			cnt = 1;
			//다음 size만큼 비교
			continue;
		}
	}
	return press_str;
}

int solution(string s) {
	int answer = s.size();
	//압축사이즈 s/2부터 1까지 지정하고 압축해서 최소값 찾음
	for (int i = s.size() / 2; i >= 1; i--) {
		//압축된 문자열
		string result = press(s, i);
		//압축된 문자열 길이
		int press_size = result.size();
		//최솟값 갱신
		answer = min(answer, press_size);
	}
	return answer;
}