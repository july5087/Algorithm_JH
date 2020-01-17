//N�� M(6)
//����, N�� �Է¹��� ����, �ߺ�X
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
bool visited[8];
vector<int> numbers;
vector<int> v;

void Print() {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
}

void DFS(int idx, int cnt) {
	if (cnt == M) {
		Print();
		return;
	}
	for (int i = idx; i < N; i++) {
		if (visited[i] == true) continue;
		visited[i] = true;
		v.push_back(numbers[i]);
		DFS(i, cnt + 1);

		//�ʱ�ȭ
		v.pop_back();
		visited[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		numbers.push_back(number);
	}
	//�Է¹��� N�� ���ڵ� �������� ����
	sort(numbers.begin(), numbers.end());

	DFS(0, 0);
}