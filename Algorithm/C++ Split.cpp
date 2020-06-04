//C++ Split ���

//1. split �Լ� ���� ����(getline) �̿�
/*
1. stringstream�� �ڸ� string �� �Է�
2. std::getline() ���
getline(stringstream ss, string temp, char delim) => ������(delimiter)�� �������� ����
*/

//getline ���� ��� ��(�����ڰ� ������ �ƴ� ����)
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int main()
{
	string line = "data1,data2,data3";
	vector<string> result;
	stringstream ss(line); //1
	string temp;

	//from, to, delim
	while (getline(ss, temp, ',')) { //2
		result.push_back(temp);
	}
	return 0;
}

//getline ���� ��� ��(�����ڰ� ������ ����)
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
	/* ���� �Է�
	string str; 
	getline(cin, str); */
	string str = "ABC DEF GHI";
	stringstream ss(str);

	vector<string> v;
	string temp;

	while (ss >> temp) {
		v.push_back(temp);
	}
}

//getline �̿��� Split �Լ� ���� ��
vector<string> Split(string str, char delimiter)
{
	vector<string> ret;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		ret.push_back(temp);
	}

	return ret;
}


//2. strtok ���
/*
1. string => char[]�� ��ȯ
2. char[]�� strtok���� �߶�
3. �߶� char[] => �ٽ� string���� ��ȯ
4. string �迭�� ����
*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
	string str1 = "a b c d e f";
	char *buff = new char[1000];
	strcpy(buff, str1.c_str());

	char str2[] = "��,��,��,��,��,��";
	char str3[] = "1,2-3;4 5";
	vector<string> result;

	char* tok1 = strtok(buff, " ");
	while (tok1 != NULL) {
		//cout << tok1 << endl;
		result.push_back(tok1);
		tok1 = strtok(NULL, " ");
	}

	char* tok2 = strtok(str2, ",");
	while (tok2 != NULL) {
		//cout << tok2 << endl;
		tok2 = strtok(NULL, ",");
	}

	char* tok3 = strtok(str3, ",-; "); //������ ������ ����
	while (tok3 != NULL) {
		//cout << tok3 << endl;
		tok3 = strtok(NULL, ",-; ");
	}
}