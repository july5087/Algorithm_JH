//위장
#include <string>
#include <vector>
#include <map>
using namespace std;

//의상 종류가 a, b, c이면 모든 경우의 수는
//(a+1) * (b+1) * (c+1) - 1;
//각각 안 입은 경우 더함(+1), 모두 안 입은 경우 뺌(-1)

int solution(vector<vector<string>> clothes) {
	map<string, int> hash;
	int answer = 1;
	//의상별 갯수 세기
	for (int i = 0; i < clothes.size(); i++) {
		//hash[key] = value;
		hash[clothes[i][1]]++;
	}
	map<string, int>::iterator iter;
	for (iter = hash.begin(); iter != hash.end(); iter++) {
		answer *= iter->second + 1; //각각 의상 안 입은 경우 더함
	}
	//모두 안 입은 경우 뺌
	return answer - 1;
}