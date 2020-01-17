//�ϰ� ������
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> height;
	int sum = 0;
	int first, second;
	int input;

	//1. 9�� Ű �Է¹ް� ���� ���ϱ�
	for (int i = 0; i < 9; i++) {
		cin >> input;
		height.push_back(input);
		sum += input;
	}
	//2. �������� ����
	sort(height.begin(), height.end());

	//3. 2�� Ű ���� �� 100�� �Ǵ� ���� ���ϱ�
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - height[i] - height[j] == 100) {
				first = i;
				second = j;
				break;
			}
		}
	}
	//4. 7�� Ű ���
	for (int i = 0; i < 9; i++) {
		if (i == first || i == second) continue;
		else cout << height[i] << "\n";
	}
}