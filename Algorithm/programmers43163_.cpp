//´Ü¾î º¯È¯
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int visited[51];
bool flag = false;
int min_cnt = 987654321;
int answer = 0;

bool isChangeable(string a, string b) {
	int cnt = 0;
	for (int i = 0; i<a.size(); i++) {
		if (a[i] != b[i]) cnt++;
	}
	if (cnt == 1) return true;
	else return false;
}

void dfs(string begin, string target, vector<string> words, int cnt) {
	if (begin == target) {
		min_cnt = min(min_cnt, cnt);
		flag = true;
	}
	for (int i = 0; i<words.size(); i++) {
		if (!visited[i] && isChangeable(begin, words[i])) {
			visited[i] = true;
			dfs(words[i], target, words, cnt + 1);
			visited[i] = false;
		}
	}
}

void bfs(string begin, string target, vector<string> words) {
	queue<pair<string, int> > q;
	q.push({ begin, 0 });

	while (!q.empty()) {
		string cur = q.front().first;
		int step = q.front().second;
		q.pop();

		if (cur == target) answer = step;

		for (int i = 0; i<words.size(); i++) {
			if (!visited[i] && isChangeable(cur, words[i])) {
				visited[i] = true;
				q.push({ words[i], step + 1 });
			}
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	//DFS Å½»ö
	// for(int i=0; i<words.size(); i++){
	//     if(!visited[i])
	//         dfs(begin, target, words, 0);
	// }
	// if(flag) answer = min_cnt;
	// else answer = 0;
	//
	// return answer;

	//BFS Å½»ö
	bfs(begin, target, words);

	return answer;
}