#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;

//split �Լ� ����
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

	//�г��� ���� ó��
	//1. �����ٰ� �ٽ� ���� ��
	//2. Change�� ����
	for (int i = 0; i<record.size(); i++) {
		line = Split(record[i], ' ');

		string command = line[0];
		string output = "";
		if (command == "Enter" || command == "Change") {
			m[line[1]] = line[2]; //key�� ���� value �� �Է� �� ����
		}
	}

	for (int i = 0; i<record.size(); i++) {
		line = Split(record[i], ' ');

		string command = line[0];
		if (command == "Enter") {
			string output = m[line[1]] + "���� ���Խ��ϴ�.";
			answer.push_back(output);
		}
		if (command == "Leave") {
			string output = m[line[1]] + "���� �������ϴ�.";
			answer.push_back(output);
		}
	}
	return answer;
}