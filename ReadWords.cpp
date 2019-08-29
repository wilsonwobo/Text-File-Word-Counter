using namespace std;

#include <cstdlib>  // for exit()
#include <iostream>
#include <string>
#include <cctype>
#include "ReadWords.h"

//opens the file provided by the user
ReadWords::ReadWords(const char *filename)
{	wordfile.open(filename);

	//when the file doesnt exist, exit the program run.
    if (!wordfile)
    {   cout << "Failed to open " << filename << endl;
        exit(1);
	}
}

//closes the file
void ReadWords::close()
{ if (wordfile)
	wordfile.close();
}

//function which gets the next word in the file and deletes punctuation from in front and behind the word
string ReadWords::getNextWord()
{   string n;
	char c;
    wordfile >> n;

    //while there is still a puctuation mark in front and behind the word keep loop running
    while (ispunct(n[0]) || ispunct(n[n.length()-1]))
    {
		////if there is a punctuation mark on the first letter, delete the letter from the string
		if (ispunct(n[0]))
		{
			n.erase(0,1);
		}

		//if there is a punctuation mark on the last letter, delete the letter from the string
		if (ispunct(n[n.length()-1]))
		{
			n.erase(n.length()-1,1);
		}
    }

	//if the length of the string is not 0, make all the letters in the string lower case
    if (n.length()!=0)
    {

    	  for (int i = 0; i < n.length()-1; i++)
    	  {
    	    c = n[i];
    	    n[i] = tolower(c);
    	  }
    }

return n;
}

//if there is a string in the next word space return true, else return false.
bool ReadWords::isNextWord()
{ 	if (wordfile.eof())
		return false;
	else
		return true;

}
