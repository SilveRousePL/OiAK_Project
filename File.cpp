/*
 * File.cpp
 *
 *  Created on: 9 kwi 2018
 *      Author: darek
 */

#include "File.h"

File::File(std::string filename) :
		filename(filename), n_lines(1) {
	handle.open(filename, std::ios::in);
	if (!handle.is_open())
		throw FileException("I couldn't open file");
	//LNumber();
	if (n_lines == 0)
		throw FileException("This file is empty");

}

File::~File() {
	if (handle.is_open())
		handle.close();
}

uint32_t File::getNumber() {
	return n_lines;
}

std::string File::getLine(uint32_t line) {
	handle.seekg(0);
	std::string tmp = "";
	for (uint32_t i = 0; i < line; i++) {
		getline(handle, tmp);
	}
	handle.seekg(0);
	return tmp;
}

std::string File::getText() {
	//handle.seekg(0);
	std::string result = "";
	while (!handle.eof()) {
		std::string tmp = "";
		getline(handle, tmp);
		result = result + tmp + '\n';
	}
	handle.seekg(0);
	return result;
}

void File::LNumber() {
	std::string tmp = "";
	uint32_t number = 0;
	while (!handle.eof()) {
		getline(handle, tmp);
		number++;
	}
	this->n_lines = number;
	handle.seekg(0);
}
