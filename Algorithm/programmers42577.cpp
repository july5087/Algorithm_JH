//전화번호 목록
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
	for (int i = 0; i<phone_book.size() - 1; i++) {
		for (int j = 0; j<phone_book.size(); j++) {
			if (i != j && phone_book[i].size() <= phone_book[j].size()) {
				bool flag = false;
				for (int k = 0; k<phone_book[i].size(); k++) {
					if (phone_book[i][k] == phone_book[j][k]) {
						flag = true;
					}
					else {
						flag = false;
						break;
					}
				}
				if (flag) {
					return false;
				}
			}
		}
	}
	return true;
}