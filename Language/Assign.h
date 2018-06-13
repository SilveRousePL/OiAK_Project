/*
 * Assign.h
 *
 *  Created on: 23 maj 2018
 *      Author: darek
 */

#ifndef LANGUAGE_ASSIGN_H_
#define LANGUAGE_ASSIGN_H_
#include <string>
#include "Application.h"

class Assign: public Application {
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
