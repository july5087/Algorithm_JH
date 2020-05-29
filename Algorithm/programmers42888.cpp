#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;

//split 함수 구현
vector<string> Split(string str, char delimiter) {
	vector<string> ret;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		ret.push_back(temp);
	}

	return ret;
}

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<string> line;
	map<string, string> m;
	map<string, string> ::iterator it;

	//닉네임 변경 처리
	//1. 나갔다가 다시 들어올 때
	//2. Change로 변경
	for (int i = 0; i<record.size(); i++) {
		line = Split(record[i], ' ');

		string command = line[0];
		string output = "";
		if (command == "Enter" || command == "Change") {
			m[line[1]] = line[2]; //key에 따른 value 값 입력 및 수정
		}
	}

	for (int i = 0; i<record.size(); i++) {
		line = Split(record[i], ' ');

		string command = line[0];
		if (command == "Enter") {
			string output = m[line[1]] + "님이 들어왔습니다.";
			answer.push_back(output);
		}
		if (command == "Leave") {
			string output = m[line[1]] + "님이 나갔습니다.";
			answer.push_back(output);
		}
	}
	return answer;
}