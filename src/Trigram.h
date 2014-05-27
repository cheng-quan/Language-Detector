/*
 * by Cheng Quan <cheng-quan@foxmail.com>
 */

#ifndef _Trigram_h_
#define _Trigram_h_

#include <string>
#include "Trie.h"
#include "Model.h"

class Trigram : public Model {
public:
	Trigram();
	virtual ~Trigram();

	virtual double similarity(const std::string& iMessage);	
	static bool train(const std::string &iTrainFileName, const std::string &iModelFileName);

	bool load(const std::string &iFileName);
	bool save(const std::string &iFileName);

private:
	// for no copy
	Trigram(const Trigram& tr);
	const Trigram& operator=(const Trigram& tr);

	Trie m_trie;
};

#endif

