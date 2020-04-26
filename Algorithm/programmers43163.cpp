//단어 변환
#include <string>
#include <vector>
#include <queue>
using namespace std;

//변환 가능 여부 확인
bool isChangeable(string a, string b) {
	int cnt = 0;
	for (int i = 0; i<a.size(); i++) {
		if (a[i] != b[i]) cnt++;
	}
	if (cnt == 1) return true;
	else return false;
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	queue<pair<string, int> > q;
	bool visited[50] = { false, };

	q.push(make_pair(begin, 0)); //시작 단어 큐에 넣음
	while (!q.empty()) {
		//큐의 맨 앞 단어 꺼냄
		string node = q.front().first;
		int temp = q.front().second;
		q.pop();
		//현재 단어와 연결된 다음 단어 탐색
		for (int i = 0; i < words.size(); i++) {
			if (!visited[i] && isChangeable(node, words[i])) {
				if (words[i] == target) {
					answer = temp + 1;
					//연결 가능하면 temp 값 리턴
					return answer;
				}
				visited[i] = true;
				q.push(make_pair(words[i], temp + 1));
			}
		}
	}
	//target까지 연결 불가능하면 0 리턴
	return answer;
}