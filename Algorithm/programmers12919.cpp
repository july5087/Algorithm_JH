//���￡�� �輭�� ã��
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
	string answer = "";
	answer += "�輭���� ";

	for (int i = 0; i<seoul.size(); i++) {
		if (seoul[i] == "Kim")
			answer += to_string(i); //int->string ��ȯ �ʿ�
	}

	answer += "�� �ִ�";
	return answer;
}