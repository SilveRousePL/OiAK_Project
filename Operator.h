/*
 * Operator.h
 *
 *  Created on: 4 kwi 2018
 *      Author: darek
 */

#ifndef OPERATOR_H_
#define OPERATOR_H_
#include <string>
#include "Expression.h"
#include "Exceptions.h"

template<class T>
class Operator: Expression<T> {
	std::string symbol;
	Expression<T>* left;
	Expression<T>* right;

public:
	Operator(std::string symbol, Expression<T>* left, Expression<T>* right) :
			symbol(symbol), left(left), right(right) {
	}
	virtual ~Operator() {
		if(left != nullptr) delete left;
		if(right != nullptr) delete right;
	}
	T getValue() override {
		if (symbol == "==")
			return left->getValue() == right->getValue();
		if (symbol == "!=")
			return left->getValue() != right->getValue();
		if (symbol == "%")
			return left->getValue() % right->getValue();
		if (symbol == "/")
			return left->getValue() / right->getValue();
		if (symbol == "*")
			return left->getValue() * right->getValue();
		if (symbol == "-")
			return left->getValue() - right->getValue();
		if (symbol == "+")
			return left->getValue() + right->getValue();
		throw UnknownOperator("");
	}
};

#endif /* OPERATOR_H_ */
