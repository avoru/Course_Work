
// test unit

#pragma once

#include "GrammarRegexs.h"
#include <iostream>
#include <iomanip>

// positive
const string posIfElseTest1 = "if ( a < b ) {  }  else {  } "; 
const string posifElseTest2 = "if ( i == j ) {  }  else {  } "; 
const string posifElseTest3 = "if ( someIdent != some_ident2 ) {  } "; 
const string posifElseTest4 = "if  ( aasf > safsa )  {  } "; 

// negative 

const string negIfElseTest1 = "if ( 1b == b1 ) {  }  else {  } "; 
const string negIfElseTest2 = "if ( a  b ) {  }  else {  } "; 
const string negIfElseTest3 = "if ( a == b ) {    else {  } "; 
const string negIfElseTest4 = "if  ( a != b )   }  ";
const string negIfElseTest5 = "if   a != b  {  } else {   } ";

void testPos(const string& testCase,regex& pattern) {	
	cout << "test : " +  testCase + "\n" << setw(30) << " . . . "  
		 << ((regex_match(testCase,pattern))?("passed"):("failed")) << endl;  
}

void runPositiveTests() {
	cout << "Positive tests stat\n" << endl;
	testPos(posIfElseTest1, ifWithElsePattern ) ;
	testPos(posifElseTest2, ifWithElsePattern );
	testPos(posifElseTest3, ifWithoutElsePattern );
	testPos(posifElseTest4, ifWithoutElsePattern );\
	cout << endl << endl;
}

void testNeg(const string& testCase,regex& pattern) {
	cout << "test : " +  testCase + "\n" << setw(30) << " . . . " 
		 << ((!regex_match(testCase,pattern) )?("passed negative"):("failed negative")) << endl;
}

void runNegativeTests() {
	cout << "Negative tests stat\n" << endl;
	testNeg(negIfElseTest1, ifPattern );
	testNeg(negIfElseTest2, ifPattern);
	testNeg(negIfElseTest3, ifPattern);
	testNeg(negIfElseTest5, ifPattern);
	testNeg(negIfElseTest5, ifPattern);
	cout << endl << endl;
}


