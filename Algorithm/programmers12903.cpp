//가운데 글자 가져오기
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	int len = s.size();
	string result = "";

	if (len % 2 == 0) { //짝수
		result += s[len / 2 - 1];
		result += s[len / 2];
	}
	else { //홀수
		result = s[len / 2];
	}
	return result;
}