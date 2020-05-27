//최솟값 만들기
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;
	sort(A.begin(), A.end());
	sort(B.rbegin(), B.rend());

	int sum = 0;
	for (int i = 0; i<A.size(); i++) {
		answer += A[i] * B[i];
	}
	return answer;
}