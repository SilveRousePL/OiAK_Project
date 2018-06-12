/*
 * Read.h
 *
 *  Created on: 1 cze 2018
 *      Author: darek
 */

#ifndef LANGUAGE_READ_H_
#define LANGUAGE_READ_H_
#include <memory>
#include "Program.h"
#include "Assign.h"
#include "../Expressions/Constant.h"

class Read: public Program {
	std::string var;

public:
	Read(std::string v) :
			var(v) {
	}
	virtual ~Read() {

	}
	virtual void execute(std::map<std::string, int64_t>* memory) {
		int64_t n;
		std::cin >> n;
		std::unique_ptr<Assign> a(new Assign(var, new Constant(n)));
		a->execute(memory);
	}
};

#endif /* LANGUAGE_READ_H_ */
