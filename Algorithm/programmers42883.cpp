//큰 수 만들기
#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
	string answer = "";

	int length = number.size() - k; //answer의 길이
	int start = 0;
	for (int i = 0; i<length; i++) { //전체 문자열
		char max_val = number[start];
		int max_idx = start;

		for (int j = start; j <= k + i; j++) { //최대값 찾음(length번 반복)
			if (max_val < number[j]) {
				max_val = number[j];
				max_idx = j;
			}
		}
		start = max_idx + 1; //start 저장(최대값 다음 인덱스)
		answer += max_val; //최대값 저장
	}
	return answer;
}