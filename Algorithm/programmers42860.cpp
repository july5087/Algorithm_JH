//���̽�ƽ
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
	string a(name.size(), 'A');
	int answer = 0;
	int cur = 0, right, left;
	while (name != a) {
		if (name[cur] != 'A') {
			//��, �Ʒ� ���� ���ؼ� answer ����
			answer += min(name[cur] - 'A', 'Z' - name[cur] + 1);
			//A�� ����
			name[cur] = 'A';
		}

		//���� ��ġ ���� �ݸ�(���� ����, ������) �̵�
		for (int i = 1; i <= name.size() / 2; i++) {
			right = cur + i;
			left = cur - i;
			if (right >= name.size())
				right -= name.size();
			if (left < 0) 
				left += name.size();

			//����, ������ ���� ���ؼ� �̵� ���̸�ŭ answer ����
			if (name[right] != 'A') {
				answer += i;
				cur = right;
				break;
			}
			else if (name[left] != 'A') {
				answer += i;
				cur = left;
				break;
			}
		}
	}
	return answer;
}