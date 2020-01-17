//사탕게임
#include<iostream>
#include<algorithm>
using namespace std;

int N;
char candy[51][51];
int garoMax, seroMax;
int answer;

//배열 SWAP
void swap(char &a, char &b) {
	char temp;
	temp = a;
	a = b;
	b = temp;
}

int check() {

	for (int i = 0; i < N; i++) {
		garoMax = 1;

		for (int j = 0; j < N - 1; j++) {
			if (candy[i][j] == candy[i][j + 1]) {
				garoMax++;
				answer = max(answer, garoMax);
			}
			else {
				answer = max(answer, garoMax);
				garoMax = 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		seroMax = 1;

		for (int j = 0; j < N - 1; j++) {
			if (candy[j][i] == candy[j + 1][i]) {
				seroMax++;
				answer = max(answer, seroMax);
			}
			else {
				answer = max(answer, seroMax);
				seroMax = 1;
			}
		}
	}

	return max(garoMax, seroMax);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char color;
			cin >> color;
			candy[i][j] = color;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j + 1 < N) {
				//가로 swap
				swap(candy[i][j], candy[i][j + 1]);
				check();
				swap(candy[i][j], candy[i][j + 1]);
			}

			if (i + 1 < N) {
				//세로 swap
				swap(candy[i][j], candy[i + 1][j]);
				check();
				swap(candy[i][j], candy[i + 1][j]);
			}
		}
	}

	cout << answer << '\n';
}