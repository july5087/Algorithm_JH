//�κм����� ��
#include <iostream>
using namespace std;

int N, S;
int sequence[20];
int result;

void subset(int idx, int sum) {
	sum += sequence[idx]; //�ش� �ε��� ���� ����
	//���� ��� : ���� �ʰ�
	if (idx >= N)
		return;
	if (sum == S)
		result++;
	subset(idx + 1, sum); //�ش� �ε��� ���� ���� ���
	subset(idx + 1, sum - sequence[idx]); //�ش� �ε��� ���� �����ϰ� ���� ���
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> sequence[i];
	
	subset(0, 0);
	
	cout << result << "\n";
}