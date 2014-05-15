//   -  ^ - ������ ����������� ������
//   -  \\s - whitespace 
//   -   *  - �������� ��� �� ����� ���� �� 0 �� �������������
//	 -  var - ������ ���������� ����� 
//   -  \\s+  - �� 1 �� ������������� ��������
//   -  [a-zA-Z1-9_]*  - ����� �� ������������������ ��������   '*' �������� ��� �� ����� ���� �� 0 - ...
//   \\s* - �������
//	  ;
//	 \\s* �������
//		$ ����� ����������� ������
#include "stdafx.h"
#include <iostream>
#include <regex>	

using namespace std;
int main() {
	setlocale(0, "");
	const string varLineRegex = "^\\s*var\\s+[a-zA-Z]\\w*\\s*;\\s*$";
	const string semicolon = "^\\s*var\\s+[a-zA-Z]\\w*\\s*$";
	const string startFromDigitRegex = "^\\s*var\\s+\\d[a-zA-Z1-9_]*\\s*;\\s*$";
	//const string ifelse = "^\\s*if\\s+[a-zA-Z]\\w*\\s*[==!%><+-*/]\\s+[a-zA-Z]\\w*[)][{]\\s*[}]\\s*$";
	//const string key_word = "^\\s*w[a-zA-Z1-9_]*\\s+\\w[a-zA-Z1-9_]*\\s*;\\s*$";
	string inputLine;

	cout << "Input line to check : ";
	getline(cin, inputLine, '\n');
	

	if(regex_match(inputLine,regex(varLineRegex))) {
		cout << "Your line is ok" << endl;
	}
	else {
		cout << "Your line is not ok" << endl;
		if (regex_match(inputLine, regex(semicolon))){
			cout << "Semicolon is missing!\n";
		}
		//if (regex_match(inputLine, regex(key_word))){
		//	//cout << "�������� ����� ������� �� ������\n";
		//}
		if (regex_match(inputLine, regex(startFromDigitRegex))){
			cout << "Identifier should not be started from digit!\n";
			//cout << "������������� �� ����� ���� ������ ������\n";
		}
	}
	if (regex_match(inputLine, regex(ifelse)))
	{
		cout << "if else wrote ok";
	}
	else
	{
		cout << "if else wrote not ok";
	}
	cin.get();
	return main();
}
