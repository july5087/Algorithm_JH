//¦���� �����ϱ�
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
	stack<char> st;

	//ù ���� ����
	st.push(s[0]);

	for (int i = 1; i<s.size(); i++) {
		//������ ����ų� �� ���ڰ� �ٸ��� push
		if (st.empty() || st.top() != s[i]) st.push(s[i]);
		//������ pop
		else st.pop();
	}
	//��� ���ŵ� ��� ������ ��(1 ����)
	if (st.empty()) return 1;
	else return 0;
}