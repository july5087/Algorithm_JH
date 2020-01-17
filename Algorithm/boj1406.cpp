//에디터
#include<iostream>
#include<string>
#include<stack>
using namespace std;

void textEditor(string text) {
	stack<char> left, right;
	int num;
	cin >> num; //명령어 수

	string enter;
	getline(cin, enter);
	string command;

	//1. 입력받은 문자열 left에 모두 push
	for (int i = 0; i < text.size(); i++) {
		left.push(text[i]);
	}

	//2. 명령어 처리
	for (int k = 0; k < num; k++) {
		getline(cin, command);

		if (command == "L" && !left.empty()) {
			right.push(left.top());
			left.pop();
		}
		if (command == "D" && !right.empty()) {
			left.push(right.top());
			right.pop();
		}
		if (command == "B" && !left.empty()) {
			left.pop();
		}
		if (command[0] == 'P') {
			left.push(command[2]);
		}
	}

	//3. left에서 pop한 모든 요소들 => right스택에 모두 push (left, right 문자열 잇는 작업) 
	while (!left.empty()) {
		//cout << left.top();
		right.push(left.top());
		left.pop();
	}

	//4. right스택 요소 모두 pop(문자열 출력 작업)
	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}
	cout << "\n";
}

int main() {
	string text;
	cin >> text;

	textEditor(text);
}