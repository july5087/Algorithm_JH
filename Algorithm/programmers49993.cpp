//��ųƮ��
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
		//find �Լ�:ã���� ã�� �ε��� ��ȯ
		if (skill.find(temp) == 0) //ã�� �ε����� 0
			answer++;
	}
	return answer;
}