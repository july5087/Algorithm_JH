//���� ����
#include <iostream>
#include <vector>
#include <queue>
#define MAX 10
using namespace std;

int N; //���� ����
int inDegree[MAX]; //�� ����� ���� ����
vector<int> a[MAX]; //���� �׷���

void TopologySort() {
	//int result[MAX]; //�������� ���
	queue<int> q;
	
	//���� ������ 0�� ��带 ť�� ����
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	//N���� ��带 �湮 => ��� �湮�ϸ� ���� ���� ����
	for (int i = 1; i <= N; i++) {
		//N���� �湮�ϱ� ���� ť�� ��� ����Ŭ �߻� 
		if (q.empty()) return;

		//ť���� ���� ����
		int x = q.front();
		q.pop();
		//result[i] = x;
		cout << x << " "; //��� ���
		
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			inDegree[y]--; //����� ���� ����

			// 3. ���Ӱ� ���������� 0�� �� ������ ť�� ���� 
			if (inDegree[y] == 0)
				q.push(y);
		}
	}
	/*for (int i = 1; i <= N; i++) {
		cout << result[i] << "\n";
	}*/
}

int main(void) {
	cin >> N; //���� ���� �Է�

	for (int i = 0; i < N; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		a[v1].push_back(v2); //v1 -> v2 ���� �Է�
		inDegree[v2]++; //v2 �������� ����
	}
	//���� ����
	TopologySort();
}