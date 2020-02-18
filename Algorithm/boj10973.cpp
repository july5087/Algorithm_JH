//이전 순열
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int permu[10000];

void solution() {
	if (prev_permutation(permu, permu + N) == true) {
		for (int i = 0; i < N; i++)
			cout << permu[i] << " ";
		cout << "\n";
	}
	else
		cout << "-1\n";
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> permu[i];

	solution();
}