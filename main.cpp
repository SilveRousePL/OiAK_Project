/*
 * main.cpp
 *
 *  Created on: 28 mar 2018
 *      Author: darek
 */
#include <iostream>
#include "Parser.h"
#include "File.h"

int main(int argc, char** argv) {
	std::string args(*argv);

	std::map<std::string, int64_t>* memory = new std::map<std::string, int64_t>;
	/*	while (true) { // Calculator parser
	 std::string command;
	 std::cout << "> ";
	 getline(std::cin, command);
	 if (command.length() == 0)
	 continue;
	 try {
	 Parser p(command, memory);
	 Expression * exp = p.parseExpression();
	 int64_t result = exp->get();
	 std::cout << "  = " << result << std::endl;
	 } catch (ParserException & e) {
	 std::cerr << "  Parser error: " << e.what();
	 } catch (UnknownOperator & e) {
	 std::cerr << "  Parser error: " << e.what();
	 } catch (VariableNotFound & e) {
	 std::cerr << "  Program error: " << e.what();
	 } catch (ArithmeticException & e) {
	 std::cerr << "  Arithmetic error: " << e.what();
	 } catch (...) {
	 std::cerr << "  Unknown error";
	 }
	 }
	 */
	std::string fn;
	if (argc == 1) {
		std::cout << "Nazwa pliku: ";
		getline(std::cin, fn);
	} else if (argc == 2) {
		fn = argv[1];
	}
	try {
		File f(fn);
		Parser p(f.getText(), memory);
		Application* app = p.parseProgram();
		app->execute(memory);
		std::cout << std::endl;
	} catch (FileException & e) {
		std::cerr << "  File error: " << e.what() << std::endl;
	} catch (ParserException & e) {
		std::cerr << "  Parser error: " << e.what() << "(" << e.getPosition()
				<< ")" << std::endl;
	} catch (UnknownOperator & e) {
		std::cerr << "  Parser error: " << e.what() << "(" << e.getPosition()
				<< ")" << std::endl;
	} catch (VariableNotFound & e) {
		std::cerr << "  Program error: " << e.what() << "(" << e.getPosition()
				<< ")" << std::endl;
	} catch (ArithmeticException & e) {
		std::cerr << "  Arithmetic error: " << e.what() << "("
				<< e.getPosition() << ")" << std::endl;
	} catch (...) {
		std::cerr << "  Unknown error" << std::endl;
	}

	delete memory;

	/*Expression * ex1 = new Constant(20);
	 Expression * ex2 = new Constant(7);
	 Expression * ex3 = new Operator("+", ex1, ex2);
	 std::cout << ex1->get() << "+" << ex2->get() << "=" << ex3->get()
	 << std::endl;*/
	return 0;
}
