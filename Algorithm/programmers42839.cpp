//�Ҽ� ã��
#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool visited[10000000]; //numbers:���� 1 �̻� 7 ���� ���ڿ�
bool used[10]; //0~9 ��� ����
vector<char> cur_num;
int answer;

bool IsPrime(int num) {
	if (num == 0 || num == 1) return false;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

void DFS(string numbers, string currStr) {
	//����
	if (currStr != "" && !visited[stoi(currStr)]) {
		visited[stoi(currStr)] = true;
		//���� ������ Ȯ�� �������� �Ҽ� �Ǻ�
		if (IsPrime(stoi(currStr))) {
			answer++;
		}
	}
	for (int i = 0; i < numbers.size(); i++) {
		if (!used[i]) {
			used[i] = true;
			DFS(numbers, currStr + numbers[i]);
			used[i] = false;
		}
	}
}

int solution(string numbers) {
	DFS(numbers, "");
	return answer;
}