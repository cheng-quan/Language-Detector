/*
 * by Cheng Quan <cheng-quan@foxmail.com>
 */

#include <string>
#include <iostream>
#include <vector>
#include "LanguageDetector.h"

using namespace std;

int main()
{
	string langArray[] = {"English", "German", "Spanish", "French", "Italian", "Japanese", "Korean", "Portuguese", "Chinese", "Turkish", "Vietnamese"};
	const vector<string> languages(langArray, langArray + sizeof(langArray) / sizeof(string));

	LanguageDetector detector;
	detector.init("../configs/trigrams", languages);
		
	string ostr("We are good friends");
	cout << detector.detect(ostr) << endl;

	return 0;
}
