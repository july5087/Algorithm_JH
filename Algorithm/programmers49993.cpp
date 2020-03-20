//스킬트리
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	bool flag = false;

	for (int i = 0; i<skill_trees.size(); i++) {
		string temp = "";
		for (int j = 0; j<skill_trees[i].size(); j++) {
			if (skill.find(skill_trees[i][j]) != -1) {
				temp += skill_trees[i][j];
			}
		}
		//find 함수:찾으면 찾은 인덱스 반환
		if (skill.find(temp) == 0) //찾은 인덱스가 0
			answer++;
	}
	return answer;
}