//   -  ^ - начало проверяемой строки
//   -  \\s - whitespace 
//   -   *  - означает что их может быть от 0 до безконечности
//	 -  var - точное совпадение после 
//   -  \\s+  - от 1 до безконечности пробелов
//   -  [a-zA-Z1-9_]*  - любой из последовательности символов   '*' означает что их может быть от 0 - ...
//   \\s* - пробелы
//	  ;
//	 \\s* пробелы
//		$ конец проверяемой строки
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
		//	//cout << "Ключевое слово введено не верное\n";
		//}
		if (regex_match(inputLine, regex(startFromDigitRegex))){
			cout << "Identifier should not be started from digit!\n";
			//cout << "Идентификатор не может быть просто цифрой\n";
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
