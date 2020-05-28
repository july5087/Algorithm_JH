//���� �پ��� �ܾ�
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//�پ��� �ܾ� : ��� �ٸ� ���ĺ� �ҹ��ڷθ� �̷���� �ܾ�
//�پ��� �ܾ� S �־����� ��, ���� ������ S�� �ٷ� ������ ���� �پ��� �ܾ� ���
//������ -1 ���
int main() {
	string s;
	char cp_s[26];
	char alpha[] = "abcdefghijklmnopqrstuvwxyz";
	//���ڿ� S �Է�
	cin >> s;
	int length = s.size();
	//���ڿ� ����
	for (int i = 0; i<length; i++) {
		cp_s[i] = s[i];
	}

	//a ~ z ��� ���� ���
	if (length == 26) {
		//������ ���� �ܾ� ���
		//�迭 ũ�� + 1 ���ڿ� ��(��)�� ������ ����
		if (next_permutation(cp_s, cp_s + 27)) {
			cout << cp_s << "\n";
		}
		//���� ���� ������(a~z �̰ų� z~a)
		else cout << "-1\n";
	}

	else {
		//���ڿ� ���ĺ��� ����
		sort(cp_s, cp_s + length);
		//���� ���ĺ� üũ
		char to_add = ' ';
		int idx = 0;
		for (int i = 0; i < 26; i++) {
			if (cp_s[i] != alpha[i]) {
				to_add = alpha[i];
				idx = i;
				break;
			}
		}
		if (to_add == ' ')
			to_add = ++cp_s[length - 1];
		s += to_add;
		cout << s << "\n";
	}
	return 0;
}