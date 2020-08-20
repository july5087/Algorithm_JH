//나이순 정렬
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(pair<int, pair<int, string>> a, pair<int, pair<int, string>> b) {
	if (a.second.first == b.second.first)
		return a < b;
	else a.second.first > b.second.first;
}

// 회원을 나이 내림차순, 나이가 같으면 가입한 순
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<pair<int, pair<int, string>>> v;

	for (int i = 0; i < n; i++) {
		int age;
		string name;
		cin >> age >> name;
		
		v.push_back({ i, { age, name } });
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << v[i].second.first << " " << v[i].second.second << "\n";
	}
}