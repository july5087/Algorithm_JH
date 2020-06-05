//������ ����
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//next_permutation() -> �ð��ʰ�
/*
�Է� ������ 5 2 4 7 6 3 1 �� �־�����
�ε��� 1���� �ش� ���� ���������� ������Ŵ
������ ������ (�ڸ��� - 1)! ����
(1 ? ? ? ? ? ?) 6!�� + (2 ? ? ? ? ? ?) 6!�� + (3 ? ? ? ? ? ?) 6!�� + (4 ? ? ? ? ? ?) 6!��
(5 1 ? ? ? ? ?) 5!��
(5 2 1 ? ? ? ?) 4!�� + (5 2 3 ? ? ? ?) 4!��
(5 2 4 1 ? ? ?) 3!�� + (5 2 4 3 ? ? ?) 3!�� + (5 2 4 6 ? ? ?) 3!��
(5 2 4 7 1 ? ?) 2!�� + (5 2 4 7 3 ? ?) 2!��,
(5 2 4 7 6 1 ?) 1!��
�� ������ ��� ���ϸ� �� ��° �������� Ȯ���� �� �ִ�. �̷��� ������ �ݴ�� �����ϸ� k��° ������ ����� �� �ִ�.
*/
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, flag;
	long long fact[21]; //1!~20! ����
	bool visited[21]; //N �湮����

	fact[0] = 1;
	for (int i = 1; i <= 20; i++) {
		fact[i] = fact[i - 1] * i;
	}

	cin >> N >> flag;

	//K��° ���� ���
	if (flag == 1) {
		long long K;
		cin >> K;
		vector<int> permu;
		
		//K��° ���� ã��
		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= N; j++) {
				//������ �����ϸ� �Ѿ
				if (visited[j]) continue;
				//���丮�� ���� K���� ������ K���� ���丮�� ����ŭ ����
				if (fact[N - 1 - i] < K)
					K -= fact[N - 1 - i];
				//���丮�� ���� K���� ũ�� �ش������ ���� ã��
				//������ ����
				else {
					permu.push_back(j);
					visited[j] = true;
					break;
				}
			}
		}
		//���� ���
		for (int i = 0; i < N; i++) {
			cout << permu[i] << " ";
		}
	}

	//�Է¹��� ������ ���° �������� ���
	if (flag == 2) {
		vector<int> permu;

		//�־��� ���� �Է�
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			permu.push_back(num); //1 3 2 4
		}

		int answer = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 1; j < permu[i]; j++) {
				if (!visited[j]) {
					answer += fact[permu.size() - 1 - i];
				}
			}
			//������ �ִ� ���� ǥ��
			visited[permu[i]] = true;
		}
		cout << answer + 1;
	}
	return 0;
}