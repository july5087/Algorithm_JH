//����ī �̷�
#include <iostream>
#include <vector>
using namespace std;

int eureka[50]; //�ﰢ�� ����

void calculate() {
	for (int i = 1; i <= 50; i++) {
		int sum = i * (i + 1) / 2;
		eureka[i - 1] = sum;
	}
}

bool isTriangle(int number) {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			for (int k = 0; k < 50; k++) {
				//�ﰢ������ �Ǻ�
				int sum = eureka[i] + eureka[j] + eureka[k];
				if (sum == number) return true;
			}
		}
	}
	return false;
}

int main() {
	int N;
	cin >> N;

	//�ﰢ�� �̸� ����ؼ� ����
	calculate();

	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;

		if (isTriangle(number)) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
}