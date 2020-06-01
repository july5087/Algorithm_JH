//���м���
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//���� ��� ã�� �� ������������ ����(002 -> 2)
//�� ���ڿ� 100�ڸ����� ���� -> int, longlong���� ��ȯ �Ұ�

bool cmp(string a, string b) {
	//���� �ٸ��� ���� ���� �������� ����
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	//���� ������ ������ �������� ����
	else return a < b;
}

int main() {
	int N;
	vector<string> v;
	vector<string> answer;

	cin >> N;
	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		v.push_back(line);
	}

	for (int i = 0; i < v.size(); i++) {
		string temp = "";
		for (int j = 0; j < v[i].size(); j++) {
			//���ڸ� string�� ����
			if (v[i][j] >= '0' && v[i][j] <= '9') {
				//���� 0 ���� ó��
				if (v[i][j] == '0' && temp == "") {
					//���ڸ� �� 0 ���
					if ((v[i][j + 1] < '0' || v[i][j + 1] > '9') && j + 1 < v[i].size()) temp += v[i][j];
					if (j == v[i].size() - 1) temp += v[i][j];
					//�ƴϸ� ���� ����
					else continue;
				}
				else temp += v[i][j];
			}
			//���� �ƴϰ� temp ������� ���Ϳ� string �����ϰ� �ʱ�ȭ
			else {
				if (temp != "") {
					answer.push_back(temp);
					temp = "";
				}
				else continue;
			}
		}
		//temp�� string ���������� ����
		if (temp != "") answer.push_back(temp);
	}
	//string ���̼� -> ������ ����
	sort(answer.begin(), answer.end(), cmp);

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}