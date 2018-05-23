/*
 * Parser.cpp
 *
 *  Created on: 6 kwi 2018
 *      Author: darek
 */

#include "Parser.h"

Parser::Parser(std::string current, std::map<std::string, int64_t>* memory) :
		text(current), position(0), memory(memory) {
}

Parser::~Parser() {
	// TODO Auto-generated destructor stub
}

char Parser::getNext() {
	skipWhitespace();
	return text[position];
}

void Parser::skipWhitespace() {
	while (isspace(text[position]))
		position++;
}

Expression* Parser::parseExpression() {
	Expression* exp = parseSum();
	if (getNext() == '\0')
		return exp;
	else {
		delete exp;
		throw NotParsed("");
	}
	return exp;
}

Expression* Parser::parseSum() {
	Expression* exp = parseMult();
	char curr = getNext();
	while (curr == '+' || curr == '-') {
		position++;
		Expression* f = parseMult();
		exp = new Operator(std::string(1, curr), exp, f);
		curr = getNext();
	}
	return exp;
}

Expression* Parser::parseMult() {
	Expression* exp = parseTerm();
	char curr = getNext();
	while (curr == '*' || curr == '/' || curr == '%') {
		position++;
		Expression* f = parseTerm();
		exp = new Operator(std::string(1, curr), exp, f);
		curr = getNext();
	}
	return exp;
}

Expression* Parser::parseTerm() {
	char curr = getNext();
	if (curr == '(')
		return parseParen();
	else if (isdigit(curr) || curr == '-')
		return parseConstant();
	else if (isalpha(curr))
		return parseVariable();
	else
		throw NotParsed("a term expected");
}

Expression* Parser::parseConstant() {
	int64_t n = 0;
	while (isdigit(text[position])) {
		n *= 10;
		n += text[position] - '0';
		position++;
	}
	/*if (text[position] == '.') {
		double nf = 0;
		uint64_t nfi = 0;
		uint64_t i = 1;
		position++;
		while (isdigit(text[position])) {
			nfi *= 10;
			nfi += text[position] - '0';
			i *= 10;
			position++;
		}
		nf = n + ((double) nfi) / i;
		return new Constant(nf);
	}*/
	return new Constant(n);
}

Expression* Parser::parseVariable() {
	std::string str;
	while (isalnum(text[position])) {
		str.push_back(text[position]);
		position++;
	}
	return new Variable(str, memory);
}

Expression* Parser::parseParen() {
	position++; // parse_term zapewnia, że wskaznik stoi na nawiasie otwierajacym '('
	Expression* exp = parseSum();
	if (getNext() == ')') {
		position++;
		return exp;
	} else
		throw NotParsed("')' expected");
}

Program* Parser::parseAssign(std::string value) {
	char c = getNext();
	if (c == '=') {
		position++;
		Expression* exp = parseSum();
		return new Assign(value, exp);
	} else
		throw NotParsed("'=' expected");
}
