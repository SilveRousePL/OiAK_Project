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

std::string Parser::parseIdentifier() {
	std::string str;
	while (isalpha(text[position]) || isdigit(text[position])
			|| text[position] == '\\') {
		if (text[position] == '\\') {
			position++;
			if (text[position] == 'n') {
				str.push_back('\n');
			} else if (text[position] == 't') {
				str.push_back('\t');
			} else if (text[position] == 's') {
				str.push_back(' ');
			} else {
				throw ParserException("Unknown special character", position);
			}
			position++;
		} else {
			str.push_back(text[position]);
			position++;
		}
	}
	return str;
}

/*std::string Parser::parseOperator(std::vector<std::string> op) {
 std::string str;
 for (int i = 0; i < op.size(); i++) {
 for (int j = 0; j < op[i].length(); j++) {
 while (text[position] == ) {

 }
 }
 }
 while (text[position] == '=' || text[position] == '!'
 || text[position] == '<' || text[position] == '>'
 || text[position] == '+' || text[position] == '-'
 || text[position] == '*' || text[position] == '/'
 || text[position] == '%' || text[position] == ':'
 || text[position] == '^' || text[position] == '&'
 || text[position] == '|') {
 str.push_back(text[position]);
 position++;
 }
 return str;
 }*/

Expression * Parser::parseExpression() {
	Expression* exp = parseSum();
	if (getNext() == '\0')
		return exp;
	else {
		delete exp;
		throw ParserException("Unknown expression", position);
	}
	return exp;
}

Expression * Parser::parseSum() {
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

Expression * Parser::parseMult() {
	Expression* exp = parseComp();
	char curr = getNext();
	while (curr == '*' || curr == '/' || curr == '%') {
		position++;
		Expression* f = parseComp();
		exp = new Operator(std::string(1, curr), exp, f);
		curr = getNext();
	}
	return exp;
}

Expression * Parser::parseComp() {
	Expression* exp = parseTerm();
	char curr = getNext();
//std::string curr = parseOperator(); //std::string(1, getNext());
	while (curr == '?' || curr == '!' || curr == '<' || curr == '>') {
		position++;
		Expression* f = parseTerm();
		exp = new Operator(std::string(1, curr), exp, f);
		curr = getNext();
	}
	return exp;
}

Expression * Parser::parseTerm() {
	char curr = getNext();
	if (curr == '(')
		return parseParen();
	else if (isdigit(curr) || curr == '-')
		return parseConstant();
	else if (isalpha(curr))
		return parseVariable();
	else
		throw ParserException("Unexpected character", position);
}

Expression * Parser::parseConstant() {
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

Expression * Parser::parseVariable() {
	std::string str;
	while (isalnum(text[position])) {
		str.push_back(text[position]);
		position++;
	}
//parseAssign(str);
	return new Variable(str, memory);
}

Expression * Parser::parseParen() {
	position++;
	Expression* exp = parseSum();
	if (getNext() == ')') {
		position++;
		return exp;
	} else
		throw ParserException("')' expected", position);
}

Application* Parser::parseAssign(std::string value) {
	char c = getNext();
	if (c == '=') {
		position++;
		Expression* exp = parseSum();
		Application* a = new Assign(value, exp);
		//a->execute(memory);
		return a;
	} else
		throw ParserException("'=' expected", position);
}

Application * Parser::parseProgram() {
	Application* p = parseBlock();
	if (getNext() == 0)
		return p;
	else
		throw ParserException("End of stream expected", position);
}

Application * Parser::parseBlock() {
	Application* p = parseInstruction();
	char c = getNext();
	while (c != '}' && c != 0) {
		Application* q = parseInstruction();
		p = new Composition(p, q);
		c = getNext();
	}
	return p;
}

Application * Parser::parseInstruction() {
	char c = getNext();
	if (c == '{') {
		position++;
		Application* p = parseBlock();
		if (getNext() == '}') {
			position++;
			return p;
		} else
			throw ParserException("'}' expected", position);
	} else if (isalpha(c)) {
		std::string str = parseIdentifier();
		if (str == "read")
			return parseRead();
		else if (str == "vwrite")
			return parseVWrite();
		else if (str == "cwrite")
			return parseCWrite();
		else if (str == "if")
			return parseIf();
		/*else if (str == "for")
		 return parseFor();*/
		else if (str == "while")
			return parseWhile();
		else if (str == "skip")
			return new Skip();
		else
			return parseAssign(str);
	} else
		throw ParserException("identifier or a keyword expected", position);
}

Application * Parser::parseRead() {
	char c = getNext();
	if (isalpha(c)) {
		std::string s = parseIdentifier();
		return new Read(s);
	} else
		throw ParserException("", position);
}

Application * Parser::parseVWrite() {
	char c = getNext();
	if (isalpha(c)) {
		std::string s = parseIdentifier();
		return new Write(s);
	} else
		throw ParserException("variable expected", position);
}

Application * Parser::parseCWrite() {
	getNext();
	std::string s = parseIdentifier();
	return new Write(s, 1);
}

Application * Parser::parseIf() {
	Expression* e = parseSum();
	Application* p = parseInstruction();
	if (isalpha(getNext())) {
		if (parseIdentifier() == "else") {
			Application* q = parseInstruction();
			return new If(e, p, q);
		} else
			throw ParserException("'else' expected", position);
	} else
		throw ParserException("'else' expected", position);
}

/*Application* Parser::parseFor() {

 Expression* e = parseSum();

 Application* p = parseInstruction();
 return new For(, e, , p);
 }*/

Application * Parser::parseWhile() {
	Expression* e = parseSum();
	Application* p = parseInstruction();
	return new While(e, p);
}
