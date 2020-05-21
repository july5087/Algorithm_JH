//���̸� �ִ��
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, answer;
vector<int> v;
int numbers[9];
bool visited[9];

//���� �� ���
int Calculate() {
	int diffSum = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		diffSum += abs(v[i + 1] - v[i]);
	}
	return diffSum;
}

//����
void dfs(int cnt) {
	if (cnt == N) {
		//������ �� ���ϱ�
		answer = max(answer, Calculate());
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(numbers[i]);

			dfs(cnt + 1);
			
			//�ʱ�ȭ
			visited[i] = false;
			v.pop_back();

		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}

	dfs(0);

	cout << answer << "\n";
}