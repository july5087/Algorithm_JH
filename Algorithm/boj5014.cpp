//��ŸƮ��ũ
#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
int visited[1000001];
int cnt = 0;

int bfs() {
	queue<int> q;
	q.push(S);
	visited[S] = 1;
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		//�������� �� ���
		if (cur == G) {
			return visited[cur] - 1;
		}
		//�������� �̵�
		if (cur + U > 0 && cur + U <= F && !visited[cur + U]) {
			visited[cur + U] = visited[cur] + 1;
			q.push(cur + U);
		}
		//�Ʒ������� �̵�
		if (cur - D > 0 && cur - D <= F && !visited[cur - D]) {
			visited[cur - D] = visited[cur] + 1;
			q.push(cur - D);
		}
	}
	//G���� �������� ���� ���
	return -1;
}

int main() {
	//F:���� �� ����, S:������, G:������, U:���� U�� ���� ��ư, D:�Ʒ��� D�� ���� ��ư
	cin >> F >> S >> G >> U >> D;

	int result = bfs();

	//G������ �� �� ���� ���
	if (result == -1)
		cout << "use the stairs\n";
	//G������ �� �� �ִ� ���
	cout << cnt << "\n";

	return 0;
}