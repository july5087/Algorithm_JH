#include <iostream>
#include <ctime> 
using namespace std;

int solution(string p) {
	int answer = 0;
	int min = -1;
	int max = p.size();

	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '>') {
			min = i;
			break;
		}
	}
	for (int i = p.size() - 1; i >= 0; i--) {
		if (p[i] == '<') {
			max = i;
			break;
		}
	}

	if (min == max) return 0;

	// '>'�� �ִ� ���
	if (min == 0 && max == p.size()) return p.size();

	// '<'�� �ִ� ���
	if (min == -1 && max == p.size() - 1) return p.size();

	// <> <<>> <<<>>>�� ���� ���
	if (max - min < 0) return p.size();

	int impossible = max - min + 1;
	answer = p.size() - impossible;

	return answer;
}

int main() {
	clock_t start, end;
	double result;
	start = clock(); //�ð����� ����

	string s;
	cin >> s;

	cout << solution(s) << "\n";

	end = clock(); //�ð� ���� ��
	result = (double)(end - start);
	cout << "result : " << ((result) / CLOCKS_PER_SEC) << "seconds" << "\n";

	return 0;
}