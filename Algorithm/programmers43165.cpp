//Ÿ�� �ѹ�
#include <string>
#include <vector>
using namespace std;

int answer = 0;
void dfs(vector<int> numbers, int target, int sum, int count) {
	//��� Ż�� ����
	if (count == numbers.size()) {
		if (sum == target) answer++;
		return;
	}
	//�ش� ���� ������ �� ��
	dfs(numbers, target, sum + numbers[count], count + 1);
	//�ش� ���� ���� �� ��
	dfs(numbers, target, sum - numbers[count], count + 1);
}

int solution(vector<int> numbers, int target) {
	dfs(numbers, target, 0, 0);
	return answer;
}