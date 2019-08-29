/*
 * FormBar.h
 *
 *  Created on: 12 Nov 2017
 *      Author: Wilson Wobo
 */

#ifndef FORMBAR_H_
#define FORMBAR_H_

using namespace std;

#include "ReadWords.h"
#include <map>
#include <string>
#include <list>

class FormBar
 {
   public:

   	//the constructor which calls all the methods in the correct order, for the program to work
	FormBar(ReadWords&, ReadWords&);

	//read the words from the file into a map <(the word in the file), (number of occurences of the word)>
	map<string,int> readToMap(ReadWords&);

	//read words from the search file in to the list
	list<string> readToList(ReadWords&);

	//read words from the map in to the console
	void readToConsole();

	//read words from the map in to a file
	void readToFile();

	//if any of the words in the search list didn't occur in both map, return a list of the rejected word
	list<string> unfoundWords();

   private:

   	//holds a map containing the strings searched for and their number of occurences in the file
	map<string,int> maperz;

	//holds a list of strings the user wishes to search
	list<string> listz;

	ofstream myfile;

 };

#endif /* FORMBAR_H_ */
