//���� �����ձ�
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
	string prev_word = words[0]; //���� �ܾ�
	s.insert(words[0]);

	for (int i = 1; i < words.size(); i++) {
		//���� �ܾ� ������ ���ڿ� ���� �ܾ� ù ���� �ٸ��� Ż��
		if (prev_word[prev_word.size() - 1] != words[i][0]) {
			flag = false;
		}
		//���� �ܾ� ������ set�� �Է�, ������ Ż��
		if (s.find(words[i]) == s.end()) s.insert(words[i]);
		else flag = false;

		//Ż���� ���
		if (!flag) {
			answer.push_back(i % n + 1); //Ʋ�� ��� ��ȣ
			answer.push_back(i / n + 1); //Ʋ�� ����� ���� ����
			return answer;
		}
		prev_word = words[i]; //���� �ܾ ���� �ܾ��
	}

	//Ż���� ��� ���� ���
	answer.push_back(0);
	answer.push_back(0);

	return answer;
}