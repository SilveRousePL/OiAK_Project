/*
 * Write.h
 *
 *  Created on: 1 cze 2018
 *      Author: darek
 */

#ifndef LANGUAGE_WRITE_H_
#define LANGUAGE_WRITE_H_
#include <memory>
#include "Program.h"
#include "../Expressions/Variable.h"

class Write: public Program {
	std::string var;

public:
	Write(std::string var) :
			var(var) {
	}
	virtual ~Write() {
	}
	virtual void execute(std::map<std::string, int64_t>* memory) {
		std::unique_ptr<Variable> exp(new Variable(var, memory));
		int64_t value = exp->get();
		std::cout << value << std::endl;
	}
};

#endif /* LANGUAGE_WRITE_H_ */
