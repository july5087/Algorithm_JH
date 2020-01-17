//N�� M(11)
//����, �ߺ�����, �Է¹��� ����, �ߺ��Ǵ� ����X
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int N, M;
//bool visited[8];

vector<int> numbers;
vector<int> v;

void Print() {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
}

void DFS(int cnt) {
	if (cnt == M) {
		Print();
		return;
	}

	bool used[10001] = { false };
	//���������� �ʱ�ȭ�ϴ� �� �߿� => ��͸� �ݺ��� �� ���� �ߺ� ���� �� ����
	//��������� ȣ��� �Լ� DFS()�� ����Ǹ� �̸� ȣ���� �κ����� �ǵ��ư�
	//�� �κп��� for������ ���� index������ ���ư��� ������
	//������ ���� ���� !used[i]�� �ɷ��� �ߺ� ���� �� �ִ�

	for (int i = 0; i < N; i++) {
		if (!used[numbers[i]]) {
			//visited[i] = true;
			used[numbers[i]] = true;

			v.push_back(numbers[i]);
			DFS(cnt + 1);

			//�ʱ�ȭ
			v.pop_back();
			//visited[i] = false;
		}
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

	DFS(0);
}