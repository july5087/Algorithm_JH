//������ ��ġ
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;
	int idx = 0;
	int location = 1;

	while (location <= n) {
		//������ ���� ��ġ�� ����(���� ����)�ȿ� ���� ��ġ �ִ��� Ȯ��
		if (idx<stations.size() && location >= stations[idx] - w) {
			location = stations[idx] + w + 1;
			idx++;
		}
		//���� �ȿ� ������ 
		else {
			//������ ��ġ
			answer++;
			//���� ���̸�ŭ ���� ��ġ �̵�
			location += (2 * w) + 1;
		}
	}
	return answer;
}