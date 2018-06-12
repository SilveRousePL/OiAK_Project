/*
 * If.h
 *
 *  Created on: 1 cze 2018
 *      Author: darek
 */

#ifndef LANGUAGE_IF_H_
#define LANGUAGE_IF_H_
#include "Program.h"

class If: public Program {
	Expression* condition;
	Program* p_then;
	Program* p_else;

public:
	If(Expression* condition, Program* p_then, Program* p_else) :
			condition(condition), p_then(p_then), p_else(p_else) {
	}
	virtual ~If() {
	}
	virtual void execute(std::map<std::string, int64_t>* memory) {
		if (condition->get() != 0)
			p_then->execute(memory);
		else if(p_else != NULL)
			p_else->execute(memory);
	}
};

#endif /* LANGUAGE_IF_H_ */
