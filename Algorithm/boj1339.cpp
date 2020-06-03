//�ܾ� ����
//����
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int N, answer = 0;
vector<string> words; //���ڿ�
vector<char> usealpha; //���� ���ĺ� (���� ���� ���)
//set<char> s; //���� ���ĺ� (�ߺ����� ���� ���� ���)
int alpha[26];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		// �ܾ� ����
		words.push_back(str); //GCF, ACDEB
		// ���� ���ĺ��� �ߺ����� ����
		for (int j = 0; j < str.size(); j++) {
			//s.insert(str[j]);
			usealpha.push_back(str[j]); //G C F A D E B
		}
	}
	// ���ĺ��� �ٽ� ���Ϳ� ����(next_permutation �ϱ� ����)
	/*for (auto i = s.begin(); i != s.end(); i++) {
		char c = *i;
		usealpha.push_back(c);
	}*/

	//�������� ����
	sort(usealpha.begin(), usealpha.end()); //A B C C D E F G
	//�ߺ� ����
	usealpha.erase(unique(usealpha.begin(), usealpha.end(), usealpha.end())); ////A B C D E F G

	//����(next_permutation)
	do {
		//�տ������� �ϳ��� ����
		int num = 9; //9���� ����
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
			sum += (tmp / 10); //�ڸ��� ������
		}
		//�ִ� ����
		answer = max(answer, sum);
	} while (next_permutation(usealpha.begin(), usealpha.end()));

	cout << answer << "\n";
	return 0;
}