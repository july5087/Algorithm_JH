//�ø��� ��ȣ
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//1. �ø����ȣ ª���� ����
//2. ���� ���� ���̰� ���ٸ�, A�� ��� �ڸ����� �հ� B�� ��� �ڸ��� �� ���� ���� ���� ������(������ �͸� ����)
//3. ���� 1,2������ �� �ȵǸ� ������ ��(���ڰ� ���ĺ����� ���������� �۴�)

bool cmp(string a, string b) {
	//���� �ٸ��� ���̼� �������� ����
	if (a.size() != b.size()) {
		return a.size() < b.size();
	}

	//���� ������ ������ ��
	else {
		int sum_a = 0, sum_b = 0;
		for (int i = 0; i < a.length(); i++) {
			if (a[i] >= '0' && a[i] <= '9') sum_a += a[i] - '0';
			if (b[i] >= '0' && b[i] <= '9') sum_b += b[i] - '0';
		}
		//������ ������ ������ ����
		if (sum_a == sum_b) return a < b;
		//������ �ٸ��� ������ ���� ����
		else return sum_a < sum_b;
	}
}

int main() {
	int N;
	vector<string> numbers;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		numbers.push_back(str);
	}

	//����
	sort(numbers.begin(), numbers.end(), cmp);

	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << "\n";
	}

	return 0;
}