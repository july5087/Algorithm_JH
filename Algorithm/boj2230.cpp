#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, result = 2000000001;
	int arr[100001];

	//�Է�
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}	
	//����
	sort(arr, arr + n);

	//�������� �˰���
	int left = 0, right;
	while (right < n && left < n) {
		int diff = arr[right] - arr[left];
		if (diff >= m) {
			result = min(result, diff);
			left++;
		}
		else right++;
	}

	printf("%d\n", result);

	return 0;
}