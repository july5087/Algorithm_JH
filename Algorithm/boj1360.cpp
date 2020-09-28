//�ǵ�����
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<pair<string, int> > v;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string cmd, val; //val:type�� ��� ����, undo�� ��� ���ư� �ð�
		int time;

		cin >> cmd >> val >> time;

		if (cmd == "type") {
			string next_val;
			if (v.size()) next_val = v.back().first + val;
			else next_val = val;
			v.push_back({ next_val, time });
		}
		else if(cmd == "undo") {
			string re = "";
			//�迭�� �ں��� ������� Ž���� (����ð�-t)�� ������ ���� �ҷ���
			for (int i = v.size() - 1; i >= 0; i--) {
				if (time - stoi(val.c_str()) > v[i].second) {
					re = v[i].first;
					break;
				}
			}
			v.push_back({ re, time });
		}
	}
	cout << v.back().first;

	return 0;
}