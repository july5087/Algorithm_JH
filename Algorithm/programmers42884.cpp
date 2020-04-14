#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
	//�ܼ�ī�޶�� ������ 1�� �̻� ��ġ, 1�� �ʱ�ȭ
	int answer = 1;
	//������ ������ ���� ���� �������� ����
	sort(routes.begin(), routes.end());
	//�ʱⰪ(ù��° �� ������ ��ġ)
	int temp = routes[0][1];
	for (int i = 0; i<routes.size() - 1; i++) {
		//������ ������ ��ġ�� ������ ������ ��ġ�� ������ temp�� ����
		if (temp > routes[i][1]) temp = routes[i][1];
		//������ �Ǵ� ������ ���� �� ������ ������ ī�޶� ��ġ
		if (temp < routes[i + 1][0]) {
			answer++;
			//������ ������ ��ġ�� temp�� ����(���� ������ ���ϱ� ����)
			temp = routes[i + 1][1];
		}
	}
	return answer;
}