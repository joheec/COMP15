/*
 * readInput.cpp
 *
 *  Created on: Apr 12, 2016
 *      Author: johee
 */

#include <iostream>
#include <fstream>
#include <cstdlib>

#include "readInput.h"

using namespace std;

void readFile(string fileName, string type)
{
	//file of inputs
	ifstream fileInput;
	fileInput.open(fileName);
	string line;
	if(fileInput.is_open()) {
		while(getline(fileInput, line)) {
			cout << line << '\n';
		}
		fileInput.close();
	} else {
		cerr << "Unable to open file.";
	}

}

void readCommands(istream &input)
{
	//commands
	string command;
	input >> command;
	while(!input.fail() && command != "quit") {
		cout << command << "\n";
		cin >> command;
	}

}

