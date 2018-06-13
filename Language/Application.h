/*
 * Application.h
 *
 *  Created on: 20 maj 2018
 *      Author: darek
 */

#ifndef LANGUAGE_APPLICATION_H_
#define LANGUAGE_APPLICATION_H_
#include <map>

class Application {
public:
	Application() {
	}
	virtual ~Application() {
	}
	virtual void execute(std::map<std::string, int64_t>* memory) = 0;
};

#endif /* LANGUAGE_APPLICATION_H_ */
