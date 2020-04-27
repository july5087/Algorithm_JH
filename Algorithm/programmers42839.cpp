//소수 찾기
#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool visited[10000000]; //numbers:길이 1 이상 7 이하 문자열
bool used[10]; //0~9 사용 여부
vector<char> cur_num;
int answer;

bool IsPrime(int num) {
	if (num == 0 || num == 1) return false;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

void DFS(string numbers, string currStr) {
	//순열
	if (currStr != "" && !visited[stoi(currStr)]) {
		visited[stoi(currStr)] = true;
		//숫자 이전에 확인 안했으면 소수 판별
		if (IsPrime(stoi(currStr))) {
			answer++;
		}
	}
	for (int i = 0; i < numbers.size(); i++) {
		if (!used[i]) {
			used[i] = true;
			DFS(numbers, currStr + numbers[i]);
			used[i] = false;
		}
	}
}

int solution(string numbers) {
	DFS(numbers, "");
	return answer;
}