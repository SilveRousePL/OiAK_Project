/*
 * Parser.h
 *
 *  Created on: 6 kwi 2018
 *      Author: darek
 */

#ifndef PARSER_H_
#define PARSER_H_
#include <string>
#include "Expressions/Constant.h"
#include "Expressions/Variable.h"

//TODO: Parser
class Parser {
	std::string text;
	size_t position;

public:
	Parser(std::string current);
	virtual ~Parser();

	char lookAhead();
	void skipWhitespace();

	Expression* parseExpression();
	Expression* parseSum();
	Expression* parseMult();
	Expression* parseTerm();
	Expression* parseConstant();
	Expression* parseVariable();
	Expression* parseParen();
};

#endif /* PARSER_H_ */
