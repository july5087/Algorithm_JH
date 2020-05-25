//ū �� �����
#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
	string answer = "";

	int length = number.size() - k; //answer�� ����
	int start = 0;
	for (int i = 0; i<length; i++) { //��ü ���ڿ�
		char max_val = number[start];
		int max_idx = start;

		for (int j = start; j <= k + i; j++) { //�ִ밪 ã��(length�� �ݺ�)
			if (max_val < number[j]) {
				max_val = number[j];
				max_idx = j;
			}
		}
		start = max_idx + 1; //start ����(�ִ밪 ���� �ε���)
		answer += max_val; //�ִ밪 ����
	}
	return answer;
}