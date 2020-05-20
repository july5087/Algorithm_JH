//JadenCase문자열 만들기
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = s;

	for (int i = answer.size() - 1; i >= 0; i--) {
		//공백이면 뒤 문자를 대문자로
		if (answer.at(i) == ' ' && i + 1 < s.size())
			answer.at(i + 1) = toupper(answer.at(i + 1));
		//아니면 소문자로
		else {
			answer.at(i) = tolower(answer.at(i));
		}
	}
	//첫문자 대문자로
	answer.at(0) = toupper(answer.at(0));

	return answer;
}