//거스름돈
#include <iostream>
using namespace std;


int main() {
	int input, change, cnt = 0;
	cin >> input;

	change = 1000 - input;

	//거스름돈 개수가 가장 적게
	while (change > 0) {
		if (change >= 500) change -= 500;
		else if (change >= 100) change -= 100;
		else if (change >= 50) change -= 50;
		else if (change >= 10) change -= 10;
		else if (change >= 5) change -= 5;
		else if (change >= 1) change -= 1;
		cnt++;
	}
	cout << cnt << "\n";

	return 0;
}