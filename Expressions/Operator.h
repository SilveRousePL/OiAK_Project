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
	int64_t get() override { //Pod wstawki ASM
		if (symbol == "=")
			return equal();
		if (symbol == "!=")
			return not_equal();
		if (symbol == "<")
			return less();
		if (symbol == ">")
			return greater();
		if (symbol == "<=")
			return less_or_equal();
		if (symbol == ">=")
			return greater_or_equal();
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
		throw UnknownOperator("Unknown operator!", 0);
	}
private:
	int64_t add() {
		return left->get() + right->get();
	}
	int64_t sub() {
		return left->get() - right->get();
	}
	int64_t mul() {
		return left->get() * right->get();
	}
	int64_t div() {
		if (right->get() == 0)
			throw ArithmeticException("Divide by zero", 0);
		return left->get() / right->get();
	}
	int64_t mod() {
		if (right->get() == 0)
			throw ArithmeticException("Divide by zero", 0);
		return left->get() % right->get();
		/*return [](T value, T modulus)->T {
		 return value - trunc(value / modulus) * modulus;
		 }(left->get(), right->get());*/
	}
	int64_t greater_or_equal() {
		return left->get() >= right->get();
	}
	int64_t less_or_equal() {
		return left->get() <= right->get();
	}
	int64_t greater() {
		return left->get() > right->get();
	}
	int64_t less() {
		return left->get() < right->get();
	}
	int64_t not_equal() {
		return left->get() != right->get();
	}
	int64_t equal() {
		return left->get() == right->get();
	}
};

#endif /* OPERATOR_H_ */
