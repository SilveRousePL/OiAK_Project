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

class FileException: public Exception {
public:
	FileException(std::string comment) :
			Exception(comment) {
	}
};

class ProgramException: public Exception {
protected:
	size_t position;

public:
	ProgramException(std::string comment, size_t position) :
			Exception(comment), position(position) {
	}
	size_t getPosition() {
		return position;
	}
};

class NullPointerException: public ProgramException {
public:
	NullPointerException(std::string comment, size_t position) :
			ProgramException(comment, position) {
	}
};

class UnknownOperator: public ProgramException {
public:
	UnknownOperator(std::string comment, size_t position) :
			ProgramException(comment, position) {
	}
};

class ParserException: public ProgramException {
public:
	ParserException(std::string comment, size_t position) :
			ProgramException(comment, position) {
	}
};

class VariableNotFound: public ProgramException {
public:
	VariableNotFound(std::string comment, size_t position) :
			ProgramException(comment, position) {
	}
};

class ArithmeticException: public ProgramException {
public:
	ArithmeticException(std::string comment, size_t position) :
			ProgramException(comment, position) {
	}
};

#endif /* EXCEPTIONS_H_ */
