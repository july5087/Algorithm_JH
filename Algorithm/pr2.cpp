#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime> 
using namespace std;

//진수 변환
int conv_base(int num, int base) {
	string res = "";

	while (num > 0) {
		res += to_string(num % base);
		num /= base;
	}
	reverse(res.begin(), res.end());

	int ret = atoi(res.c_str());
	return ret;
}

int main() {
	clock_t start, end;
	double result;
	start = clock();
	//시간측정 시작

	vector<int> answer;
	int N = 14; //입력값
	int max_val = -1, max_base = -1;

	for (int i = 2; i < 10; i++) {
		int conv = conv_base(N, i); //n진수 변환한 값

		//자릿수곱
		string str = to_string(conv);
		int mul = 1;
		for (int k = 0; k < str.size(); k++) {
			if (str[k] != '0')
				mul *= str[k] - '0';
		}
		if (max_val <= mul) {
			max_val = mul;
			max_base = i;
		}
	}
	answer.push_back(max_base);
	answer.push_back(max_val);

	cout << answer[0] << " " << answer[1] << "\n";

	//시간측정 끝
	end = clock();
	result = (double)(end - start);
	cout << "result : " << ((result) / CLOCKS_PER_SEC) << "seconds" << "\n";

	return 0;
}