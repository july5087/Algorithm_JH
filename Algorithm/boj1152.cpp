//단어의 개수
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
	string input;
	//cin >> input;
	getline(cin, input); //getline으로 공백까지 같이 입력받음
	stringstream ss(input);
	vector<string> v;

	string temp;
	while (ss >> temp) { 
		v.push_back(temp);
	}

	cout << v.size() << "\n";

	return 0;
}