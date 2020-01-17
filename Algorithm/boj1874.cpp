#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

void output(vector<int> v) {
	stack<int> s;
	int max = 0;
	string answer = "";

	for (int i = 0; i < v.size(); i++) {
		if (v[i] > max) {
			for (int j = max + 1; j <= v[i]; j++) {
				s.push(j);
				answer += "+\n";
			}
			max = v[i];
		}
		if (s.top() == v[i]) {
			s.pop();
			answer += "-\n";
		}
		else {
			answer = "NO\n";
			break;
		}
	}
	cout << answer;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	vector<int> v;
	int max = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	output(v);
}