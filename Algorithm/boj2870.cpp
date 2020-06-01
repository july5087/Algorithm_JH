//수학숙제
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//숫자 모두 찾은 뒤 오름차순으로 정리(002 -> 2)
//각 문자열 100자리까지 가능 -> int, longlong으로 변환 불가

bool cmp(string a, string b) {
	//길이 다르면 길이 기준 오름차순 정렬
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	//길이 같으면 사전순 오름차순 정렬
	else return a < b;
}

int main() {
	int N;
	vector<string> v;
	vector<string> answer;

	cin >> N;
	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		v.push_back(line);
	}

	for (int i = 0; i < v.size(); i++) {
		string temp = "";
		for (int j = 0; j < v[i].size(); j++) {
			//숫자면 string에 저장
			if (v[i][j] >= '0' && v[i][j] <= '9') {
				//숫자 0 예외 처리
				if (v[i][j] == '0' && temp == "") {
					//한자리 수 0 허용
					if ((v[i][j + 1] < '0' || v[i][j + 1] > '9') && j + 1 < v[i].size()) temp += v[i][j];
					if (j == v[i].size() - 1) temp += v[i][j];
					//아니면 넣지 않음
					else continue;
				}
				else temp += v[i][j];
			}
			//숫자 아니고 temp 비었으면 벡터에 string 저장하고 초기화
			else {
				if (temp != "") {
					answer.push_back(temp);
					temp = "";
				}
				else continue;
			}
		}
		//temp에 string 남아있으면 저장
		if (temp != "") answer.push_back(temp);
	}
	//string 길이순 -> 사전순 정렬
	sort(answer.begin(), answer.end(), cmp);

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}