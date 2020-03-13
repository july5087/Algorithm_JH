//문자열 내림차순으로 배치하기
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
	string answer;
	sort(s.rbegin(), s.rend());
	answer = s;
	return answer;
}