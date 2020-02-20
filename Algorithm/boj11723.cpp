#include<iostream>
#include<string>
#include <cstring> //memset 함수(배열 초기화)
using namespace std;

int M;
bool visited[21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M;

	for (int i = 0; i < M; i++) {
		int number;
		string oper;
		
		cin >> oper;

		if (oper == "add") {
			cin >> number;
			visited[number] = true;
		}
		if (oper == "remove") {
			cin >> number;
			visited[number] = false;
		}
		if (oper == "check") {
			cin >> number;
			if (visited[number])
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		if (oper == "toggle") {
			cin >> number;
			if (visited[number])
				visited[number] = false;
			else
				visited[number] = true;
		}
		if (oper == "all") {
			memset(visited, true, sizeof(visited));
		}
		if (oper == "empty") {
			memset(visited, false, sizeof(visited));
		}
	}
}