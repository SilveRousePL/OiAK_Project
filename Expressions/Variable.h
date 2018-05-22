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
#include <map>

template<class T>
class Variable: Expression<T> {
	static std::map<std::string, T> memory;
	std::string name;

	Variable();

	T get() override {
		try {
			return memory.at(name);
		} catch(...) {
			throw VariableNotFound("");
		}
	}
};

#endif /* VARIABLE_H_ */
