//바이러스
#include <iostream>

using namespace std;

int p[101];

//최적화된 find
int Find(int x) {
	if (p[x] == x)
		return x;
	//경로 압축:find하면서 만난 모든 값의 부모노드를 root로 만듦
	else {
		int y = Find(p[x]);
		p[x] = y;
		return y;
	}
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	p[b] = a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	int computers, network;

	cin >> computers >> network;

	//초기화
	for (int i = 1; i <= computers; i++) {
		p[i] = i;
	}

	//컴퓨터 연결
	for (int i = 0; i < network; i++) {
		int a, b;
		cin >> a >> b;

		Union(a, b);
	}

	int cnt = 0;
	//루트노드가 1인 노드 검색해서 카운트
	for (int i = 2; i <= computers; i++) {
		if (Find(i) == Find(1))
			cnt++;
	}
	cout << cnt << "\n";

	return 0;
}