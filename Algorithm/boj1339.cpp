//단어 수학
//순열
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int N, answer = 0;
vector<string> words; //문자열
vector<char> usealpha; //쓰인 알파벳 (순열 위해 사용)
//set<char> s; //쓰인 알파벳 (중복없이 저장 위해 사용)
int alpha[26];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		// 단어 저장
		words.push_back(str); //GCF, ACDEB
		// 쓰인 알파벳을 중복없이 저장
		for (int j = 0; j < str.size(); j++) {
			//s.insert(str[j]);
			usealpha.push_back(str[j]); //G C F A D E B
		}
	}
	// 알파벳을 다시 벡터에 저장(next_permutation 하기 위해)
	/*for (auto i = s.begin(); i != s.end(); i++) {
		char c = *i;
		usealpha.push_back(c);
	}*/

	//오름차순 정렬
	sort(usealpha.begin(), usealpha.end()); //A B C C D E F G
	//중복 제거
	usealpha.erase(unique(usealpha.begin(), usealpha.end(), usealpha.end())); ////A B C D E F G

	//순열(next_permutation)
	do {
		//앞에서부터 하나씩 선택
		int num = 9; //9부터 저장
		for (int i = 0; i < usealpha.size(); i++) {
			int idx = usealpha[i] - 'A'; //A:[0] ~ Z:[26]
			alpha[idx] = num; // 9 8 7 6 5 4 3
			num--;
		}

		int sum = 0;
		for (int i = 0; i < N; i++) {
			int tmp = 0;
			for (int j = 0; j < words[i].size(); j++) {
				tmp += alpha[words[i][j] - 'A']; 
				tmp *= 10;
			}
			sum += (tmp / 10); //자릿수 더해줌
		}
		//최댓값 갱신
		answer = max(answer, sum);
	} while (next_permutation(usealpha.begin(), usealpha.end()));

	cout << answer << "\n";
	return 0;
}