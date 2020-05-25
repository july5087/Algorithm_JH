//N개의 최소공배수
#include <vector>
using namespace std;

//최대공약수
int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
//최소공배수
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