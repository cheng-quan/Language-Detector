/*
 * by Cheng Quan <cheng-quan@foxmail.com>
 */

#include <iostream>
#include <fstream>
#include "Trie.h"

using namespace std;

TrieNode::TrieNode() : m_pBuffer(NULL), m_iCount(0) {}

TrieNode::~TrieNode()
{
	if (m_pBuffer != NULL) {
		delete [] m_pBuffer;
		m_pBuffer = NULL;
	}
}

Trie::Trie() : m_pRoot() 
{
	m_pRoot.m_pBuffer = new TrieNode[256];
}

Trie::~Trie() {}

void Trie::insert(const string &tri_chars)
{
	TrieNode* cur_node = &m_pRoot;
	for (int i = 0; i < 3; i++) {
		if(cur_node->m_pBuffer == NULL)
			cur_node->m_pBuffer = new TrieNode[256];
		cur_node->m_iCount++;
		cur_node = &(cur_node->m_pBuffer[static_cast<unsigned char>(tri_chars[i])]);
	}
	cur_node->m_iCount++;
}

unsigned int Trie::search(const string &tri_chars)
{
	TrieNode* cur_node = &m_pRoot;
	for (int i = 0; i < 3; i++) {
		if (cur_node->m_pBuffer == NULL)
			return 0;
		cur_node = &(cur_node->m_pBuffer[static_cast<unsigned char>(tri_chars[i])]);
	}

	return cur_node->m_iCount;
}

bool Trie::save(const string &iFileName)
{
	fstream file(iFileName.c_str(), ios::out | ios::binary);
	if (!file.good()) {
		cerr << "Failed to open file: " << iFileName << endl;
		return false;
	}

	file.write((char*)(&m_pRoot.m_iCount), sizeof(unsigned int));
	TrieNode* level_1 = m_pRoot.m_pBuffer;
	for (int i = 0; i < 256; i++) {
		file.write((char*)(&level_1[i].m_iCount), sizeof(unsigned int));
		if (level_1[i].m_iCount != 0) {
			TrieNode* level_2 = level_1[i].m_pBuffer;
			for (int j = 0; j < 256; j++) {
				file.write((char*)(&level_2[j].m_iCount), sizeof(unsigned int));
				if (level_2[j].m_iCount != 0) {
					TrieNode* level_3 = level_2[j].m_pBuffer;
					for (int k = 0; k < 256; k++) 
						file.write((char*)(&level_3[k].m_iCount), sizeof(unsigned int));
				}
			}
		}
	}
	file.close();

	return true;
}

bool Trie::load(const string &iFileName)
{
	ifstream file(iFileName.c_str(), ios::in | ios::binary);
	if (!file.good()) {
		cerr << "Failed to open file: " << iFileName << endl;
		return false;
	}
	
	file.read((char*)(&m_pRoot.m_iCount), sizeof(unsigned int));
	TrieNode* level_1 = m_pRoot.m_pBuffer;
	for (int i = 0; i < 256; i++) {	
		file.read((char*)(&level_1[i].m_iCount), sizeof(unsigned int));
		if (level_1[i].m_iCount != 0) {
			level_1[i].m_pBuffer = new TrieNode[256];
			TrieNode* level_2 = level_1[i].m_pBuffer;
			for (int j = 0; j < 256; j++) {
				file.read((char*)(&level_2[j].m_iCount), sizeof(unsigned int));
				if (level_2[j].m_iCount != 0) {
					level_2[j].m_pBuffer = new TrieNode[256];
					TrieNode* level_3 = level_2[j].m_pBuffer;
					for (int k = 0; k < 256; k++)
						file.read((char*)(&level_3[k].m_iCount), sizeof(unsigned int));
				}
			}
		}
	}
	file.close();

	return true;
}

