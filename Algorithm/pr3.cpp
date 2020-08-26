#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime> 
using namespace std;

int main() {
	clock_t start, end;
	double result;
	start = clock(); //�ð����� ����

	vector<int>	input = { 100, 101, 102, 103, 104 };
	vector<int> v_start = { 1, 2 };
	vector<int> v_end = {2, 4};
	vector<int> answer;
	int sum_first, sum_second = 0;
	//ù��° �۾�
	
	for (int i = v_start[0]; i <= v_end[0]; i++)
		sum_first += input[i];
	answer.push_back(sum_first);

	//�ι�° �۾�
	for (int i = v_start[1]; i <= v_end[1]; i++) {
		sum_second += input[i];
	}
	answer.push_back(sum_second);

	cout << answer[0] << " " << answer[1] << "\n";

	end = clock(); //�ð����� ��
	result = (double)(end - start);
	cout << "result : " << ((result) / CLOCKS_PER_SEC) << "seconds" << "\n";

	return 0;
}