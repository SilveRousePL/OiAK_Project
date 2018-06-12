/*
 * Composition.h
 *
 *  Created on: 2 cze 2018
 *      Author: darek
 */

#ifndef LANGUAGE_COMPOSITION_H_
#define LANGUAGE_COMPOSITION_H_
#include "Program.h"

class Composition: public Program {
	Program* left;
	Program* right;

public:
	Composition(Program* left, Program* right) :
			left(left), right(right) {
	}
	virtual ~Composition() {

	}
	virtual void execute(std::map<std::string, int64_t>* memory) {
		left->execute(memory);
		right->execute(memory);
	}
};

#endif /* LANGUAGE_COMPOSITION_H_ */
