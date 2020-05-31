#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//특정 튜플 표현하는 집합(순서 x) 문자열 s가 매개변수로 주어질 때
//s가 표현하는 튜플(순서 o)을 배열에 담아 return

vector<int> solution(string s) {
	vector<int> answer;
	vector<int> numbers[501]; //배열의 길이 범위
	bool visited[100001] = { false, }; //튜플 원소의 숫자 범위

	string str_num = "";
	int idx = 0; //벡터 길이
	for (int i = 1; i <= s.size() - 2; i++) {
		//숫자인 경우 string에 저장
		if (s[i] >= '0' && s[i] <= '9') {
			str_num += s[i];
		}

		if (s[i] == '{') continue;

		if (s[i] == '}') {
			//맨 끝 숫자 넣음
			if (i == s.size() - 2) { 
				int num = stoi(str_num);
				numbers[idx].push_back(num);
				str_num = "";
			}
			else continue;
		}

		if (s[i] == ',') {
			int num = stoi(str_num);
			numbers[idx].push_back(num);
			str_num = "";
			//현재 집합의 끝이면 다음 집합에 넣음
			if (s[i + 1] == '{') {
				idx++;
				str_num = ""; //str 초기화
			}
		}
	}

	int len = 1;
	for (int k = 0; k < 501; k++) {
		bool flag = false;
		//길이 1 ~ 원소갯수까지 같은 길이 찾음
		for (int i = 0; i <= idx; i++) {
			//1부터 같은 벡터 길이 찾음
			if (numbers[i].size() == len) {
				flag = true;
				//그 안에서 방문하지 않은 숫자 넣음
				for (int j = 0; j < numbers[i].size(); j++) {
					int num = numbers[i][j];

					if (!visited[num]) {
						answer.push_back(num);
						visited[num] = true;
					}
				}
				//다음 길이 탐색
				len++;
				break;
			}
		}
		//같은 길이 없으면 종료
		if (!flag) break;
	}

	return answer;
}