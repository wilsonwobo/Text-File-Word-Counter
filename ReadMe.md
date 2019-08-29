# Text File Word Counter

## Platform Recommendation
* This program has been run on Windows 10.0.15063 build 15063 and Mac OS X, developed using cygwin version 3.0.7-1, g++/gcc version 7.4.0 & GNU Make version 4.2.1 Other systems have not been tested, and it is advised to have caution with untested OS.

## To Start
* Open a command line window and navigate to the folder holding the program's *.cpp* & *.h* files.
* Then type: *g++ ex2.cpp FormBar.cpp ReadWords.cpp -o WordCounter*, which should compile the the program into a file named *WordCounter.exe*.

## How to use the Program
* Firstly, double-click on the compiled *WordCounter.exe* file.
* Then, you will be prompted to input the name of the file containing the words you wish to search (via a command prompt).
* Input the filename *words.txt* into the command prompt.  
**NOTE: A different *.txt* file can be used but its contents must be of a similar format to *words.txt*.**  
* Next, you will be prompted to input the name of the file you wish to compare to the search words.
* Input the filename *story.txt* into the command prompt.   
**NOTE: A different *.txt* file can be used also.**
* The contents of this search will then be output in a bar-chart format, proceeded by the words that could not be found.
**NOTE: The contents of this search will also be output into a seperate file named *BarChart.txt*.**

## Example Runtime
<pre>
C\...\WordCounter_c++>g++ ex2.cpp FormBar.cpp ReadWords.cpp -o WordCounter

Input the file, which contains the search words!
words.txt

Input the file, which you wish to search!
story.txt

Words From File, Bar Chart.
a  ************************  24
and  **********************************************************  58
fox  ******************************  30
good  ******  6
is  *****  5
look  *  1
the  *******************************************************************************  79
went  ***  3

Searched words, which were not in the file.
because
happy
rabit
sign
walk

Output sent to 'BarChart.txt'
</pre>
