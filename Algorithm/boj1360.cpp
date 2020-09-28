//되돌리기
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<pair<string, int> > v;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string cmd, val; //val:type인 경우 문자, undo인 경우 돌아갈 시간
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
			//배열을 뒤부터 순서대로 탐색해 (현재시간-t)초 이전의 상태 불러옴
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