/*
 * by Cheng Quan <cheng-quan@foxmail.com>
 */

#ifndef _LanguageDetector_h_
#define _LanguageDetector_h_

#include <string>
#include <map>
#include <vector>

class Model;

class LanguageDetector {
public:
	LanguageDetector();
	~LanguageDetector();

	bool init(const std::string &iModelDir, const std::vector<std::string> &languages);
	std::string detect(const std::string &iMessage);
	double getTrigramSimilarity(const std::string &iMessage, const std::string &language);
private:
	std::map<std::string, Model*> mGramMap;
	const static double SIM_THRESHOLD;
};

#endif
