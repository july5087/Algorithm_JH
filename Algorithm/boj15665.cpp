//N과 M(11)
//순열, 중복가능, 입력받은 수로, 중복되는 수열X
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int N, M;
//bool visited[8];

vector<int> numbers;
vector<int> v;

void Print() {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
}

void DFS(int cnt) {
	if (cnt == M) {
		Print();
		return;
	}

	bool used[10001] = { false };
	//지역변수로 초기화하는 것 중요 => 재귀를 반복할 때 마다 중복 피할 수 있음
	//재귀적으로 호출된 함수 DFS()가 종료되면 이를 호출한 부분으로 되돌아감
	//그 부분에서 for문에서 아직 index순서로 돌아가기 때문에
	//이전에 사용된 값은 !used[i]에 걸려서 중복 피할 수 있다

	for (int i = 0; i < N; i++) {
		if (!used[numbers[i]]) {
			//visited[i] = true;
			used[numbers[i]] = true;

			v.push_back(numbers[i]);
			DFS(cnt + 1);

			//초기화
			v.pop_back();
			//visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		numbers.push_back(number);
	}
	//입력받은 N개 숫자들 오름차순 정렬
	sort(numbers.begin(), numbers.end());

	DFS(0);
}