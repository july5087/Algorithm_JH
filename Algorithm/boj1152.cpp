//�ܾ��� ����
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
	string input;
	//cin >> input;
	getline(cin, input); //getline���� ������� ���� �Է¹���
	stringstream ss(input);
	vector<string> v;

	string temp;
	while (ss >> temp) { 
		v.push_back(temp);
	}

	cout << v.size() << "\n";

	return 0;
}