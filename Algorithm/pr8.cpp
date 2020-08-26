#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime> 
using namespace std;

int main() {
	clock_t start, end;
	double result;
	start = clock(); //시간측정 시작

	int N;
	vector<pair<int, int>> inout;
	int toilet = 1; //화장실 수

	cin >> N;

	for (int i = 0; i < N; i++) {
		int in, out;
		cin >> in >> out;
		inout.push_back({ in, out });
	}

	//들어간 시간 순서로 정렬
	sort(inout.begin(), inout.end());

	for (int i = 0; i < N - 1; i++) {
		if (inout[i].second > inout[i + 1].first) toilet++;
	}
	cout << toilet << "\n";

	end = clock(); //시간 측정 끝
	result = (double)(end - start);
	cout << "result : " << ((result) / CLOCKS_PER_SEC) << "seconds" << "\n";

	return 0;
}