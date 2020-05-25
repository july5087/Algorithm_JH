//N���� �ּҰ����
#include <vector>
using namespace std;

//�ִ�����
int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
//�ּҰ����
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
	int answer = 0;
	int temp = 1;
	while (arr.size() > 0) {
		answer = lcm(temp, arr[0]);
		arr.erase(arr.begin());
		temp = answer;
	}
	return answer;
}