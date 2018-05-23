/*
 * main.cpp
 *
 *  Created on: 28 mar 2018
 *      Author: darek
 */
#include <iostream>
#include "Parser.h"

int main(int argc, char** argv) {
	std::string args(*argv);

	std::map<std::string, int64_t>* memory = new std::map<std::string, int64_t>;
	while (true) {
		std::string command;
		std::cout << "> ";
		getline(std::cin, command);
		if (command.length() == 0)
			continue;
		try {
			Parser p(command, memory);
			Expression * exp = p.parseExpression();
			std::cout << "  = " << exp->get() << std::endl;
		} catch (NotParsed & e) {
			std::cout << " Parsed Error!" << std::endl;
		} catch (VariableNotFound & e) {
			std::cout << " Variable not found!" << std::endl;
		} catch (...) {
			std::cout << " Unknown Error!" << std::endl;
		}
	}
	delete memory;

	Expression * ex1 = new Constant(20);
	Expression * ex2 = new Constant(7);
	Expression * ex3 = new Operator("+", ex1, ex2);
	std::cout << ex1->get() << "+" << ex2->get() << "=" << ex3->get()
			<< std::endl;
	return 0;
}
