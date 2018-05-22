/*
 * Exceptions.h
 *
 *  Created on: 4 kwi 2018
 *      Author: darek
 */

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_
#include <iostream>

class Exception {
protected:
	std::string c;

public:
	Exception(std::string comment) :
			c(comment) {
	}
	virtual ~Exception() = default;

	std::string what() const {
		return c;
	}
};

class NullPointerException: public Exception {
public:
	NullPointerException(std::string comment) :
			Exception(comment) {
	}
};

class UnknownOperator: public Exception {
public:
	UnknownOperator(std::string comment) :
			Exception(comment) {
	}
};

class NotParsed: public Exception {
public:
	NotParsed(std::string comment) :
			Exception(comment) {
	}
};

class VariableNotFound: public Exception {
public:
	VariableNotFound(std::string comment) :
			Exception(comment) {
	}
};

class ArithmeticException: public Exception {
public:
	ArithmeticException(std::string comment) :
			Exception(comment) {
	}
};

class FileException: public Exception {
public:
	FileException(std::string comment) :
			Exception(comment) {
	}
};

#endif /* EXCEPTIONS_H_ */
