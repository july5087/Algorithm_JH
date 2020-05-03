//Union-Find
#include <iostream>
using namespace std;

int parent[100];

int Find(int x) {
	//x�� ���� ������ root��� ��ȯ
	
	if (x == parent[x]) {
		return x;
	}
	else {
		//root�� ã�ư�(��� ����)
		int p = Find(parent[x]); //���
		parent[x] = p;
		return p;
	}
}

void Union(int x, int y) {
	//x, y���� ��ħ

	//2. Find
	//x���� ���� x�� root ���, y���� ���� y�� Root ��带 ����
	x = Find(x);
	y = Find(y);

	if (x != y) {
		// y�� root ��带 x�� ���� -> x���ҿ� y���� ��ħ
		parent[y] = x;
	}
}

int main() {
	int n;

	cin >> n;
	
	//1. �ʱ�ȭ
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	//3. Union
	int x, y;
	cin >> x >> y;
	Union(x, y);
}