//���� ū ��
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string &a, string &b) { //�� string ��ģ ���ڿ� ���ؼ� �������� ����
	return a + b > b + a; //ex) 6, 10 ������ 610 > 106 => 6, 10 ������ ����
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
	//ó�� ���ڰ� 0�̸� 0����
	//ex) numbers[0, 0, 0, 0, 0]�� ��� 00000�� �ƴ� 0 ����
	if (answer[0] == '0')
		return "0";

	return answer;
}