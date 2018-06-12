/*
 * Variable.h
 *
 *  Created on: 5 kwi 2018
 *      Author: darek
 */

#ifndef VARIABLE_H_
#define VARIABLE_H_
#include "Expression.h"
#include <string>

//template<class T>
class Variable: public Expression {
	std::string name;
	std::map<std::string, int64_t>* memory;

public:
	Variable(std::string name, std::map<std::string, int64_t>* memory) :
			name(name), memory(memory) {
	}
	int64_t get() override {
		try {
			return memory->at(name);
		} catch (...) {
			throw VariableNotFound("Variable '" + name + "' is not declared", 0);
		}
	}
	std::string getName() {
		return name;
	}
};

#endif /* VARIABLE_H_ */
