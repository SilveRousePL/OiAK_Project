/*
 * Expression.h
 *
 *  Created on: 5 kwi 2018
 *      Author: darek
 */

#ifndef EXPRESSION_H_
#define EXPRESSION_H_
#include "../Exceptions.h"

//template<class T>
class Expression {
public:
	Expression() {
	}
	virtual ~Expression() {
	}
	virtual int64_t get() = 0;
};

#endif /* EXPRESSION_H_ */
