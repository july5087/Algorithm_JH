#include <string>
//문자열 다루기 기본
#include <vector>

using namespace std;

bool solution(string s) {
	bool answer = true;

	for (int i = 0; i<s.size(); i++) {
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
			return false;
		}
	}
	if (s.size() == 4 || s.size() == 6)
		return true;
	return false;
}