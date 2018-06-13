/*
 * Parser.h
 *
 *  Created on: 6 kwi 2018
 *      Author: darek
 */

#ifndef PARSER_H_
#define PARSER_H_
#include <string>
#include <vector>
#include <map>
#include "Expressions/Operator.h"
#include "Language/Composition.h"
#include "Language/Skip.h"
#include "Language/Write.h"
#include "Language/Read.h"
#include "Language/If.h"
#include "Language/For.h"
#include "Language/While.h"

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
	std::string parseIdentifier();
//	std::string parseOperator(std::vector<std::string> op);

	Expression* parseExpression();
	Expression* parseSum();
	Expression* parseMult();
	Expression* parseComp();
	Expression* parseTerm();
	Expression* parseConstant();
	Expression* parseVariable();
	Expression* parseParen();

	Application* parseAssign(std::string value);
	Application* parseProgram();
	Application* parseBlock();
	Application* parseInstruction();
	Application* parseRead();
	Application* parseVWrite();
	Application* parseCWrite();
	Application* parseIf();
//	Program* parseFor();
	Application* parseWhile();
};

#endif /* PARSER_H_ */
