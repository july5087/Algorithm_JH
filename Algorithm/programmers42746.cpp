//가장 큰 수
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string &a, string &b) { //두 string 합친 문자열 비교해서 내림차순 정렬
	return a + b > b + a; //ex) 6, 10 있으면 610 > 106 => 6, 10 순으로 정렬
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> v;
	for (int i = 0; i<numbers.size(); i++) {
		string str = to_string(numbers.at(i));
		v.push_back(str);
	}
	sort(v.begin(), v.end(), cmp);
	for (int j = 0; j<v.size(); j++) {
		answer += v[j];
	}
	//처음 숫자가 0이면 0리턴
	//ex) numbers[0, 0, 0, 0, 0]의 경우 00000가 아닌 0 리턴
	if (answer[0] == '0')
		return "0";

	return answer;
}