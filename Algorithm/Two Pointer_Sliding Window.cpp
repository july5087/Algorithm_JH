//Two Pointer Algorithm
#include <iostream>
using namespace std;

int main() {
	int N, M, arr[10000];;
	cin >> N >> M;

	for (int i = 0; i<N; i++)
		cin >> arr[i];

	int result = 0, sum = 0, lo = 0, hi = 0;
	while (1) {
		if (sum >= M)
			sum -= arr[lo++];
		else if (hi == N)
			break;
		else sum += arr[hi++];
		
		if (sum == M) result++;
	}
	cout << result << "\n";
}

//Sliding Window Algorithm
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int colMax[3] = { 0 }, colMin[3] = { 0 }, tempMax[3] = { 0 }, tempMin[3] = { 0 };
	int N;
	cin >> N;

	for (int i = 0; i<N; i++) {
		for (int j = 0; j<3; j++) {
			cin >> tempMax[j];
			tempMin[j] = tempMax[j];

			tempMax[j] += max(colMax[1], (j == 1) ? max(colMax[0], colMax[2]) : colMax[j]);
			tempMin[j] += min(colMin[1], (j == 1) ? min(colMin[0], colMin[2]) : colMin[j]);
		}
		// colMax, colMin 배열을 temp 배열로 덮어쓰기하여 다음 루프에서 사용
		memcpy(colMax, tempMax, sizeof(int) * 3);
		memcpy(colMin, tempMin, sizeof(int) * 3);
	}
	sort(colMax, colMax + 3);
	sort(colMin, colMin + 3);

	cout << colMax[2] << " " << colMin[2] << "\n";
}

//https://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220795165570&parentCategoryNo=&categoryNo=299&viewDate=&isShowPopularPosts=true&from=search