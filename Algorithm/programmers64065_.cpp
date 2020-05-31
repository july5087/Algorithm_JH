//Ʃ��
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
	return a.size() < b.size();
}
vector<int> solution(string s) {
	bool visited[100001] = { false, };
	vector<int> answer;
	vector<vector<int> > numbers;

	for (int i = 0; i< s.length(); i++) {
		//������ ���
		if (s[i] >= '0' && s[i] <= '9') {
			vector<int> tmp;

			bool flag = false;
			while (!flag) {
				int tmp_num = 0;

				while (1) {
					if (s[i] == '}') { //�迭 ��
						tmp.push_back(tmp_num);
						flag = true;
						break;
					}
					else if (s[i] == ',') { //���� ��
						tmp.push_back(tmp_num);
						tmp_num = 0;

					}
					else { //���ڸ� �ڸ��� ����ؼ� ����
						tmp_num *= 10;
						tmp_num += s[i] - '0';
					}

					i++;
				}
			}
			numbers.push_back(tmp);
		}
	}
	//���� ���� �������� �������� ����
	sort(numbers.begin(), numbers.end(), cmp);

	for (int i = 0; i < numbers.size(); i++) { //���̼�
		for (int j = 0; j < numbers[i].size(); j++) {
			//�湮���� ���� ���� ����
			if (!visited[numbers[i][j]]) {
				visited[numbers[i][j]] = true;
				answer.push_back(numbers[i][j]);
			}
		}
	}
	return answer;
}