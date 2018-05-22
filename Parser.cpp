/*
 * Parser.cpp
 *
 *  Created on: 6 kwi 2018
 *      Author: darek
 */

#include "Parser.h"

Parser::Parser() {
	// TODO Auto-generated constructor stub

}

Parser::Parser(std::string current) {
}

Parser::~Parser() {
	// TODO Auto-generated destructor stub
}

char Parser::lookAhead() {
	skipWhitespace();
	return text[position];
}

void Parser::skipWhitespace() {
	while (isspace(text[position]))
		position++;
}

Expression* Parser::parseExpression() {
	Expression* e = parseSum();
	if (lookAhead() == EOS)
		return e;
	else {
		delete e;
		throw NotParsed();
	}
}

Expression* Parser::parseSum() {
	Expression* exp = parseMult();
	char curr = lookAhead();
	while (curr == '+' || curr == '-') {
		position++;
		Expression* f = parseMult();
		exp = new Operator(curr, exp, f);
		curr = lookAhead();
	}
	return exp;
}

Expression* Parser::parseMult() {
	Expression* exp = parseTerm();
	char curr = lookAhead();
	while (curr == '*' || curr == '/' || curr == '%') {
		position++;
		Expression* f = parseTerm();
		exp = new Operator(curr, exp, f);
		curr = lookAhead();
	}

	return exp;
}

Expression* Parser::parseTerm() {
	char curr = lookAhead();
	if (curr == '(')
		return parseParen();
	else if (isdigit(curr))
		return parseConstant();
	else if (isalpha(curr))
		return parseVariable();
	else
		throw NotParsed("a term expected");
}

Expression* Parser::parseConstant() {
	int n = 0;
	while (isdigit(text[position])) {
		n *= 10;
		n += text[position] - '0';
		position++;
	}
	return new Constant(n);
}

Expression* Parser::parseVariable() {
	std::string str;
	while (isalnum(text[position])) {
		str.push_back(text[position]);
		position++;
	}
	return new Variable(str);
}

Expression* Parser::parseParen() {
	position++; // parse_term zapewnia, że wskaznik stoi na nawiasie otwierajacym '('
	Expression* exp = parseSum();
	if (lookAhead() == ')') {
		position++;
		return exp;
	} else
		throw NotParsed("')' expected");
}
