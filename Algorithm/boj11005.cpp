//���� ��ȯ2
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, B;

//10���� �� N�� �־��� �� B�������� �ٲ� ���
//10���� �Ѿ�� ���� ���ڷ� ǥ���� �� ���� ��� ���ĺ� �빮�ڸ� ���
//A: 10, B: 11, ..., F: 15, ..., Y: 34, Z: 35 (2 �� B �� 36)
int main() {
	cin >> N >> B;
	vector<char> v;
	string answer;

	while (N >= 0) {
		int r = N % B;

		if (r < 10)
			answer += r + '0'; //int -> char ����ȯ
		else
			answer += r - 10 + 'A'; //int -> char ����ȯ
		N /= B;
	}
	reverse(answer.begin(), answer.end());
	cout << answer << "\n";

	return 0;	
}