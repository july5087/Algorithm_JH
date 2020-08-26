#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <ctime> 
using namespace std;

int main() {
	clock_t start, end;
	double result;
	start = clock(); //시간측정 시작

	int M, C; //메세지 수, 컨슈머 수
	vector<int> msglength; //각 메세지 길이
	vector<int> msg; //메세지 큐

	cin >> M >> C;

	//입력
	for (int i = 0; i < M; i++) {
		int input;
		cin >> input;
		msglength.push_back(input);
	}

	//처음에 컨슈머 수만큼 각 메세지큐에 넣음
	for (int i = 0; i < C; i++) {
		msg.push_back(msglength[i]);
	}

	//벡터 안의 최솟값에 넣음
	for (int i = C; i < msglength.size(); i++) {
		sort(msg.begin(), msg.end());
		msg[0] += msglength[i];
	}
	//sort(msg.begin(), msg.end());
	//cout << msg[msg.size()-1] << "\n";
	int answer = *max_element(msg.begin(), msg.end());
	cout << answer << "\n";



	end = clock(); //시간 측정 끝
	result = (double)(end - start);
	cout << "result : " << ((result) / CLOCKS_PER_SEC) << "seconds" << "\n";

	return 0;
}