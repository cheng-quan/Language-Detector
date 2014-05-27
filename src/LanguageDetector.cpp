/*
 * by Cheng Quan <cheng-quan@foxmail.com>
 */

#include <iostream>
#include <algorithm>
#include "Trigram.h"
#include "LanguageDetector.h"

using namespace std;

const double LanguageDetector::SIM_THRESHOLD = 0.3;

LanguageDetector::LanguageDetector() : mGramMap() {}

LanguageDetector::~LanguageDetector()
{
	for (map<string, Model*>::iterator it = mGramMap.begin(); it != mGramMap.end(); it++) {
		delete it->second;
		it->second = NULL;
	}
	mGramMap.clear();
}

bool LanguageDetector::init(const string &iModelDir, const vector<string> &languages)
{
	for (size_t i = 0; i < languages.size(); i++) {
		string langFileName = iModelDir + "/" + languages[i];
		if (mGramMap.find(languages[i]) == mGramMap.end()) {
			langFileName += "_trigram";
			Trigram* ptri = new Trigram();
			ptri->load(langFileName.c_str());
			mGramMap[languages[i]] = ptri; 
		}
	}
	return true;
}

bool compareSimPair(pair<double, string> a, pair<double, string> b)
{
	return a.first > b.first;
}

string LanguageDetector::detect(const string &iMessage)
{
	vector< pair<double, string> > simVector;

	for (map<string, Model*>::iterator it = mGramMap.begin(); it != mGramMap.end(); it++) {
		double sim = it->second->similarity(iMessage);
		simVector.push_back(pair<double, string>(sim, it->first));
	}
	stable_sort(simVector.begin(), simVector.end(), compareSimPair);
	
	if (simVector[0].first < SIM_THRESHOLD)
		return "Unknown";
	else
		return simVector[0].second;
}

double LanguageDetector::getTrigramSimilarity(const string &iMessage, const string &language)
{
	map<string, Model*>::iterator it = mGramMap.find(language);
	if (it != mGramMap.end())
		return it->second->similarity(iMessage);
	else
		return 0.0f;
}


