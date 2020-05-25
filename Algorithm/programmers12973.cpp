//짝지어 제거하기
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
	stack<char> st;

	//첫 문자 넣음
	st.push(s[0]);

	for (int i = 1; i<s.size(); i++) {
		//스택이 비었거나 두 문자가 다르면 push
		if (st.empty() || st.top() != s[i]) st.push(s[i]);
		//같으면 pop
		else st.pop();
	}
	//모두 제거된 경우 스택이 빔(1 리턴)
	if (st.empty()) return 1;
	else return 0;
}