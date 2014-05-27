/*
 * by Cheng Quan <cheng-quan@foxmail.com>
 */

#ifndef _Trie_h_
#define _Trie_h_

#include <string>

class TrieNode {
friend class Trie;
public:
	TrieNode();
	~TrieNode();
private:
	TrieNode* m_pBuffer;
	unsigned int m_iCount;
};

class Trie {
public:
	Trie();
	~Trie();

	void insert(const std::string &tri_chars);
	unsigned int search(const std::string &tri_chars);

	bool save(const std::string &iFileName);
	bool load(const std::string &iFileName);
private:
	TrieNode m_pRoot;
};

#endif

