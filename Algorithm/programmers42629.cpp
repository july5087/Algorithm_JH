//������
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<int> pq;

	for (int day = 0, j = 0; day < k; day++) {
		//���� ������ ������ Ȯ��
		if (day == dates[j]) {
			//�켱������ �а��� ���� �߰�
			pq.push(supplies[j]);
			j++;
		}
		//���� ���ڶ�� ���� ����
		if (!stock) {
			stock += pq.top();
			pq.pop();
			answer++;
		}
		//���� ����
		stock--;
	}
	return answer;
}