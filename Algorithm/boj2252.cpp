//�ټ����
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100001

int main() {
	int N, M; //�л� ��, �� ��(����, ����)
	int inDegree[MAX]; //���� ����
	vector<int> a[MAX]; //���� �׷���
	queue<int> q; 
	
	cin >> N >> M;

	//���� �Է�
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B; //A->B (A > B)
		a[A].push_back(B);
		inDegree[B]++;
	}
	
	//��� ���� �˻��� ���������� 0�� ��� ť�� ����
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	while(!q.empty()){
		int x = q.front();
		q.pop();
		cout << x << " "; //ť���� ���� ���� ���

		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i]; //����� ����
			inDegree[y]--; //���� ����

			if (inDegree[y] == 0) q.push(y);
		}
	}
	cout << "\n";

	return 0;
}