/*
 * Expression.h
 *
 *  Created on: 5 kwi 2018
 *      Author: darek
 */

#ifndef EXPRESSION_H_
#define EXPRESSION_H_

template<class T>
class Expression {
public:
	Expression();
	virtual ~Expression();
	virtual T getValue() = 0;
};

#endif /* EXPRESSION_H_ */
