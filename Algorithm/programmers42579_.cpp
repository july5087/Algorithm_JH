//베스트앨범
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//장르별 재생수 합 기준 내림차순
bool CompareGenere(pair<string, int> A, pair<string, int> B) {
	return A.second > B.second;
}

//재생수 기준 내림차순, 인덱스 기준 오름차순
bool ComparePlay(pair<int, int> A, pair<int, int> B) {
	if (A.second == B.second) return A.first < B.first;
	return A.second > B.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> sums; //장르, 총 재생수
	map<string, vector<pair<int, int>>> play_list; //장르, 인덱스, 재생수

	for (int i = 0; i < plays.size(); ++i) {
		sums[genres[i]] += plays[i]; //키:장르, 값:총 재생수 누적
		play_list[genres[i]].push_back(make_pair(i, plays[i])); //키:장르, 값:인덱스, 재생수
	}

	//맵 -> 벡터 복사
	vector<pair<string, int>> sum_of_plays(sums.begin(), sums.end()); 
	//1. 총 재생수 기준 내림차순 정렬
	sort(sum_of_plays.begin(), sum_of_plays.end(), CompareGenere); 

	//장르별로 반복
	for (auto genre : sum_of_plays) { // genre : pair<string, int>
		//2. 재생수 기준 내림차순, 3. 인덱스 기준 오름차순 정렬
		//pair<string, int> genre = sum_of_plays[i];

		sort(play_list[genre.first].begin(), play_list[genre.first].end(), ComparePlay);
		
		answer.push_back(play_list[genre.first][0].first); //총 재생수 가장 많은 장르중 재생수 가장 많은 곡
		
		if (play_list[genre.first].size() > 1)
			answer.push_back(play_list[genre.first][1].first); //총 재생수 가장 많은 장르중 재생수 두번째로 많은 곡
	}

	return answer;
}