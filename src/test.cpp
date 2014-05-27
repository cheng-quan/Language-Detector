/*
 * by Cheng Quan <cheng-quan@foxmail.com>
 */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "LanguageDetector.h"

using namespace std;

int main()
{
	string langArray[] = {"English", "German", "Spanish", "French", "Italian", "Japanese", "Korean", "Portuguese", "Chinese", "Turkish", "Vietnamese"};
	const vector<string> languages(langArray, langArray + sizeof(langArray) / sizeof(string));

	LanguageDetector detector;
	detector.init("../configs/trigrams", languages);
		
	ifstream file("../testdata_labeled");
	if (!file.good()) {
		cerr << "Failed to open file: testdata_labeled" << endl;
		return -1;
	}

	int totalLine = 0;
	int rightLine = 0;
	string line;
	while (getline(file, line)) {
		string language = line.substr(0, 7);
		string message = line.substr(8);
		string result = detector.detect(message);
		if (language != result) {
			cout << "Message: " << message << endl;
			cout << "Language: " << language << "\t" << "Result: " << result << endl;
		} else {
			rightLine++;
		}
		totalLine++;
	}
	cout << "Accuracy: " << static_cast<double>(rightLine) / totalLine << endl;

	return 0;
}
