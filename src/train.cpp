/*
 * by Cheng Quan <cheng-quan@foxmail.com>
 */

#include <string>
#include <iostream>
#include <vector>
#include "Trigram.h"

using namespace std;

int main()
{
	string langArray[] = {"English", "German", "Spanish", "French", "Italian", "Japanese", "Korean", "Portuguese", "Chinese", "Turkish", "Vietnamese"};
	const vector<string> languages(langArray, langArray + sizeof(langArray) / sizeof(string));

	string inputDir = "../configs/corpora/";
	string outputDir = "../configs/trigrams/";
	for (size_t i = 0; i < languages.size(); i++) {
		string trainFile = inputDir + languages[i];
		string modelFile = outputDir + languages[i] + "_trigram";
		if (!Trigram::train(trainFile, modelFile)) {
			cerr << "Training failed for " << languages[i] << endl;
			return -1;
		}
	}

	return 0;
}
