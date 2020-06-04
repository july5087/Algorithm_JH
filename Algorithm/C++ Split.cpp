//C++ Split 사용

//1. split 함수 직접 구현(getline) 이용
/*
1. stringstream에 자를 string 값 입력
2. std::getline() 사용
getline(stringstream ss, string temp, char delim) => 구분자(delimiter)를 마지막에 지정
*/

//getline 직접 사용 시(구분자가 공백이 아닌 문자)
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

//getline 직접 사용 시(구분자가 공백인 문자)
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
	/* 직접 입력
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

//getline 이용해 Split 함수 구현 시
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


//2. strtok 사용
/*
1. string => char[]로 변환
2. char[]를 strtok으로 잘라냄
3. 잘라낸 char[] => 다시 string으로 변환
4. string 배열에 적재
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

	char str2[] = "가,나,다,라,마,바";
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

	char* tok3 = strtok(str3, ",-; "); //여러개 구분자 가능
	while (tok3 != NULL) {
		//cout << tok3 << endl;
		tok3 = strtok(NULL, ",-; ");
	}
}