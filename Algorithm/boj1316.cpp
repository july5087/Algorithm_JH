//�׷� �ܾ� üĿ
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//�׷� �ܾ�:�ܾ �����ϴ� ��� ���ڿ� ���� �� ���ڰ� �����ؼ� ��Ÿ���� ���
int main() {
	bool used[27] = { false, }; //���ĺ� ��� ����
	int N, cnt = 0;
	cin >> N;

	while (N--) {
		string input;
		cin >> input;

		//�׽�Ʈ���̽����� �ʱ�ȭ
		bool groupword = true;
		memset(used, false, sizeof(used));

		for (int i = 1; i<input.size(); i++) {
			char prev = input[i - 1];
			used[input[i - 1] - 'a' + 1] = true;
			//���� ���ĺ��� ���� �ʰ� ����� �� ������ �׷�ܾ �ƴ�
			if (prev != input[i] && used[input[i] - 'a' + 1]) {
				groupword = false;
				break;
			}
		}
		if (groupword) cnt++;
	}
	cout << cnt;

	return 0;
}