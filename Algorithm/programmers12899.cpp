//124 ������ ����
#include <string>
#include <vector>
using namespace std;

string solution(int n) {
	string answer = "";
	while (n != 0) {
		if (n % 3 == 0) { //�������� 0�� ���� 4 �߰�
			//ex) n�� 3�� �� �������� 0�� �ǰ� ���� 1
			//���� �������� 0�� �� 4�� �̾� ���� �� 1�� �Ȼ��� ���� 1�� ����
			//���� 14�� ��(X) => n�� 3�� ���� 4
			answer = "4" + answer; //���� ���ڿ� �տ��� �߰�
			n = n / 3 - 1; //
		}
		else {
			answer = to_string(n % 3) + answer;
			n /= 3;
		}
	}
	return answer;
}