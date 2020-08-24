#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <ctime> 
using namespace std;

int main() {
	clock_t start, end;
	double result;
	start = clock();
	//시간측정 시작

	vector<int> v = { 20, 8, 10, 1, 4, 15 };
	int answer = -1;

	sort(v.begin(), v.end());

	do {
		int sum = 0;
		for (int i = 0; i < v.size() - 1; i++) {
			sum += abs(v[i] - v[i + 1]);
		}
		answer = max(answer, sum);


	} while (next_permutation(v.begin(), v.end()));

	cout << answer << "\n";

	//시간측정 끝
	end = clock();
	result = (double)(end - start);
	cout << "result : " << ((result) / CLOCKS_PER_SEC) << "seconds" << "\n";

	return 0;
}