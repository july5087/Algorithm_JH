//���� ū ����
#include <vector>
using namespace std;

bool rule_two(int a, int b) {
	vector<int> v_a, v_b; //a, b 2����
	int cnt_a = 0, cnt_b = 0; //a, b 2������ 1 ����

	//2���� ��ȯ
	while (a > 0) {
		//1 ���� ī��Ʈ
		if (a % 2 == 1) cnt_a++;
		v_a.push_back(a % 2);
		a /= 2;
	}
	while (b > 0) {
		//1 ���� ī��Ʈ
		if (b % 2 == 1) cnt_b++;
		v_b.push_back(b % 2);
		b /= 2;
	}
	//2���� ���� ���� ������� ������ ������ Ȯ���ϹǷ� pass
	//1 ���� ������ Ȯ��
	if (cnt_a == cnt_b) return true;
	else return false;
}

int solution(int n) {
	int answer = 0;

	for (int i = n + 1; i <= 1000000; i++) {
		//2���� ��ȯ �� 1 ���� ������ Ȯ��
		if (rule_two(n, i)) {
			answer = i;
			break;
		}
	}
	return answer;
}