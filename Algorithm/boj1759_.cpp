//암호 만들기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C, answer;
char alpha[16];
bool visited[16];
vector<char> v;

void dfs(int cnt) {
	if (cnt == L) {
		int mo = 0, ja = 0;
		bool flag = true;
		//암호 조건2 검사 : 최소 2개 자음, 1개 모음
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') mo++;
			else ja++;
		}
		// 3. 출력
		if (ja >= 2 && mo >= 1) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i];
			}
			cout << "\n";
		}
	}

	for (int i = 0; i < C; i++) {
		if (!visited[i]) {
			//암호 조건1 검사:오름차순
			//빈 벡터가 아니고 넣을 알파벳이 더 작으면 continue
			if(!v.empty() && alpha[i] < v[v.size()-1]) continue;

			visited[i] = true;
			v.push_back(alpha[i]);

			dfs(cnt + 1);

			visited[i] = false;
			v.pop_back();
		}
	}
}

int main() {
	//1. 입력
	cin >> L >> C; //C개 알파벳 중 L개 사용한 암호 조합
	for (int i = 0; i < C; i++) {
		cin >> alpha[i];
	}
	//오름차순 정렬
	sort(alpha, alpha + C);

	//2. 탐색
	dfs(0);

	return 0;
}