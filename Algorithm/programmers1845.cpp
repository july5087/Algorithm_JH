//���ϸ�
#include <vector>
#include <algorithm>
using namespace std;

//(N/2)���� �������� �� �� �� �ִ� ������ �ִ밪
int solution(vector<int> nums)
{
	int answer = 0;
	int ponketmon[200001];
	int choice = nums.size() / 2;
	//�ߺ� ���� ����
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());

	//(num/2)�� �ߺ������� ���� ũ�� �� ���� ���� ��
	if (nums.size() <= choice) answer = nums.size();
	else answer = choice;

	return answer;
}