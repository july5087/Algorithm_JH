//��ɰ���
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	deque<int> temp;
	int front;
	int count;

	for (int i = 0; i<progresses.size(); i++) {
		int remain = 100 - progresses[i];
		int day = ceil((double)remain / (double)speeds[i]);
		temp.push_back(day);
	}

	front = temp[0]; //�� ��(front) ��� �۾���
	for (int j = 0; j<temp.size(); j++) {
		if (front < temp[j]) { //���� �۾��� �� ���� �ɸ��� ����
			answer.push_back(count);
			count = 1; //count �ʱ�ȭ
			front = temp[j]; //front �ʱ�ȭ
		}
		else { //�� ���� �ɸ��� count++
			count++;
		}
		if (j == temp.size() - 1) { //������ ����� �� �� ������ count ���� push
			answer.push_back(count);
		}
	}
	return answer;
}