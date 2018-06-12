/*
 * Assign.h
 *
 *  Created on: 23 maj 2018
 *      Author: darek
 */

#ifndef LANGUAGE_ASSIGN_H_
#define LANGUAGE_ASSIGN_H_
#include "Program.h"
#include <string>

class Assign: public Program {
	std::string variable;
	Expression* expression;

public:
	Assign(std::string variable, Expression* expression) :
			variable(variable), expression(expression) {
	}
	virtual void execute(std::map<std::string, int64_t>* memory) {
		(*memory)[variable] = expression->get();
	}
};

#endif /* LANGUAGE_ASSIGN_H_ */
