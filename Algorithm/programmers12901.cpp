//2016³â
#include<iostream>
#include<string>
using namespace std;

string solution(int a, int b)
{
	string day[] = { "THU","FRI","SAT","SUN","MON","TUE","WED" };
	int month[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int sum = 0;

	for (int i = 0; i<a - 1; i++) {
		sum += month[i];
	}
	sum += b;
	return day[sum % 7];
}