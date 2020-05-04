//�� �����ϱ�
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_INT 101

int p[MAX_INT];

//��Ʈ ��� ã��
int Find(int x) {
	if (x == p[x])
		return x;
	else
		return p[x] = Find(p[x]);
}

bool cmp(vector<int> &a, vector<int> &b) {
	//���� ����ġ
	return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	//1. Disjoint set �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		p[i] = i;
	}
	//2. ����ġ ���� �������� ����
	sort(costs.begin(), costs.end(), cmp);

	//3. ��� ���� �˻�
	for (int i = 0; i < costs.size(); i++) {
		int start = costs[i][0]; //���� ����� ��Ʈ���
		int end = costs[i][1]; //�� ����� ��Ʈ���
		int cost = costs[i][2];
		//4. start�� end�� ���� ������� �ʾҴٸ�(��Ʈ ��尡 ���� ������)
		if (start != end) {
			//1) start�� �θ��带 end�� ����
			p[start] = end;
			//2) ������ ����ġ�� ����� ������
			answer += cost;
		}
	}
	return answer;
}