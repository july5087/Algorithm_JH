//����Ʈ
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int visited[50001];

int solution(vector<int> people, int limit) {
	int answer = 0;
	int cnt = 0;
	//���� ���� �������� ����
	sort(people.begin(), people.end());

	int light = 0;
	int heavy = people.size() - 1;

	while (light <= heavy) {
		//�ּ� + �ִ� ���� Ÿ�� ���
		if (people[light] + people[heavy] <= limit) {
			//�ּ�, �ִ� ���� Ž
			light++;
			heavy--;
		}
		//�ּ� + �ִ� ���� ��Ÿ�� ���
		else {
			//�ִ� ȥ�� Ž
			heavy--;
		}
		//�ּ� + �ִ� ���� Ÿ�� ��� => 1�� �߰�
		//�ּ� + �ִ� ���� ��Ÿ�� ���:�ִ� ȥ�� Ž => 1�� �߰�
		answer++;
	}
	return answer;
}