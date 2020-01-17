//ī�� �޷�
#include<iostream>
#include<algorithm>

using namespace std;

int M, N, X, Y;

//�ִ�����(��Ŭ���� ȣ����)
int GCD(int a, int b) {

	int numA = max(a, b);
	int numB = min(a, b);

	while (numB != 0) {
		int rem = numA % numB;
		numA = numB;
		numB = rem;
	}
	return numA;
}

//�ּҰ����
int LCM(int a, int b) {
	return (a * b) / GCD(a, b);
}

//����ϱ�
int Calculate(int M, int N, int X, int Y) {
	int lcm = LCM(M, N);
	int year = X, day = 0;

	for (;;) {
		if (year > lcm) return -1;

		day = year % N;
		if (day == 0) day = N;

		if (day == Y) break;

		year += M;
		//cout << "year:" << year << ", " << "day:" << day << "\n";
	}
	return year;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> M >> N >> X >> Y;
		cout << Calculate(M, N, X, Y) << "\n";
	}
}