//���� �߱�
//����Ž��
#include <string>
#include <vector>

using namespace std;

bool available[10]; //0~9

bool checkStrike(int num, int guess, int strike) {
	string num_str = to_string(num);
	string guess_str = to_string(guess);
	int cnt = 0;
	
	for (int i = 0; i < num_str.size(); i++) {
		//���ڿ� ��ġ�� ������ ��Ʈ����ũ
		if (num_str[i] == guess_str[i]) cnt++;
	}
	if (cnt == strike) return true;
	return false;
}

bool checkBall(int num, int guess, int ball) {
	string num_str = to_string(num);
	string guess_str = to_string(guess);
	int cnt = 0;

	for (int i = 0; i < num_str.size(); i++) {
		for (int j = 0; j < num_str.size(); j++) {
			//���ڴ� �°� ��ġ�� Ʋ���� ��
			if (num_str[i] == guess_str[j] && i != j) cnt++;
		}
	}
	if (cnt == ball) return true;
	return false;
}

int solution(vector<vector<int>> baseball) {
	int answer = 0;

	for (int num = 123; num <= 987; num++) {
		string temp = to_string(num);
		if (temp[0] == '0' || temp[1] == '0' || temp[2] == '0') continue;
		if (temp[0] == temp[1] || temp[1] == temp[2] || temp[0] == temp[2]) continue;

		bool check = true;
		for (int i = 0; i < baseball.size(); i++) {
			//��� ����(����, ��Ʈ����ũ, �� ����) �´��� üũ
			if (!checkStrike(num, baseball[i][0], baseball[i][1]) || !checkBall(num, baseball[i][0], baseball[i][2])) {
				check = false;
			}
		}
		if (check) answer++;
	}
	return answer;
}