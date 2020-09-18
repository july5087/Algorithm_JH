//����
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int H, W, rain = 0;
	int map[501]; //��� ����

	cin >> H >> W; //����, ����
	for (int i = 0; i < W; i++) {
		cin >> map[i];
	}

	//���� ��� ���� ���� ���� ���� ���� ������ ���� ���� �� ã��
	//������ (�� �� ���� ���� - ���� ��� ����)��ŭ ���� ä��
	for (int i = 1; i < W - 1; i++) {
		int cur = map[i];
		//�ִ밪 ���� ���̷� �ʱ�ȭ(���� ���̰� ���� ������ ���� 0)
		int left_max = cur, right_max = cur;

		//���� ���� ���� ��
		for (int l = 0; l < i; l++) {
			left_max = max(left_max, map[l]);
		}
		//������ ���� ���� ��
		for (int r = i + 1; r <= W - 1; r++) {
			right_max = max(right_max, map[r]);
		}
		rain += min(left_max, right_max) - cur;
	}
	cout << rain << "\n";

	return 0;
}