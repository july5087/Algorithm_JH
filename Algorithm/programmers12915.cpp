#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;

bool mysort(string a, string b) {
	if (a.at(N) != b.at(N)) {
		return a.at(N) < b.at(N);   //N�ε����� ���ڷ� ����
	}
	else {
		return a < b;   //���������� ����
	}
	//���� �Ǵ� 0�̸� ��ü�� �ڸ��� �״�� �����Ǹ�, ����� ��쿡�� �� ��ü�� �ڸ��� �ٲ��.
}

vector<string> solution(vector<string> strings, int n) {
	vector<string> answer;
	N = n;
	answer = strings;
	sort(answer.begin(), answer.end(), mysort);
	return answer;
}