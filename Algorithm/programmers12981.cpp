//영어 끝말잇기
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	set<string> s;
	
	bool flag = true;
	string prev_word = words[0]; //이전 단어
	s.insert(words[0]);

	for (int i = 1; i < words.size(); i++) {
		//이전 단어 마지막 문자와 현재 단어 첫 문자 다르면 탈락
		if (prev_word[prev_word.size() - 1] != words[i][0]) {
			flag = false;
		}
		//현재 단어 없으면 set에 입력, 있으면 탈락
		if (s.find(words[i]) == s.end()) s.insert(words[i]);
		else flag = false;

		//탈락인 경우
		if (!flag) {
			answer.push_back(i % n + 1); //틀린 사람 번호
			answer.push_back(i / n + 1); //틀린 사람이 말한 순서
			return answer;
		}
		prev_word = words[i]; //현재 단어를 이전 단어로
	}

	//탈락인 사람 없는 경우
	answer.push_back(0);
	answer.push_back(0);

	return answer;
}