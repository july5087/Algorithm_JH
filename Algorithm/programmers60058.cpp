#include <string>
#include <vector>
#include <stack>

using namespace std;

//�ùٸ� ��ȣ ���ڿ����� Ȯ��
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

//���ڿ� �Ľ�
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
	//1. �Է��� ���ڿ��� ��� �� ���ڿ� ��ȯ
	if (p == "") return "";
	//�ùٸ� ���ڿ��̸� ����
	if (isWriteBracket(p)) return p;

	//2. �������� ���ڿ� u, v�� �и�
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
	//3. ���ڿ� u�� �ùٸ� ��ȣ ���ڿ��̸� v�� ���� ���
	if (isWriteBracket(u)) {
		return u + solution(v);
	}
	//4.���ڿ� u�� �ùٸ� ��ȣ ���ڿ��� �ƴϸ�
	else {
		string temp = "";
		//4-4 ���ڿ��� ù��°�� ������ ���� ����
		string new_u = u.substr(1, u.size() - 2).c_str();
		//4-1
		temp += "(";
		//4-2
		temp += solution(v);
		//4-3
		temp += ")";
		//4-4 ��ȣ ���� ����� ����
		for (int i = 0; i<new_u.size(); i++) {
			if (new_u[i] == '(') temp += ')';
			else temp += '(';
		}
		return temp;
	}
}