#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <ctime> 
using namespace std;

int main() {
	clock_t start, end;
	double result;
	start = clock(); //시간측정 시작

	//vector<string> record = {"RECEIVE abcd@naver.com", "RECEIVE zzkn@naver.com", "DELETE", "RECEIVE	qwerty@naver.com", "SAVE", "RECEIVE QwerTY@naver.com"};
	vector<string> record = { "RECEIVE abcd@naver.com", "RECEIVE zzkn@naver.com", "DELETE", "RECEIVE qwerty@naver.com", "SAVE", "SAVE", "DELETE", "RECEIVE QwerTY@naver.com", "SAVE" };
	stack<string> temp;
	vector<string> temp2;
	queue<string> perma;

	for (int i = 0; i < record.size(); i++) {
		stringstream ss(record[i]);
		string command, email;
		ss >> command;

		if (command == "RECEIVE") {
			ss >> email;
			temp.push(email);
		}
		else if (command == "DELETE" && !temp.empty()) {
			temp.pop();
		}
		else if (command == "SAVE") {
			while (!temp.empty()) {
				string str = temp.top();
				temp.pop();
				temp2.push_back(str);
				reverse(temp2.begin(), temp2.end());
			}
			for (int i = 0; i<temp2.size(); i++) {
				perma.push(temp2[i]);
			}

			temp2.clear();
		}
	}

	while (!perma.empty()) {
		cout << perma.front() << "\n";
		perma.pop();
	}

	end = clock(); //시간 측정 끝
	result = (double)(end - start);
	cout << "result : " << ((result) / CLOCKS_PER_SEC) << "seconds" << "\n";

	return 0;
}