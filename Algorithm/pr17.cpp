#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime> 
using namespace std;

int calc_doubt_index(string answer, string a, string b) {
	int doubt_num = 0; //의심 문항 수
	int sequence = 0, max_seq = 0; //연속 문항 수, 최대 연속 문항 수
	bool isSeq = false; //연속인지 확인
	int possible = 0; //부정행위 가능성 지수

	for (int i = 0; i < answer.size(); i++) {
		//의심문항인 경우
		if (answer[i] != a[i] && a[i] == b[i]) {
			if (isSeq == true) sequence++;
			else if (i == answer.size() - 1 && answer[i] != a[i] && a[i] == b[i]) sequence++; //예외:마지막 문항만 의심문항인 경우(최대 연속 문항 길이가 1)

			doubt_num++;
			isSeq = true;
		}
		else { //의심문항 아닌 경우 최대연속문항 갱신
			max_seq = max(max_seq, sequence);
			sequence = 0;
		}
		if (i == answer.size() - 1) { //마지막 문항이면서 의심문항인 경우 최대연속문항 갱신
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
	start = clock(); //시간측정 시작

	string answer_sheet = "24551"; //2
	vector<string> sheets = { "24553", "24553", "24553", "24553" };

	int question = answer_sheet.size();
	int student = sheets.size();
	int max_doubt = -1;

	for (int i = 0; i < student; i++) {
		for (int j = i + 1; j < student; j++) {
			//학생 2명끼리 부정행위 가능성 지수 계산
			int index = calc_doubt_index(answer_sheet, sheets[i], sheets[j]);
			max_doubt = max(max_doubt, index);
		}
	}

	cout << max_doubt << "\n";

	end = clock(); //시간 측정 끝
	result = (double)(end - start);
	cout << "result : " << ((result) / CLOCKS_PER_SEC) << "seconds" << "\n";

	return 0;
}