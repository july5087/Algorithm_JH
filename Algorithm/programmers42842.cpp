//ī��
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	int all = brown + red;
	int limit = (int)sqrt(all);

	//����, ���� �׻� 3�̻�
	for (int i = 3; i <= limit; i++) {
		//������ ����� ���
		if (all % i == 0) {
			int temp = all / i; // temp > i
			//(��ü ���� - 2) * (��ü ���� - 2) == red ũ���̸�
			if ((temp - 2) * (i - 2) == red) {
				answer.push_back(temp);
				answer.push_back(i);
				break;
			}
		}
	}
	return answer;
}