//�ܾ� ��ȯ
#include <string>
#include <vector>
#include <queue>
using namespace std;

//��ȯ ���� ���� Ȯ��
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

	q.push(make_pair(begin, 0)); //���� �ܾ� ť�� ����
	while (!q.empty()) {
		//ť�� �� �� �ܾ� ����
		string node = q.front().first;
		int temp = q.front().second;
		q.pop();
		//���� �ܾ�� ����� ���� �ܾ� Ž��
		for (int i = 0; i < words.size(); i++) {
			if (!visited[i] && isChangeable(node, words[i])) {
				if (words[i] == target) {
					answer = temp + 1;
					//���� �����ϸ� temp �� ����
					return answer;
				}
				visited[i] = true;
				q.push(make_pair(words[i], temp + 1));
			}
		}
	}
	//target���� ���� �Ұ����ϸ� 0 ����
	return answer;
}