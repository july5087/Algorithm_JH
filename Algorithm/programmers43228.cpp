//�Ա��ɻ�
//�̺�Ž��
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
	//�ð� �������� ����
	sort(times.begin(), times.end());
	//�ּҽð� = �ɻ��ϴµ� ���� ª�� �ɸ��� �ð�
	long long min = times[0];
	//�ִ�ð� = �ɻ��ϴµ� ���� ���� �ɸ��� �ð� * �ο���
	long long max = (long long)(times[times.size() - 1]) * n;
	long long answer = max;

	//�̺�Ž��
	while (min <= max) {
		//mid:�� �ɸ��ð�
		long long mid = (min + max) / 2;
		//sum:�� �Ա��� ��
		long long sum = 0;

		//�ɻ�� �� �Ա��� �� ����
		for (int i = 0; i < times.size(); i++)
			sum += mid / times[i];

		//n�� ��
		//�Ұ����� ��� �ð� �ø�
		if (n > sum) min = mid + 1;
		//������ ���
		else {
			//�ּҰ� ����
			if (mid <= answer) answer = mid;
			//�ð� ����
			max = mid - 1;
		}
	}
	return answer;
}