//��� ���� ��������
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	int len = s.size();
	string result = "";

	if (len % 2 == 0) { //¦��
		result += s[len / 2 - 1];
		result += s[len / 2];
	}
	else { //Ȧ��
		result = s[len / 2];
	}
	return result;
}