using namespace std;

#include "FormBar.h"
#include "ReadWords.h"
#include <iostream>
#include <map>
#include <list>
#include <string>

//the constructor which calls all the methods in the correct order, for the program to work
FormBar::FormBar(ReadWords &readWords, ReadWords &readSearch)
{
	listz = readToList(readSearch);
	maperz = readToMap(readWords);

	readToConsole();
	readToFile();
}

//read the words from the file into a map <(the word in the file), (number of occurences of the word)>
map<string,int> FormBar::readToMap(ReadWords &readWords)
{
  map<string,int> readStore;
  string s;

  //while there is a next word keep adding strings to the map
  while(readWords.isNextWord())
  {
	  s = readWords.getNextWord();

	  //check to see if an empty string was returned
	  if (s.empty())
	  {
		  continue;
	  }

	  //if the word has occured before increment the counter
	  for (auto const& word : listz) {
	      if (s == word)
	      {
	    	  ++readStore[s];
	      }
	  }

  }

  return readStore;
}

//if any of the words in the search list didnt occur in both map, return a list of the rejected words
list<string> FormBar::unfoundWords()
{	list<string> listtt;
	bool occur;

	for (auto const &word : listz) {
		occur = false;

		//if the word occured in the map break the current loop and search the next word
		for (const auto &p : maperz) {
			if (p.first == word) {
				occur = true;
				break;
			}
		}

		//if the word doesnt occur in the map push it in to the list
		if (occur == false){
			listtt.push_back(word);
		}
	}

  return listtt;
}

//read words from the search file in to the list
list<string> FormBar::readToList(ReadWords &readSearch)
{
  list<string> searchStore;
  string s;

  //while there is a next word keep pushing strings to the list
  while(readSearch.isNextWord())
  {
	  s = readSearch.getNextWord();

	  //check to see if an empty string was returned
	  if (s.empty())
	  {
		  continue;
	  }

	  searchStore.push_back(s);
  }

  //sort the list so duplicates can be deleted
  searchStore.sort();
  searchStore.unique();

  return searchStore;
}

//read words from the map in to the console
void FormBar::readToConsole()
{
	std::cout << "Words From File, Bar Chart." << '\n';

	for (const auto &p : maperz) {
		//makes a string array of '*' holding the amount of times a string occured
		string s(p.second,'*');
	    std::cout << p.first << "  " << s << "  " << p.second << '\n';
	}

	//now print out the rejected words which were not found
	list<string> listReject = unfoundWords();

	if (listReject.size() != 0)
	{
		std::cout << "Searched words, which were not in the file." << '\n';
		for (auto const& word : listReject) {
			std::cout << word << '\n';
		}
	}

	std::cout << "Output sent to 'BarChart.txt'" << '\n';
}

//read words from the map in to a file
void FormBar::readToFile()
{
	myfile.open ("BarChart.txt");

	myfile << "Words From File, Bar Chart." << '\n';

	for (const auto &p : maperz) {
			string s(p.second,'*');
			myfile << p.first << "  " << s << "  " << p.second << '\n';
	}

	list<string> listReject = unfoundWords();

	if (listReject.size() != 0)
	{
		myfile << "Searched words, which were not in the file." << '\n';
		for (auto const& word : listReject) {
			myfile << word << '\n';
		}
	}

	myfile.close();

}
