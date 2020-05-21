#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

string press(string s, int size) {
	string press_str = "";
	string temp = "";
	int cnt = 1;

	for (int i = 0; i < s.size(); i += size) {
		string cur = s.substr(i, size).c_str();
		string next = "";
		if (i + size < s.size())
			next = s.substr(i + size, size).c_str();

		//���� ������ ��� ���� Ƚ�� ��
		if (cur == next) cnt++;
		//���� �Ұ����� ���
		else {
			//������ ����� ����� ����Ƚ�� ����
			if (cnt >= 2) press_str += to_string(cnt);
			//size��ŭ �ڸ� ���ڿ� ����
			press_str += cur;
			
			//����Ƚ�� �ʱ�ȭ
			cnt = 1;
			//���� size��ŭ ��
			continue;
		}
	}
	return press_str;
}

int solution(string s) {
	int answer = s.size();
	//��������� s/2���� 1���� �����ϰ� �����ؼ� �ּҰ� ã��
	for (int i = s.size() / 2; i >= 1; i--) {
		//����� ���ڿ�
		string result = press(s, i);
		//����� ���ڿ� ����
		int press_size = result.size();
		//�ּڰ� ����
		answer = min(answer, press_size);
	}
	return answer;
}