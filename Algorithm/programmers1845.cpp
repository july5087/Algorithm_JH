//폰켓몬
#include <vector>
#include <algorithm>
using namespace std;

//(N/2)마리 선택했을 때 고를 수 있는 종류의 최대값
int solution(vector<int> nums)
{
	int answer = 0;
	int ponketmon[200001];
	int choice = nums.size() / 2;
	//중복 원소 제거
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());

	//(num/2)와 중복제거한 벡터 크기 중 작은 수가 답
	if (nums.size() <= choice) answer = nums.size();
	else answer = choice;

	return answer;
}