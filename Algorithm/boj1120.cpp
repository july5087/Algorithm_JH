//���ڿ�
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//A�� ���̰� B�� �Ѿ�� ���� ���� starting position�� �����ذ��鼭 A�� B�� ���� �ּڰ� ã��
int main() {
	string a, b;
	cin >> a >> b;
	int answer = 50; //�ִ밪 : A, B ��� �ٸ� ���

	for (int i = 0; i <= b.size() - a.size(); i++) {
		int cnt = 0;
		for (int k = 0; k < a.size(); k++) {
			if (a[k] != b[k + i]) cnt++;
		}
		answer = min(answer, cnt);
	}
	cout << answer << "\n";

	return 0;
}