#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n) {
	string answer = "";
	string word[2] = { "��","��" };

	for (int i = 0; i < n; i++) {
		answer += word[i % 2];
	}
	return answer;
}