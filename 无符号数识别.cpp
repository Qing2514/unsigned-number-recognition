#include<iostream>
using namespace std;

bool isNumeric(string s) {

	int index1 = 0;	// ��¼'.'λ��
	int index2 = 0;	// ��¼'E'λ��
	int index3 = 0;	// ��¼'+|-'λ��

	for (int i = 0; i < s.length(); i++) {

		// ���ڲ��ó��ֵ��ַ���ֱ�ӷ���false
		if ((s[i] > '9' || s[i] < '0') && s[i] != 'E' && s[i] != '.' && s[i] != '+' && s[i] != '-') {
			cout << "this is not a number" << endl << endl;
			return false;
		}



		// ����'.'���ţ����䲻�ڵ�һλ��index1Ϊ0����ʾ'.'δ���ֹ�����λ�ø�ֵ��index1
		if (s[i] == '.') {
			if (index1 != 0 || i == 0)	return false;
			else index1 = i;
		}

		// ����'E'���ţ����䲻�ڵ�һλ��index2Ϊ0����ʾ'E'δ���ֹ�����λ�ø�ֵ��index2
		else if (s[i] == 'E') {
			if (index2 != 0 || i == 0)	return false;
			else index2 = i;
		}

		// ����'+|-'���ţ����䲻�ڵ�һλ��index3Ϊ0����ʾ'+|-'δ���ֹ�����λ�ø�ֵ��index3
		else if (s[i] == '+' || s[i] == '-') {
			if (index3 != 0 || i == 0)	return false;
			else index3 = i;
		}



		// ��ͬʱ����'.'��'E'��'.'���������'E'֮ǰ
		if (index1 != 0 && index2 != 0 && index1 > index2) {
			cout << "false, 'E' is not behind '.'" << endl << endl;
			return false;
		}

		// ������'+|-'����������'E'
		else if (index2 == 0 && index3 != 0) {
			cout << "false, only exits '+|-'" << endl << endl;
			return false;
		}

		// ��ͬʱ����'E'��'+|-'��'E'���������'+|-'ǰһλ
		else if (index2 != 0 && index3 != 0 && index2 + 1 != index3) {
			cout << "false, '+|-' must be after with 'E'" << endl << endl;
			return false;
		}

		// �������Ŷ�����λ�����һλ
		else if (index1 == s.length() - 1) {
			cout << "false, '.' in the last" << endl << endl;
			return false;
		}
		else if (index2 == s.length() - 1) {
			cout << "false, 'E' in the last" << endl << endl;
			return false;
		}
		else if (index3 == s.length() - 1) {
			cout << "false, '+|-' in the last" << endl << endl;
			return false;
		}

	}

	cout << "true" << endl << endl;
	return true;
}

int main() {

	string s;

	while (cin >> s)
		isNumeric(s);

	return 0;
}