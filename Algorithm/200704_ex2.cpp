#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//3�� �迭���� �������� �ִ� ������ �ִ밪
int main() {
	vector<int> arr1 = { 1,3,5,7,9,11,11 };
	vector<int> arr2 = { 1,2,3,4,5,6,7 };
	vector<int> arr3 = { 2,4,6,6,8,10,12,14,16 };
	vector<int>::iterator iter, iter2;
	int answer = -1;
	
	for (int i = arr1.size() - 1; i >= 0; i--) {
		//arr2���� arr1���� ã��
		iter = find(arr2.begin(), arr2.end(), arr1[i]);
		if (iter != arr2.end()) {
			iter2 = find(arr3.begin(), arr3.end(), *iter);
			if (iter2 != arr3.end()) {
				answer = *iter2;
				break;
			}
		}
	}
	cout << answer;
	return 0;
}