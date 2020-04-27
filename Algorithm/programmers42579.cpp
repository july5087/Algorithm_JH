//베스트앨범
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
	return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> genres_cnt;
	map<string, int>::iterator iter;
	vector<pair<string, int> > v;

	//장르별로 재생수 누적
	for (int i = 0; i<genres.size(); i++)
		genres_cnt[genres[i]] += plays[i];
	//맵을 벡터에 복사
	for (iter = genres_cnt.begin(); iter != genres_cnt.end(); iter++)
		v.push_back(make_pair(iter->first, iter->second));
	//재생수 순으로 내림차순 정렬
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i<v.size(); i++) {
		int first = 0, second = 0, fidx = 0, sidx = 0;
		for (int j = 0; j<genres.size(); j++) {
			if (v[i].first == genres[j]) {
				if (plays[j] > first) {
					second = first;
					sidx = fidx;
					first = plays[j];
					fidx = j;
				}
				else if (plays[j] > second) {
					second = plays[j];
					sidx = j;
				}
			}
		}
		answer.push_back(fidx);
		//두번째 있으면 push
		if (second > 0)
			answer.push_back(sidx);
	}

	return answer;
}