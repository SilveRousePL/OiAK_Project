/*
 * main.cpp
 *
 *  Created on: 28 mar 2018
 *      Author: darek
 */
#include <iostream>
#include "Operator.h"
#include "Constant.h"
#include "Variable.h"

int main(int argc, char **argv) {
	Expression<bool> * ex1 = new Constant<bool>(0);
	Expression<bool> * ex2 = new Constant<bool>(1);
	Expression<bool> * ex3 = new Operator<bool>("%", ex1, ex2);
	std::cout << ex1->get() << "%" << ex2->get() << "=" << ex3->get() << std::endl;
	return 0;
}
