//JadenCase���ڿ� �����
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = s;

	for (int i = answer.size() - 1; i >= 0; i--) {
		//�����̸� �� ���ڸ� �빮�ڷ�
		if (answer.at(i) == ' ' && i + 1 < s.size())
			answer.at(i + 1) = toupper(answer.at(i + 1));
		//�ƴϸ� �ҹ��ڷ�
		else {
			answer.at(i) = tolower(answer.at(i));
		}
	}
	//ù���� �빮�ڷ�
	answer.at(0) = toupper(answer.at(0));

	return answer;
}