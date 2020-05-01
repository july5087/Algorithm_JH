#include <string>
#include <vector>
#include <stack>

using namespace std;

//올바른 괄호 문자열인지 확인
bool isWriteBracket(string s) {
	stack<char> st;
	for (int i = 0; i<s.size(); i++) {
		if (s[i] == '(')
			st.push(s[i]);
		if (s[i] == ')' && !st.empty())
			st.pop();
	}
	if (st.empty()) return true;
	else return false;
}

//문자열 파싱
string parsing(string s, int start, int end) {
	string str = "";
	for (int i = start; i <= end; i++) {
		str += s[i];
	}
	return str;
}

string solution(string p) {
	int left = 0, right = 0, idx = 0;
	string u = "", v = "";
	//1. 입력이 빈문자열인 경우 빈 문자열 반환
	if (p == "") return "";
	//올바른 문자열이면 리턴
	if (isWriteBracket(p)) return p;

	//2. 균형잡힌 문자열 u, v로 분리
	for (int i = 0; i<p.size(); i++) {
		if (p[i] == '(') left++;
		if (p[i] == ')') right++;
		
		if (left == right) {
			//u = parsing(p, 0, i);
			//v = parsing(p, i+1, p.size()-1);
			u = p.substr(0, i + 1).c_str();
			v = p.substr(i + 1, p.size() - i).c_str();
			break;
		}
	}
	//3. 문자열 u가 올바른 괄호 문자열이면 v에 대해 재귀
	if (isWriteBracket(u)) {
		return u + solution(v);
	}
	//4.문자열 u가 올바른 괄호 문자열이 아니면
	else {
		string temp = "";
		//4-4 문자열의 첫번째와 마지막 문자 제거
		string new_u = u.substr(1, u.size() - 2).c_str();
		//4-1
		temp += "(";
		//4-2
		temp += solution(v);
		//4-3
		temp += ")";
		//4-4 괄호 방향 뒤집어서 붙임
		for (int i = 0; i<new_u.size(); i++) {
			if (new_u[i] == '(') temp += ')';
			else temp += '(';
		}
		return temp;
	}
}