//�ܾ� ������
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

	for (int i = 0; i < n; i++) { //�Է�
		getline(cin, line);

		for (int i = 0; i < line.length(); i++) {
			if (line[i] != ' ') { //���� �ƴ� ���
				s.push(line[i]);
			}

			else { //������ ���
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << " ";
			}
		}

		while (!s.empty()) { //������ �ܾ� ������
			cout << s.top();
			s.pop();
		}
		cout << "\n";
	}
}