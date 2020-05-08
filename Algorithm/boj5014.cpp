//½ºÅ¸Æ®¸µÅ©
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

		//µµÂøÃþ¿¡ ¿Â °æ¿ì
		if (cur == G) {
			return visited[cur] - 1;
		}
		//À­ÃþÀ¸·Î ÀÌµ¿
		if (cur + U > 0 && cur + U <= F && !visited[cur + U]) {
			visited[cur + U] = visited[cur] + 1;
			q.push(cur + U);
		}
		//¾Æ·¡ÃþÀ¸·Î ÀÌµ¿
		if (cur - D > 0 && cur - D <= F && !visited[cur - D]) {
			visited[cur - D] = visited[cur] + 1;
			q.push(cur - D);
		}
	}
	//GÃþ¿¡ µµÂøÇÏÁö ¸øÇÑ °æ¿ì
	return -1;
}

int main() {
	//F:ÃþÀÇ ÃÑ °³¼ö, S:½ÃÀÛÃþ, G:µµÂøÃþ, U:À§·Î UÃþ °¡´Â ¹öÆ°, D:¾Æ·¡·Î DÃþ °¡´Â ¹öÆ°
	cin >> F >> S >> G >> U >> D;

	int result = bfs();

	//GÃþÀ¸·Î °¥ ¼ö ¾ø´Â °æ¿ì
	if (result == -1)
		cout << "use the stairs\n";
	//GÃþÀ¸·Î °¥ ¼ö ÀÖ´Â °æ¿ì
	cout << cnt << "\n";

	return 0;
}