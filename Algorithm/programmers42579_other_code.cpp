//베스트앨범
//다른 코드 참고
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool CompareGenere(pair<string, int> A, pair<string, int> B)
{
	//재생수 기준 내림차순 정렬
	return A.second > B.second;
}

bool ComparePlay(pair<int, int> A, pair<int, int> B)
{
	//재생수 같으면 인덱스 기준 오름차순으로 정렬
	if (A.second == B.second)
		return A.first < B.first;
	//재생수 기준 내림차순 정렬
	return A.second > B.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> sums; //재생수 누적
	map<string, vector<pair<int, int>>> play_list;

	for (int i = 0; i < plays.size(); ++i)
	{
		//장르별 재생수 누적
		sums[genres[i]] += plays[i];
		//key(장르)에 value(인덱스, 재생수)저장
		play_list[genres[i]].push_back(make_pair(i, plays[i]));
	}
	//정렬 위해 맵을 벡터로 변환
	vector<pair<string, int>> sum_of_plays(sums.begin(), sums.end());
	//재생수 기준 내림차순 정렬
	sort(sum_of_plays.begin(), sum_of_plays.end(), CompareGenere);

	for (auto genere : sum_of_plays)
	{
		//같은 장르 내 재생수 기준 내림차순 정렬
		sort(play_list[genere.first].begin(), play_list[genere.first].end(), ComparePlay);
		//장르 내 첫번째 최다 재생곡
		answer.push_back(play_list[genere.first][0].first);
		if (play_list[genere.first].size() > 1)
			//장르 내 두번째 최다 재생곡
			answer.push_back(play_list[genere.first][1].first);
	}
	return answer;
}