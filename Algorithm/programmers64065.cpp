#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//Ư�� Ʃ�� ǥ���ϴ� ����(���� x) ���ڿ� s�� �Ű������� �־��� ��
//s�� ǥ���ϴ� Ʃ��(���� o)�� �迭�� ��� return

vector<int> solution(string s) {
	vector<int> answer;
	vector<int> numbers[501]; //�迭�� ���� ����
	bool visited[100001] = { false, }; //Ʃ�� ������ ���� ����

	string str_num = "";
	int idx = 0; //���� ����
	for (int i = 1; i <= s.size() - 2; i++) {
		//������ ��� string�� ����
		if (s[i] >= '0' && s[i] <= '9') {
			str_num += s[i];
		}

		if (s[i] == '{') continue;

		if (s[i] == '}') {
			//�� �� ���� ����
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
			//���� ������ ���̸� ���� ���տ� ����
			if (s[i + 1] == '{') {
				idx++;
				str_num = ""; //str �ʱ�ȭ
			}
		}
	}

	int len = 1;
	for (int k = 0; k < 501; k++) {
		bool flag = false;
		//���� 1 ~ ���Ұ������� ���� ���� ã��
		for (int i = 0; i <= idx; i++) {
			//1���� ���� ���� ���� ã��
			if (numbers[i].size() == len) {
				flag = true;
				//�� �ȿ��� �湮���� ���� ���� ����
				for (int j = 0; j < numbers[i].size(); j++) {
					int num = numbers[i][j];

					if (!visited[num]) {
						answer.push_back(num);
						visited[num] = true;
					}
				}
				//���� ���� Ž��
				len++;
				break;
			}
		}
		//���� ���� ������ ����
		if (!flag) break;
	}

	return answer;
}