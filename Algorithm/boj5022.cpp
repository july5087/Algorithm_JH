//��ȭ��ȣ ���
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int T, N;
	cin >> T;

	while (T--) {
		cin >> N;
		vector<string> v;
		string answer = "";

		for (int i = 0; i < N; i++) {
			string str;
			cin >> str;
			v.push_back(str);
		}
		//���� -> ���ڿ� �����͸� Ȯ���ϸ� ��
		//�������� ������ �ð��ʰ�
		sort(v.begin(), v.end());

		bool flag = true;
		for (int i = 0; i < v.size()-1;  i++) {
			int len = v[i].size();
			if (v[i] == v[i + 1].substr(0, len)) {
				flag = false;
				break;
			}
		}
		if (!flag) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}