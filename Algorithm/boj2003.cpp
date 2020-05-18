//������ ��2
//�������� �˰���
#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N, M, answer = 0;
	int arr[10001];

	//1. �Է�
	cin >> N >> M;
	for (long long i = 0; i < N; i++) {
		cin >> arr[i];
	}

	//2. ��������
	long long left = 0, right = 0, sum = 0;
	 while(1) {
		 //1) ���� �κ����� M �̻��̸� left++
		 if (sum >= M){
	        sum -= arr[left];
			left++;
		 }
		 //2) ���� ����� break
		 else if (right == N) break;
		 //3) �׷��� ������ right++
		 else {
			 sum += arr[right];
			 right++;
		 }
		 //4) ���� �κ����� M�� ������ ���++
		 if (sum == M) answer++;
	 }

	//3. ���
	cout << answer;
	return 0;
}
