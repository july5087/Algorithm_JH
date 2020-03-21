//������ �簢��
using namespace std;

int getGcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return getGcd(b, a % b);
}

long long solution(int w, int h)
{
	//W, H : 1�� ������ �ڿ���
	long long W = w;
	long long H = h;

	long long gcd = getGcd(W, H); //�� ��� ����(�ִ�����)
	long long remove = (W / gcd) + (H / gcd) - 1; //��� 1�� ũ��
	remove *= gcd;

	return W * H - remove;
}