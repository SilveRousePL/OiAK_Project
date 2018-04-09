/*
 * File.cpp
 *
 *  Created on: 9 kwi 2018
 *      Author: darek
 */

#include "File.h"

File::File(std::string filename) :
		filename(filename), number_of_lines(0) {
	handle.open(filename, std::ios::in);
	if (!handle.is_open())
		throw FileException("");
	calculateLinesNumber();
	if (number_of_lines == 0)
		throw FileException("");

}

File::~File() {
	if (handle.is_open())
		handle.close();
}

uint32_t File::getNumber() {
	return number_of_lines;
}

std::string File::getLine(uint32_t line) {
	std::string tmp = "";
	for (uint32_t i = 0; i < line; i++) {
		getline(handle, tmp);
	}
	handle.seekg(0);
	return tmp;
}

void File::calculateLinesNumber() {
	std::string tmp = "";
	uint32_t number = 0;
	while (!handle.eof()) {
		getline(handle, tmp);
		number++;
	}
	this->number_of_lines = number;
	handle.seekg(0);
}
