#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime> 
using namespace std;

int main() {
	clock_t start, end;
	double result;
	start = clock(); //�ð����� ����

	int N;
	vector<pair<int, int>> inout;
	int toilet = 1; //ȭ��� ��

	cin >> N;

	for (int i = 0; i < N; i++) {
		int in, out;
		cin >> in >> out;
		inout.push_back({ in, out });
	}

	//�� �ð� ������ ����
	sort(inout.begin(), inout.end());

	for (int i = 0; i < N - 1; i++) {
		if (inout[i].second > inout[i + 1].first) toilet++;
	}
	cout << toilet << "\n";

	end = clock(); //�ð� ���� ��
	result = (double)(end - start);
	cout << "result : " << ((result) / CLOCKS_PER_SEC) << "seconds" << "\n";

	return 0;
}