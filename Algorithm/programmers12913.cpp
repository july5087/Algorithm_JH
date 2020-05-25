//�����Ա�
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
	int answer = 0;

	for (int i = 1; i < land.size(); ++i) {
		for (int j = 0; j < 4; ++j) {
			int cur_max = 0;
			for (int k = 0; k < 4; ++k) {
				//���� ���� �����ؼ� ���� �� ����
				if (j == k) continue;
				//���� ���� ���� ���� �� �ִ밪 ã��
				cur_max = max(cur_max, land[i - 1][k]);
			}
			// ���� ��ġ�� ����
			land[i][j] += cur_max;
		}
	}
	//�������� ������ �� �� �ִ밪 ã��
	for (int i = 0; i < 4; ++i) {
		answer = max(answer, land[land.size() - 1][i]);
	}

	return answer;
}