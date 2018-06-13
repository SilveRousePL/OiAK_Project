/*
 * For.h
 *
 *  Created on: 1 cze 2018
 *      Author: darek
 */

#ifndef LANGUAGE_FOR_H_
#define LANGUAGE_FOR_H_
#include "../Expressions/Expression.h"
#include "Application.h"

class For: public Application {
	Assign* variable;
	Expression* condition;
	Assign* iteration;
	Application* p_loop;

public:
	For(Assign* variable, Expression* condition, Assign* iteration,
			Application* p_loop) :
			variable(variable), condition(condition), iteration(iteration), p_loop(
					p_loop) {
	}
	virtual ~For() {
	}
	virtual void execute(std::map<std::string, int64_t>* memory) {
		variable->execute(memory);
		if (condition->get() != 0) {
			p_loop->execute(memory);
			this->execute(memory);
			iteration->execute(memory);
		}
	}
};

#endif /* LANGUAGE_FOR_H_ */
