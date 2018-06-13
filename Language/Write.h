/*
 * Write.h
 *
 *  Created on: 1 cze 2018
 *      Author: darek
 */

#ifndef LANGUAGE_WRITE_H_
#define LANGUAGE_WRITE_H_
#include <memory>
#include "../Expressions/Variable.h"
#include "Application.h"

class Write: public Application {
	std::string var;
	int mode;

public:
	Write(std::string var, int mode = 0) :
			var(var), mode(mode) {
	}
	virtual ~Write() {
	}
	virtual void execute(std::map<std::string, int64_t>* memory) {
		if (mode)
			std::cout << var;
		else {
			std::unique_ptr<Variable> exp(new Variable(var, memory));
			int64_t value = exp->get();
			std::cout << value;
		}
	}
};

#endif /* LANGUAGE_WRITE_H_ */
