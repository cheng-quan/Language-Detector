/*
 * by Cheng Quan <cheng-quan@foxmail.com>
 */

#include <iostream>
#include <fstream>
#include <map>
#include "Trigram.h"

using namespace std;

Trigram::Trigram() : m_trie() {}

Trigram::~Trigram() {}

bool Trigram::load(const string &iFileName )
{
	return m_trie.load(iFileName);
}

bool Trigram::save(const string &iFileName)
{
	return m_trie.save(iFileName);
}

bool Trigram::train(const string &iTrainFileName, const string &iModelFileName)
{
	ifstream file(iTrainFileName.c_str());
	if (!file.good()) {
		cerr << "Failed to open language file: " << iTrainFileName << endl;
		return false;
	}

	Trie te;
	char buffer[4];
	for (int i = 0; i < 3; i++)
		buffer[i] = file.get();
	buffer[3] = '\0';
	te.insert(string(buffer));

	while (!file.eof()) {
		for (int i = 0; i < 2; i++)
			buffer[i] = buffer[i+1];
		buffer[2] = file.get();
		te.insert(string(buffer));
	}

	return te.save(iModelFileName);
}

double Trigram::similarity(const string &iMessage)
{
	if (iMessage.length() < 3)
		return 0.0;

	int common = 0;
	for (int i = 0; i < iMessage.length() - 2; i++) {
		if (m_trie.search(iMessage.substr(i, 3)) != 0)
			common++;
	}

	return static_cast<double>(common) / (iMessage.length() - 2);
	
}

