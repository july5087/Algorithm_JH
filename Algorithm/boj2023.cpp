//�ű��� �Ҽ�
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int N;
vector<int> v;

//�Ҽ����� Ȯ��
bool isPrime(int num) {
	if (num == 1) return false;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}

//1~N�ڸ� �Ҽ����� Ȯ��
bool isWeirdPrime(string num) {
	string s = "";
	for (int i = 0; i<num.size(); i++) {
		s += num[i];
		if (!isPrime(stoi(s))) return false;
	}
	return true;
}

void dfs(int cnt, string s) {
	if (cnt == N) {
		cout << s << "\n";
		return;
	}
	for (int i = 1; i <= 9; i++) {
		//�ű��� �Ҽ��̸� string�� �ְ� ���� Ž��(���)
		if (isWeirdPrime(s + to_string(i))) {
			dfs(cnt + 1, s + to_string(i));
		}
	}
}

int main() {
	cin >> N;

	dfs(0, "");

	return 0;
}