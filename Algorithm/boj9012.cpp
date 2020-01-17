//°ýÈ£
#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isVPS(string line) {
	stack<char> s;
	int size = line.size();

	for (int i = 0; i < size; i++) {
		if (line[i] == '(')
			s.push(line[i]);
		else {
			if (s.empty()) return false;
			else s.pop();
		}
	}

	if (s.empty()) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;
		if (isVPS(line))
			cout << "YES" << '\n';
		else
			cout << "NO" << "\n";
	}
}