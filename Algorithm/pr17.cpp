#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime> 
using namespace std;

int calc_doubt_index(string answer, string a, string b) {
	int doubt_num = 0; //�ǽ� ���� ��
	int sequence = 0, max_seq = 0; //���� ���� ��, �ִ� ���� ���� ��
	bool isSeq = false; //�������� Ȯ��
	int possible = 0; //�������� ���ɼ� ����

	for (int i = 0; i < answer.size(); i++) {
		//�ǽɹ����� ���
		if (answer[i] != a[i] && a[i] == b[i]) {
			if (isSeq == true) sequence++;
			else if (i == answer.size() - 1 && answer[i] != a[i] && a[i] == b[i]) sequence++; //����:������ ���׸� �ǽɹ����� ���(�ִ� ���� ���� ���̰� 1)

			doubt_num++;
			isSeq = true;
		}
		else { //�ǽɹ��� �ƴ� ��� �ִ뿬�ӹ��� ����
			max_seq = max(max_seq, sequence);
			sequence = 0;
		}
		if (i == answer.size() - 1) { //������ �����̸鼭 �ǽɹ����� ��� �ִ뿬�ӹ��� ����
									  //cout << "end:" <<max_seq << " " << sequence <<"\n";
			max_seq = max(max_seq, sequence);
			sequence = 0;
		}
	}
	//cout << doubt_num << " " << max_seq << "\n";
	possible = doubt_num + pow(max_seq, 2);
	return possible;
}

int main() {
	clock_t start, end;
	double result;
	start = clock(); //�ð����� ����

	string answer_sheet = "24551"; //2
	vector<string> sheets = { "24553", "24553", "24553", "24553" };

	int question = answer_sheet.size();
	int student = sheets.size();
	int max_doubt = -1;

	for (int i = 0; i < student; i++) {
		for (int j = i + 1; j < student; j++) {
			//�л� 2���� �������� ���ɼ� ���� ���
			int index = calc_doubt_index(answer_sheet, sheets[i], sheets[j]);
			max_doubt = max(max_doubt, index);
		}
	}

	cout << max_doubt << "\n";

	end = clock(); //�ð� ���� ��
	result = (double)(end - start);
	cout << "result : " << ((result) / CLOCKS_PER_SEC) << "seconds" << "\n";

	return 0;
}