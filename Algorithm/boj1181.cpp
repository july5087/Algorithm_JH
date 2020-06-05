//�ܾ� ����
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
	//���� ������ ���� ���� ��������(a < z)
	if (a.length() == b.length()) return a < b;
	//���� ���� ��������
	else return a.length() < b.length();
}

int main() {
	int N;
	vector<string> v;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end(), cmp);
	//�ߺ�����
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}

	return 0;
}