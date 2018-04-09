/*
 * File.h
 *
 *  Created on: 9 kwi 2018
 *      Author: darek
 */

#ifndef FILE_H_
#define FILE_H_
#include <fstream>
#include "Exceptions.hpp"

class File {
	std::fstream handle;
	std::string filename;
	uint32_t number_of_lines;

public:
	File(std::string filename);
	virtual ~File();

	uint32_t getNumber();
	std::string getLine(uint32_t line);

private:
	void calculateLinesNumber();
};

#endif /* FILE_H_ */
