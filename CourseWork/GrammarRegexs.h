

#pragma once

#include <string>
#include <regex>



using namespace std;

// String regex
const string identRegex = "[a-zA-Z]\\w*";
const string varLineRegex = "^\\s*var\\s+[a-zA-Z]\\w*\\s*;\\s*$";
const string semicolon = "^\\s*var\\s+[a-zA-Z]\\w*\\s*$";
const string startFromDigitRegex = "^\\s*var\\s+\\d[a-zA-Z1-9_]*\\s*;\\s*$";

const string ifWithoutElseRegex = "\\s*if\\s*[(]\\s*" + identRegex + "\\s*((==)|(!=)|(<)|(>))\\s*" + identRegex + "\\s*[)]\\s*[{]\\s*[}]\\s*";
const string ifWithElseRegex = ifWithoutElseRegex + "else\\s*[{]\\s*[}]\\s*";

// compiledRegex
regex ifWithoutElsePattern("^" + ifWithoutElseRegex + "$");
regex ifWithElsePattern("^" + ifWithElseRegex + "$");
regex ifPattern("^(" +  ifWithElseRegex + ")|(" + ifWithoutElseRegex + ")$");
