//������
#include<iostream>
#include<string>
#include<stack>
using namespace std;

void textEditor(string text) {
	stack<char> left, right;
	int num;
	cin >> num; //��ɾ� ��

	string enter;
	getline(cin, enter);
	string command;

	//1. �Է¹��� ���ڿ� left�� ��� push
	for (int i = 0; i < text.size(); i++) {
		left.push(text[i]);
	}

	//2. ��ɾ� ó��
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

	//3. left���� pop�� ��� ��ҵ� => right���ÿ� ��� push (left, right ���ڿ� �մ� �۾�) 
	while (!left.empty()) {
		//cout << left.top();
		right.push(left.top());
		left.pop();
	}

	//4. right���� ��� ��� pop(���ڿ� ��� �۾�)
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