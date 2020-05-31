//튜플
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
	return a.size() < b.size();
}
vector<int> solution(string s) {
	bool visited[100001] = { false, };
	vector<int> answer;
	vector<vector<int> > numbers;

	for (int i = 0; i< s.length(); i++) {
		//숫자인 경우
		if (s[i] >= '0' && s[i] <= '9') {
			vector<int> tmp;

			bool flag = false;
			while (!flag) {
				int tmp_num = 0;

				while (1) {
					if (s[i] == '}') { //배열 끝
						tmp.push_back(tmp_num);
						flag = true;
						break;
					}
					else if (s[i] == ',') { //숫자 끝
						tmp.push_back(tmp_num);
						tmp_num = 0;

					}
					else { //숫자면 자릿수 계산해서 저장
						tmp_num *= 10;
						tmp_num += s[i] - '0';
					}

					i++;
				}
			}
			numbers.push_back(tmp);
		}
	}
	//벡터 길이 기준으로 오름차순 정렬
	sort(numbers.begin(), numbers.end(), cmp);

	for (int i = 0; i < numbers.size(); i++) { //길이순
		for (int j = 0; j < numbers[i].size(); j++) {
			//방문하지 않은 원소 저장
			if (!visited[numbers[i][j]]) {
				visited[numbers[i][j]] = true;
				answer.push_back(numbers[i][j]);
			}
		}
	}
	return answer;
}