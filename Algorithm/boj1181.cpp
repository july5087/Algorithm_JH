//단어 정렬
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
	//길이 같으면 문자 기준 오름차순(a < z)
	if (a.length() == b.length()) return a < b;
	//길이 기준 오름차순
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
	//중복제거
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}

	return 0;
}