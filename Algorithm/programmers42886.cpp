//����
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> weight) {
	int answer = 0;

	//�� ���� ���� �������� ����
	sort(weight.begin(), weight.end());

	for (int i = 0; i < weight.size(); i++) {
		//������ �� ���� �պ��� �� ū �߰� ������ ���� �� ���� ����
		if (answer < weight[i]) break;
		
		//�� ���� ����
		answer += weight[i];
	}
	//answer-1 : ���� �߷� ���� �� �ִ� �ִ��� ��
	return answer - 1;
}
