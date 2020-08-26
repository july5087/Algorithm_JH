#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime> 
using namespace std;

int V = 6;
vector<vector<int>> bridge = { { 1,2 },{ 2,3 },{ 4,5 } }; //������, ������
bool visited[501];
int cnt = 0;

void dfs(int start) {
	visited[start] = true;

	for (int i = 0; i < bridge.size(); i++) {
		if (start == bridge[i][0]) //������
			dfs(bridge[i][1]); //������
	}
}

int main() {
	clock_t start, end;
	double result;
	start = clock(); //�ð����� ����

	for (int i = 1; i <= V; i++) { //�� �湮
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}

	cout << cnt - 1 << "\n";

	end = clock(); //�ð� ���� ��
	result = (double)(end - start);
	cout << "result : " << ((result) / CLOCKS_PER_SEC) << "seconds" << "\n";

	return 0;
}