//이상한 문자 만들기
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	int index = 0;

	for (int i = 0; i<s.size(); i++) {
		if (s[i] == ' ') {
			index = 0;
		}
		else {
			index++;
		}
		if (index % 2 == 1)
			s[i] = toupper(s[i]);
		else
			s[i] = tolower(s[i]);
	}
	answer = s;

	return answer;
}