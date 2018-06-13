/*
 * Composition.h
 *
 *  Created on: 2 cze 2018
 *      Author: darek
 */

#ifndef LANGUAGE_COMPOSITION_H_
#define LANGUAGE_COMPOSITION_H_
#include "Application.h"

class Composition: public Application {
	Application* left;
	Application* right;

public:
	Composition(Application* left, Application* right) :
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
