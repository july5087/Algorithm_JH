//���� �� �Ӹ����
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solution(string s)
{
	for (int len = s.size(); len > 1; len--) { //�κй��ڿ� ����
		for (int start = 0; start + len <= s.size(); start++) { //s�� ������
			bool flag = true;

			//�Ӹ���� ���� �˻�(���ڿ� ������ �ݱ���)
			for (int i = 0; i<len / 2; i++) {
				if (s[start + i] != s[start + len - i - 1]) {
					flag = false;
					break;
				}
			}
			if (flag) return len;
		}
	}
	return 1;
}