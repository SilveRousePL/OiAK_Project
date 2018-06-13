/*
 * While.h
 *
 *  Created on: 1 cze 2018
 *      Author: darek
 */

#ifndef LANGUAGE_WHILE_H_
#define LANGUAGE_WHILE_H_
#include "Application.h"

class While: public Application {
	Expression* condition;
	Application* p_loop;

public:
	While(Expression* condition, Application* b) :
			condition(condition), p_loop(b) {
	}
	virtual ~While() {
	}
	virtual void execute(std::map<std::string, int64_t>* memory) {
		if (condition->get() != 0) {
			p_loop->execute(memory);
			this->execute(memory);
		}
	}
};

#endif /* LANGUAGE_WHILE_H_ */
