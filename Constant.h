/*
 * Constant.h
 *
 *  Created on: 3 kwi 2018
 *      Author: darek
 */

#ifndef CONSTANT_H_
#define CONSTANT_H_
#include "Expression.h"

template<class T>
class Constant: Expression<T> {
	T value;

public:
	Constant(T v) :
			value(v) {
	}
	virtual ~Constant();
	T getValue() override {
		return value;
	}
};

#endif /* CONSTANT_H_ */
