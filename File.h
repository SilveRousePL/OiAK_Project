/*
 * File.h
 *
 *  Created on: 9 kwi 2018
 *      Author: darek
 */

#ifndef FILE_H_
#define FILE_H_
#include <fstream>
#include "Exceptions.h"

class File {
	std::ifstream handle;
	std::string filename;
	uint32_t n_lines;

public:
	File(std::string filename);
	virtual ~File();

	uint32_t getNumber();
	std::string getLine(uint32_t line);
	std::string getText();

private:
	void LNumber();
};

#endif /* FILE_H_ */
