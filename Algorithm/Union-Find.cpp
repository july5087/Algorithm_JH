//Union-Find
#include <iostream>
using namespace std;

int parent[100];

int Find(int x) {
	//x로 들어온 원소의 root노드 반환
	
	if (x == parent[x]) {
		return x;
	}
	else {
		//root를 찾아감(경로 압축)
		int p = Find(parent[x]); //재귀
		parent[x] = p;
		return p;
	}
}

void Union(int x, int y) {
	//x, y원소 합침

	//2. Find
	//x에는 들어온 x의 root 노드, y에는 들어온 y의 Root 노드를 저장
	x = Find(x);
	y = Find(y);

	if (x != y) {
		// y의 root 노드를 x로 설정 -> x원소와 y원소 합침
		parent[y] = x;
	}
}

int main() {
	int n;

	cin >> n;
	
	//1. 초기화
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	//3. Union
	int x, y;
	cin >> x >> y;
	Union(x, y);
}