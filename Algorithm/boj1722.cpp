//순열의 순서
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//next_permutation() -> 시간초과
/*
입력 순열로 5 2 4 7 6 3 1 이 주어지면
인덱스 1부터 해당 숫자 만날때까지 증가시킴
순열에 없으면 (자릿수 - 1)! 더함
(1 ? ? ? ? ? ?) 6!개 + (2 ? ? ? ? ? ?) 6!개 + (3 ? ? ? ? ? ?) 6!개 + (4 ? ? ? ? ? ?) 6!개
(5 1 ? ? ? ? ?) 5!개
(5 2 1 ? ? ? ?) 4!개 + (5 2 3 ? ? ? ?) 4!개
(5 2 4 1 ? ? ?) 3!개 + (5 2 4 3 ? ? ?) 3!개 + (5 2 4 6 ? ? ?) 3!개
(5 2 4 7 1 ? ?) 2!개 + (5 2 4 7 3 ? ?) 2!개,
(5 2 4 7 6 1 ?) 1!개
이 과정을 모두 더하면 몇 번째 순열인지 확인할 수 있다. 이러한 과정을 반대로 진행하면 k번째 순열을 출력할 수 있다.
*/
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, flag;
	long long fact[21]; //1!~20! 저장
	bool visited[21]; //N 방문여부

	fact[0] = 1;
	for (int i = 1; i <= 20; i++) {
		fact[i] = fact[i - 1] * i;
	}

	cin >> N >> flag;

	//K번째 수열 출력
	if (flag == 1) {
		long long K;
		cin >> K;
		vector<int> permu;
		
		//K번째 순열 찾음
		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= N; j++) {
				//순열에 존재하면 넘어감
				if (visited[j]) continue;
				//팩토리얼 값이 K보다 작으면 K에서 팩토리얼 값만큼 빼줌
				if (fact[N - 1 - i] < K)
					K -= fact[N - 1 - i];
				//팩토리얼 값이 K보다 크면 해당원소의 숫자 찾음
				//순열에 저장
				else {
					permu.push_back(j);
					visited[j] = true;
					break;
				}
			}
		}
		//순열 출력
		for (int i = 0; i < N; i++) {
			cout << permu[i] << " ";
		}
	}

	//입력받은 수열이 몇번째 수열인지 출력
	if (flag == 2) {
		vector<int> permu;

		//주어진 순열 입력
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			permu.push_back(num); //1 3 2 4
		}

		int answer = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 1; j < permu[i]; j++) {
				if (!visited[j]) {
					answer += fact[permu.size() - 1 - i];
				}
			}
			//순열에 있는 숫자 표시
			visited[permu[i]] = true;
		}
		cout << answer + 1;
	}
	return 0;
}