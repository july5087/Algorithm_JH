//단어 뒤집기
#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	stack<char> s;

	string enter;
	getline(cin, enter);
	string line;

	for (int i = 0; i < n; i++) { //입력
		getline(cin, line);

		for (int i = 0; i < line.length(); i++) {
			if (line[i] != ' ') { //공백 아닌 경우
				s.push(line[i]);
			}

			else { //공백인 경우
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << " ";
			}
		}

		while (!s.empty()) { //마지막 단어 뒤집기
			cout << s.top();
			s.pop();
		}
		cout << "\n";
	}
}