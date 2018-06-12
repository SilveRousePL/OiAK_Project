/*
 * Skip.h
 *
 *  Created on: 1 cze 2018
 *      Author: darek
 */

#ifndef LANGUAGE_SKIP_H_
#define LANGUAGE_SKIP_H_
#include "Program.h"

class Skip: public Program {
public:
	Skip() {
	}
	virtual ~Skip() {
	}
	virtual void execute(std::map<std::string, int64_t>* memory) {
	}
};

#endif /* LANGUAGE_SKIP_H_ */
