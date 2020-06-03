//����Ʈ�ٹ�
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//�帣�� ����� �� ���� ��������
bool CompareGenere(pair<string, int> A, pair<string, int> B) {
	return A.second > B.second;
}

//����� ���� ��������, �ε��� ���� ��������
bool ComparePlay(pair<int, int> A, pair<int, int> B) {
	if (A.second == B.second) return A.first < B.first;
	return A.second > B.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> sums; //�帣, �� �����
	map<string, vector<pair<int, int>>> play_list; //�帣, �ε���, �����

	for (int i = 0; i < plays.size(); ++i) {
		sums[genres[i]] += plays[i]; //Ű:�帣, ��:�� ����� ����
		play_list[genres[i]].push_back(make_pair(i, plays[i])); //Ű:�帣, ��:�ε���, �����
	}

	//�� -> ���� ����
	vector<pair<string, int>> sum_of_plays(sums.begin(), sums.end()); 
	//1. �� ����� ���� �������� ����
	sort(sum_of_plays.begin(), sum_of_plays.end(), CompareGenere); 

	//�帣���� �ݺ�
	for (auto genre : sum_of_plays) { // genre : pair<string, int>
		//2. ����� ���� ��������, 3. �ε��� ���� �������� ����
		//pair<string, int> genre = sum_of_plays[i];

		sort(play_list[genre.first].begin(), play_list[genre.first].end(), ComparePlay);
		
		answer.push_back(play_list[genre.first][0].first); //�� ����� ���� ���� �帣�� ����� ���� ���� ��
		
		if (play_list[genre.first].size() > 1)
			answer.push_back(play_list[genre.first][1].first); //�� ����� ���� ���� �帣�� ����� �ι�°�� ���� ��
	}

	return answer;
}