/*
 * Program.h
 *
 *  Created on: 20 maj 2018
 *      Author: darek
 */

#ifndef LANGUAGE_PROGRAM_H_
#define LANGUAGE_PROGRAM_H_
#include <map>

class Program {
public:
	Program() {
	}
	virtual ~Program() {
	}
	virtual void eval(std::map<std::string, int> & mem) = 0;
};

#endif /* LANGUAGE_PROGRAM_H_ */
