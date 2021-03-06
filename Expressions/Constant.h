/*
 * Constant.h
 *
 *  Created on: 3 kwi 2018
 *      Author: darek
 */

#ifndef CONSTANT_H_
#define CONSTANT_H_
#include "Expression.h"

//template<class T>
class Constant: public Expression {
	int64_t value;

public:
	Constant(int64_t v) :
			value(v) {
	}
	~Constant() {
	}
	int64_t get() override {
		return value;
	}
};

#endif /* CONSTANT_H_ */
