#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, answer_max, answer_min;
	cin >> N;
	int map[N][3], min_a[3], max_a[3];

	//ó���� ���� �ִ� 3���� ���� �߿��� �ϳ��� ��� ����
	for (int i = 0; i < N; i++) {
		int left, mid, right;
		cin >> left >> mid >> right;

		map[i][0] = left;
		map[i][1] = mid;
		map[i][2] = right;
	}
	//�ʱⰪ �Է�
	max_a[0] = min_a[0] = map[0][0];
	max_a[1] = min_a[1] = map[0][1];
	max_a[2] = min_a[2] = map[0][2];


	int max_l, max_m, max_r, min_l, min_m, min_r;
	for (int i = 1; i<N; i++) {
		max_l = min_l = map[i][0];
		max_m = min_m = map[i][1];
		max_r = min_r = map[i][2];

		//�ִ밪 ã��
		max_l += max(max_a[0], max_a[1]);
		max_m += max(max_a[0], max(max_a[1], max_a[2]));
		max_r += max(max_a[1], max_a[2]);

		//�ִ� ����
		max_a[0] = max_l;
		max_a[1] = max_m;
		max_a[2] = max_r;

		//�ּڰ� ã��
		min_l += min(min_a[0], min_a[1]);
		min_m += min(min_a[0], min(min_a[1], min_a[2]));
		min_r += min(min_a[1], min_a[2]);

		//�ּڰ� ����
		min_a[0] = min_l;
		min_a[1] = min_m;
		min_a[2] = min_r;
	}
	answer_max = max(max_a[0], max(max_a[1], max_a[2]));
	answer_min = min(min_a[0], min(min_a[1], min_a[2]));

	cout << answer_max << " " << answer_min << "\n";

	return 0;
}