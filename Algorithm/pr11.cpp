#include <iostream>
#include <ctime> 
using namespace std;

int main() {
	clock_t start, end;
	double result;
	start = clock(); //시간측정 시작

	int x, y;
	cin >> x >> y;
	int visited[x][y];

	int cony_x, cony_y;
	cin >> cony_x >> cony_y;

	//코니가 범위 밖으로 벗어난 경우
	if (cony_x > x || cony_y > y) cout << "fail\n";

	else {
		for (int i = 0; i < x; i++)
			visited[i][0] = 1;
		for (int i = 0; i < y; i++)
			visited[0][i] = 1;
		visited[0][0] = 0;

		//이동하는 경우의 수
		for (int i = 1; i <= cony_x; i++) {
			for (int j = 0; j <= cony_y; j++) {
				visited[i][j] = visited[i - 1][j] + visited[i][j - 1];
			}
		}
		cout << cony_x + cony_y << " " << visited[cony_x][cony_y] << "\n";
	}

	end = clock(); //시간 측정 끝
	result = (double)(end - start);
	cout << "result : " << ((result) / CLOCKS_PER_SEC) << "seconds" << "\n";

	return 0;
}