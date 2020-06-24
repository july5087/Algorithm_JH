//�ְ��� ����
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
	vector<int> answer;
	vector<int> temp;

	//n���� ���� s�� ���� ���� �� ���� ���
	if (s / n <= 0) {
		answer.push_back(-1);
		return answer;
	}

	for (int i = 0; i<n; i++) {
		temp.push_back(s / n);
	}

	//��������ŭ ���ҿ� 1 ����
	int diff = s % n;
	for (int i = 0; i<diff; i++) {
		temp[temp.size() - 1 - i]++;
	}
	answer = temp;

	return answer;
}