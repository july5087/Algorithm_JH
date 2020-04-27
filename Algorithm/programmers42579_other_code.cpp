//����Ʈ�ٹ�
//�ٸ� �ڵ� ����
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool CompareGenere(pair<string, int> A, pair<string, int> B)
{
	//����� ���� �������� ����
	return A.second > B.second;
}

bool ComparePlay(pair<int, int> A, pair<int, int> B)
{
	//����� ������ �ε��� ���� ������������ ����
	if (A.second == B.second)
		return A.first < B.first;
	//����� ���� �������� ����
	return A.second > B.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> sums; //����� ����
	map<string, vector<pair<int, int>>> play_list;

	for (int i = 0; i < plays.size(); ++i)
	{
		//�帣�� ����� ����
		sums[genres[i]] += plays[i];
		//key(�帣)�� value(�ε���, �����)����
		play_list[genres[i]].push_back(make_pair(i, plays[i]));
	}
	//���� ���� ���� ���ͷ� ��ȯ
	vector<pair<string, int>> sum_of_plays(sums.begin(), sums.end());
	//����� ���� �������� ����
	sort(sum_of_plays.begin(), sum_of_plays.end(), CompareGenere);

	for (auto genere : sum_of_plays)
	{
		//���� �帣 �� ����� ���� �������� ����
		sort(play_list[genere.first].begin(), play_list[genere.first].end(), ComparePlay);
		//�帣 �� ù��° �ִ� �����
		answer.push_back(play_list[genere.first][0].first);
		if (play_list[genere.first].size() > 1)
			//�帣 �� �ι�° �ִ� �����
			answer.push_back(play_list[genere.first][1].first);
	}
	return answer;
}