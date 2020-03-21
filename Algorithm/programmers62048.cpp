//멀쩡한 사각형
using namespace std;

int getGcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return getGcd(b, a % b);
}

long long solution(int w, int h)
{
	//W, H : 1억 이하의 자연수
	long long W = w;
	long long H = h;

	long long gcd = getGcd(W, H); //총 블록 갯수(최대공약수)
	long long remove = (W / gcd) + (H / gcd) - 1; //블록 1개 크기
	remove *= gcd;

	return W * H - remove;
}