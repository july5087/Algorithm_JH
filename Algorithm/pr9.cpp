#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <ctime> 
using namespace std;

int main() {
	clock_t start, end;
	double result;
	start = clock(); //�ð����� ����

	int N, answer = 0;
	vector<int> seat;
	priority_queue<int> empty;

	//�Է�
	cin >> N;
	for (int i = 0; i<N; i++) {
		int input;
		cin >> input;
		seat.push_back(input);
	}

	int len = 0;
	//���ڸ� �� ���� �� �� ã��
	for (int i = 0; i<N; i++) {
		if (seat[i] == 0) {
			len++;
		}
		else { //���ڸ� �ƴ� ���
			empty.push(len);
			len = 0;
		}
		if (seat[i] == 0 && i == N - 1) {
			empty.push(len);
			len = 0;
		}
	}

	if (empty.top() % 2 == 0) answer = empty.top() / 2;
	else answer = empty.top() / 2 + 1;

	cout << answer << "\n";

	end = clock(); //�ð� ���� ��
	result = (double)(end - start);
	cout << "result : " << ((result) / CLOCKS_PER_SEC) << "seconds" << "\n";

	return 0;
}