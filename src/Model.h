/*
 * by Cheng Quan <cheng-quan@foxmail.com>
 */

#ifndef _Model_h_
#define _Model_h_

#include <string>

class Model {
public:
	virtual double similarity(const std::string &iMessage) = 0;
	virtual ~Model() {}
};

#endif
