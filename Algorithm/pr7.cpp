#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime> 
using namespace std;

int main() {
	clock_t start, end;
	double result;
	start = clock(); //�ð����� ����

	int a, b, c, N, cnt = 0;
	vector<int> num;
	cin >> a >> b >> c >> N;
	num.push_back(a);
	num.push_back(b);
	num.push_back(c);

	sort(num.begin(), num.end());

	do {
		cnt++;
		if (cnt == N) break;
	} while (next_permutation(num.begin(), num.end()));

	for (int i = 0; i<num.size(); i++) {
		cout << num[i];
	}
	cout << "\n";

	end = clock(); //�ð� ���� ��
	result = (double)(end - start);
	cout << "result : " << ((result) / CLOCKS_PER_SEC) << "seconds" << "\n";

	return 0;
}