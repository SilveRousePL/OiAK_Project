/*
 * Parser.h
 *
 *  Created on: 6 kwi 2018
 *      Author: darek
 */

#ifndef PARSER_H_
#define PARSER_H_
#include <string>
#include <map>
/*
#include "Expressions/Expression.h"
#include "Expressions/Constant.h"
#include "Expressions/Operator.h"
#include "Expressions/Variable.h"
#include "Language/Program.h"
*/
#include "headers.h"

//TODO: Parser
class Parser {
	std::string text;
	size_t position;
	std::map<std::string, int64_t>* memory;

public:
	Parser(std::string current, std::map<std::string, int64_t>* memory);
	virtual ~Parser();

	char getNext();
	void skipWhitespace();

	Expression* parseExpression();
	Expression* parseSum();
	Expression* parseMult();
	Expression* parseTerm();
	Expression* parseConstant();
	Expression* parseVariable();
	Expression* parseParen();

	Program* parseAssign(std::string value);

};

#endif /* PARSER_H_ */
