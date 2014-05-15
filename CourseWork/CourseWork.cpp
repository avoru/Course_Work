#include "tests.h"
#include "GrammarRegexs.h"

#define RUN_NEGATIVE
#define RUN_POSITIVE
#define USER_DIALOG_ON

void userDialog( )	{
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

		if (regex_match(inputLine, regex(startFromDigitRegex))){
			cout << "Identifier should not be started from digit!\n";
		}
	}
}



int main() {
	
#ifdef RUN_POSITIVE
	runPositiveTests();
#endif 
	
#ifdef RUN_NEGATIVE
	runNegativeTests();
#endif

#ifdef USER_DIALOG_ON
	//userDialog();
#endif 
	
	return 0;
}
