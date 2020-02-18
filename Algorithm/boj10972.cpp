#include<iostream>
#include<algorithm>
using namespace std;

int N;
int numbers[10000];

void solution() {
	if (next_permutation(numbers, numbers + N) == true) {
		for (int i = 0; i < N; i++)
			cout << numbers[i] << " ";
		cout << "\n";
	}
	else
		cout << "-1\n";
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> numbers[i];
	
	solution();
}