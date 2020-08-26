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

	int M, C; //�޼��� ��, ������ ��
	vector<int> msglength; //�� �޼��� ����
	vector<int> msg; //�޼��� ť

	cin >> M >> C;

	//�Է�
	for (int i = 0; i < M; i++) {
		int input;
		cin >> input;
		msglength.push_back(input);
	}

	//ó���� ������ ����ŭ �� �޼���ť�� ����
	for (int i = 0; i < C; i++) {
		msg.push_back(msglength[i]);
	}

	//���� ���� �ּڰ��� ����
	for (int i = C; i < msglength.size(); i++) {
		sort(msg.begin(), msg.end());
		msg[0] += msglength[i];
	}
	//sort(msg.begin(), msg.end());
	//cout << msg[msg.size()-1] << "\n";
	int answer = *max_element(msg.begin(), msg.end());
	cout << answer << "\n";



	end = clock(); //�ð� ���� ��
	result = (double)(end - start);
	cout << "result : " << ((result) / CLOCKS_PER_SEC) << "seconds" << "\n";

	return 0;
}