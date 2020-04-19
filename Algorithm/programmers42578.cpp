//����
#include <string>
#include <vector>
#include <map>
using namespace std;

//�ǻ� ������ a, b, c�̸� ��� ����� ����
//(a+1) * (b+1) * (c+1) - 1;
//���� �� ���� ��� ����(+1), ��� �� ���� ��� ��(-1)

int solution(vector<vector<string>> clothes) {
	map<string, int> hash;
	int answer = 1;
	//�ǻ� ���� ����
	for (int i = 0; i < clothes.size(); i++) {
		//hash[key] = value;
		hash[clothes[i][1]]++;
	}
	map<string, int>::iterator iter;
	for (iter = hash.begin(); iter != hash.end(); iter++) {
		answer *= iter->second + 1; //���� �ǻ� �� ���� ��� ����
	}
	//��� �� ���� ��� ��
	return answer - 1;
}