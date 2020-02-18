//암호 만들기
//순열 이용
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int L, C;
vector<char> letters;
vector<char> password;
bool visited[15];

//암호 조건
//1. 최소 한 개의 모음과 최소 두 개의 자음으로 구성
//2. 알파벳 오름차순
void DFS(int idx, int cnt) {
	if (cnt == L) {

		int ja = 0, mo = 0;
		//자음, 모음 수 검사
		for (int i = 0; i < password.size(); i++) {
			if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u')
				mo++;
			else 
				ja++;
		}
		if (mo >= 1 && ja >= 2)
		{
			for (int i = 0; i < L; i++) {
				cout << password[i];
			}
			cout << "\n";
		}
		return;
	}
	for (int i = idx; i < C; i++) {
		if (!visited[i]) {
			visited[i] = true;

			password.push_back(letters[i]);
			DFS(i, cnt + 1);

			visited[i] = false;
			password.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		char letter;
		cin >> letter;
		letters.push_back(letter);
	}
	//오름차순 정렬
	sort(letters.begin(), letters.end());

	DFS(0, 0);
}