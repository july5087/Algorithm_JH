//���̷���
#include <iostream>

using namespace std;

int p[101];

//����ȭ�� find
int Find(int x) {
	if (p[x] == x)
		return x;
	//��� ����:find�ϸ鼭 ���� ��� ���� �θ��带 root�� ����
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

	//�ʱ�ȭ
	for (int i = 1; i <= computers; i++) {
		p[i] = i;
	}

	//��ǻ�� ����
	for (int i = 0; i < network; i++) {
		int a, b;
		cin >> a >> b;

		Union(a, b);
	}

	int cnt = 0;
	//��Ʈ��尡 1�� ��� �˻��ؼ� ī��Ʈ
	for (int i = 2; i <= computers; i++) {
		if (Find(i) == Find(1))
			cnt++;
	}
	cout << cnt << "\n";

	return 0;
}