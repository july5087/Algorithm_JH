//������ ǥ��
#include <iostream>
using namespace std;

int p[1000001];

int Find(int x) {
	//root�� ��� x ��ȯ
	if (p[x] == x) return x;
	else {
		//�ƴϸ� ��Ʈ ã�ư�
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

	int n, m;
	int flag, a, b;

	cin >> n >> m;

	//�ʱ�ȭ
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}

	for (int i = 0; i < m; i++) {
		cin >> flag >> a >> b;
		if (flag == 0) {
			Union(a, b);
		}
		else if (flag == 1) {
			int a_root = Find(a);
			int b_root = Find(b);

			if (a_root == b_root) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
	return 0;
}