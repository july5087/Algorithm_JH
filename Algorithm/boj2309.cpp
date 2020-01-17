//일곱 난쟁이
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> height;
	int sum = 0;
	int first, second;
	int input;

	//1. 9명 키 입력받고 총합 구하기
	for (int i = 0; i < 9; i++) {
		cin >> input;
		height.push_back(input);
		sum += input;
	}
	//2. 오름차순 정렬
	sort(height.begin(), height.end());

	//3. 2명 키 뺐을 때 100이 되는 조합 구하기
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - height[i] - height[j] == 100) {
				first = i;
				second = j;
				break;
			}
		}
	}
	//4. 7명 키 출력
	for (int i = 0; i < 9; i++) {
		if (i == first || i == second) continue;
		else cout << height[i] << "\n";
	}
}