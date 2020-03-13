//Ã¼À°º¹
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int count = 0;
	vector<int> all(n, 1);

	for (int i = 0; i<lost.size(); i++) {
		all[lost[i] - 1]--;
	}
	for (int j = 0; j<reserve.size(); j++) {
		all[reserve[j] - 1]++;
	}
	for (int k = 0; k<all.size(); k++) {
		if (all[k] == 0) {
			if (all[k + 1] == 2) {
				all[k] = 1;
				all[k + 1]--;
			}
			else if (all[k - 1] == 2) {
				all[k] = 1;
				all[k - 1]--;
			}
		}
	}
	for (int i = 0; i < all.size(); i++) {
		if (all[i] != 0) {
			count++;
		}
	}
	return count;
}