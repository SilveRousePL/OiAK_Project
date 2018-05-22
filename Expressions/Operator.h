/*
 * Operator.h
 *
 *  Created on: 4 kwi 2018
 *      Author: darek
 */

#ifndef OPERATOR_H_
#define OPERATOR_H_
#include <string>
#include <cmath>
#include "Expression.h"

//template<class T>
class Operator: public Expression {
	std::string symbol;
	Expression* left;
	Expression* right;

public:
	Operator(std::string symbol, Expression* left, Expression* right) :
			symbol(symbol), left(left), right(right) {
	}
	virtual ~Operator() {
		if (left != nullptr)
			delete left;
		if (right != nullptr)
			delete right;
	}
	int get() override { //Pod wstawki ASM
		if (symbol == "==")
			return equal();
		if (symbol == "!=")
			return not_equal();
		if (symbol == "%")
			return mod();
		if (symbol == "/")
			return div();
		if (symbol == "*")
			return mul();
		if (symbol == "-")
			return sub();
		if (symbol == "+")
			return add();
		throw UnknownOperator("");
	}
private:
	int add() {
		return left->get() + right->get();
	}
	int sub() {
		return left->get() - right->get();
	}
	int mul() {
		return left->get() * right->get();
	}
	int div() {
		if (right->get() == 0)
			throw ArithmeticException("");
		return left->get() / right->get();
	}
	int mod() {
		if (right->get() == 0)
			throw ArithmeticException("");
		return left->get() % right->get();
		/*return [](T value, T modulus)->T {
		 return value - trunc(value / modulus) * modulus;
		 }(left->get(), right->get());*/
	}
	int not_equal() {
		return left->get() != right->get();
	}
	int equal() {
		return left->get() == right->get();
	}
};

#endif /* OPERATOR_H_ */
