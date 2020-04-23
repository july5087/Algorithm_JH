#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 9 + 1; //�ִ밪 + 1

int N, M; //N:����, M:����
int K; //Ž�� ���� ���

bool visit[MAX];  //�湮 ���� �˻�
				  //int check[MAX]; //�ִ� �Ÿ� ���� �� 1)�ִ� ��� ã�� 2)���� ����ġ=1 �� ���

vector<int> graph[MAX]; //���� ����Ʈ

void bfs(int start) {
	queue<int> q; //��� Ž�� �� ��� ������ ť
	q.push(start);
	visit[start] = true; //�湮 ǥ��
						 //check[start] = 0; //���������� �ִܰŸ��� 0

						 // ť�� ���� ���� ��� ��� �ݺ�
						 //ť�� ���� �ִ�. => ���� �湮���� ���� ��尡 ���� �Ѵ�.
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		//printf("%d ", node); //����(���)

		for (int i = 0; i< graph[node].size(); i++) { //���� ����Ʈ �ȿ� ���� ��� ������ŭ �ݺ�
			int next = graph[node][i];
			if (!visit[next]) { // �湮���� �ʾҴٸ�
								//if(check[next] == -1)
				q.push(next); // ť�� ����
				visit[next] = true;
				//check[next] = check[node] + 1;
			}
		}
	}
}

int main(void) {
	cin >> N >> M; //����, ���� �� �Է�
	cin >> K; //Ž�� ������ ��� �Է�

			  //��������Ʈ�� ���� ����
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	//bfs Ž�� ����
	bfs(K); // ��� K���� Ž�� ����

	return 0;
}