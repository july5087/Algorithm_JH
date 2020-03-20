//124 나라의 숫자
#include <string>
#include <vector>
using namespace std;

string solution(int n) {
	string answer = "";
	while (n != 0) {
		if (n % 3 == 0) { //나머지가 0인 경우는 4 추가
			//ex) n이 3일 때 나머지는 0이 되고 몫은 1
			//만약 나머지가 0일 때 4를 이어 붙인 후 1을 안빼면 몫은 1로 갱신
			//답은 14가 됨(X) => n이 3일 때는 4
			answer = "4" + answer; //기존 문자열 앞에서 추가
			n = n / 3 - 1; //
		}
		else {
			answer = to_string(n % 3) + answer;
			n /= 3;
		}
	}
	return answer;
}