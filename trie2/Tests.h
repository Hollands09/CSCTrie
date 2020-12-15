#ifndef _TESTS_
#define _TESTS_

#include "Trie.h"
#include "Timer.h"
#include "Rando.h"
#include "Dictionary.h"

#include <iomanip>
#include <cmath>

//calculate standard deviation of the ascii values in a string used to compare insert time vs std deviation of string.
double sd(std::string key) {

	double mean = 0;
	double x = 0;
	double variance = 0;


	for (size_t i = 0; i < key.size(); i++) {

		mean += static_cast<double>(key[i]);

	}

	mean = mean / key.size();

	for (size_t i = 0; i < key.size(); i++) {

		 x += pow((static_cast<double>(key[i]) - mean), 2);

	}

	variance = x / key.size();

	return sqrt(variance);

}

//Test 10 inputs into the trie
//Output dotfile, insert/time file, search/time file
void tenInput() {

	std::cout << "\nTest 1 : 10 Inputs\n"
		<<"outputs search results to console\noutput files include a .txt (dot syntax for graphviz)\n"
		<< ".m to graph input length and standard deviation of each input vs insertion time\n"
		<< ".m to graph input length vs search time.\n";

	system("pause");

	Trie* trie = new Trie;

	Timer* insertT = new Timer("Input Length");
	
	Timer* sdT = new Timer("Input Length and Standard Deviation");
	
	Timer* searchT = new Timer("Word Length");

	//output to a .txt file for graphviz  supposed to be a dot file but for ease of use I just copied and paste into a web version.
	//could be changed easilly by putting .dot instead of .txt.
	std::fstream dotfile("10dotfile.txt", std::fstream::out); 

	std::fstream insertTime("10insertTime.m", std::fstream::out);

	std::fstream searchTime("10searchTime.m", std::fstream::out);


	dotfile << " strict digraph G {\n" << "rootNode [label=\"root\"]\n";  //Strict diagraph, 1 line per node.

	Dictionary english; //load 42000+ words

	//This is ugly but good thing you wont see it in the main

	for (int i = 0; i < 10; i++) {//arbitrary number as not to crowd the dot image.

		unsigned int seed = rando(english.dictionarySize); //call a random selection of those words and stuff them into the trie.

		//Trie insert

		insertT->setT1();

		sdT->setT1();

		trie->insert(english.dictionary[seed]);

		insertT->setT2();

		sdT->setT2();

		dotfile << "//" << english.dictionary[seed] << "\n";  //puts word in trie as a comment in the .dot file

		//Trie helper to print dotfile

		trie->printDot(trie, english.dictionary[seed], dotfile);

		//Trie search

		searchT->setT1();

		trie->search(english.dictionary[seed], "true");  //True outputs search results to console

		searchT->setT2();

		//input data into timer containers

		insertT->graph(english.dictionary[seed].size()); //push back input length and time per insertion
		
		sdT->graph(sd(english.dictionary[seed])); //push back standard deviation of input string

		searchT->graph(english.dictionary[seed].size()); //push back input length and timer per insertion

	}

	//search for a word we know doesnt exist in library

	trie->search("CAPTAINCAVEMAN", "true"); //used to show that search outputs falls if word is not in trie 

	//Prints .m files

	insertT->printTimer(insertTime, "scatter", "ko");
	
	sdT->printTimer(insertTime, "scatter", "rs");

	searchT->printTimer(searchTime, "scatter", "rd");

	//clear allocated memory

	delete trie;
	
	delete insertT;
	
	delete sdT;

	delete searchT;

	dotfile << "}"; //closing brace for dot syntax.

}

//Test 25 inputs into the trie
//Output dotfile
void twoFiveInput() {

	std::cout << "\nTest 2 : 25 Inputs\n"
		<< "outputs search results to console\noutput files include a .txt (dot syntax for graphviz)\n";

	system("pause");

	Trie* trie = new Trie;

	//output to a .txt file for graphviz  supposed to be a dot file but for ease of use I just copied and paste into a web version.
	//could be changed easilly by putting .dot instead of .txt.
	std::fstream dotfile("25dotfile.txt", std::fstream::out); 

	dotfile << " strict digraph G {\n" << "rootNode [label=\"root\"]\n";  //Strict diagraph, 1 line per node.

	Dictionary english; //load 42000+ words

	for (int i = 0; i < 25; i++) {//arbitrary number as not to crowd the dot image.

		unsigned int seed = rando(english.dictionarySize); //call a random selection of those words and stuff them into the trie.

		//Trie insertion

		trie->insert(english.dictionary[seed]);

		//Trie helper to print dotfile

		dotfile << "//" << english.dictionary[seed] << "\n";  //puts word in trie as a comment in the .dot file

		trie->printDot(trie, english.dictionary[seed], dotfile);

		//search for all the words put into the tri

		trie->search(english.dictionary[seed], "true");

	}


	//search from a random set of words in the trie after the insertion
	for (int i = 0; i < 25; i++) {

		unsigned int seed = rando(english.dictionarySize);

		//Search for random words from the dictionary, chances are they are not in the trie

		trie->search(english.dictionary[seed], "true");

	}

	// clear allocated memory

	delete trie;

	dotfile << "}"; //closing brace for dot syntax.


}

//Test 50 inputs into the trie
//Output dotfile time/input file, time/search file
void fiveZeroInput() {

	std::cout << "\nTest 3 : 50 Inputs\n output files include a .txt (dot syntax for graphviz)\n"
		<<".m to graph input length and standard deviation of each input vs insertion time\n"
		<<".m to graph input length vs search time.\n";

	system("pause");

	Timer* insertT = new Timer("Input Length"); //new timer container to hold all info about input times

	Timer* sdT = new Timer("Input Length and Standard Deviation");  //Time container to store standard deviation of a string vs time

	Timer* searchT = new Timer("Word Length"); //new timer container to hold all info about search times

	Trie* trie = new Trie;

	//output to a .txt file for graphviz  supposed to be a dot file but for ease of use I just copied and paste into a web version.
	//could be changed easilly by putting .dot instead of .txt.
	std::fstream dotfile("50dotfile.txt", std::fstream::out); 

	std::fstream fiveZeroInp("50insertTime.m", std::fstream::out);

	std::fstream fiveZeroSearch("50searchTime.m", std::fstream::out);

	dotfile << " strict digraph G {\n" << "rootNode [label=\"root\"]\n";  //Strict diagraph, 1 line per node.

	Dictionary english; //load 42000+ words

	for (int i = 0; i < 50; i++) {//arbitrary number as not to crowd the dot image.

		unsigned int seed = rando(english.dictionarySize); //call a random selection of those words and stuff them into the trie.

		//insert time test

		insertT->setT1();

		sdT->setT1();

		trie->insert(english.dictionary[seed]);

		insertT->setT2();

		sdT->setT2();

		dotfile << "//" << english.dictionary[seed] << "\n";  //puts word in trie as a comment in the .dot file

		//search time test

		searchT->setT1();

		trie->search(english.dictionary[seed], "false"); //false indicates that search does not output to the console, used for longer input sizes.

		searchT->setT2();

		//Trie dot helper to print dotfile

		trie->printDot(trie, english.dictionary[seed], dotfile);

		//store data into the timer containers

		insertT->graph(english.dictionary[seed].size());  //push back input length and time for that insert.
		
		sdT->graph(sd(english.dictionary[seed]));  //push back standard deviation of input string into sdT inputs

		searchT->graph(english.dictionary[seed].size()); //push back input length and time for that search;

	}

	//print .m files to make plots

	insertT->printTimer(fiveZeroInp, "scatter", "ko");

	sdT->printTimer(fiveZeroInp, "scatter", "rs");

	searchT->printTimer(fiveZeroSearch, "scatter", "rd");

	//clear allocated memory

	delete insertT;

	delete sdT;

	delete searchT;

	delete trie;

	dotfile << "}"; //closing brace for dot syntax.

}

//Test 40 thousand inputs to the trie
//Output total insertion time for 40000+ inputs
void fortyThouInputs() {

	std::cout << "\nTest 4: Forty Thousand Inputs'\n"
		<<"output file is a .m to graph total insertion time / total inputs\n";

	system("pause");

	Trie* trie = new Trie;

	Timer* insertT = new Timer("Input Total"); //Name put into the constructor will be the label for the graph

	std::fstream insertTime("40ThouhinsertTime.m", std::fstream::out);
	
	Dictionary english; //load 42000+ words

	for (size_t i = 0; i < english.dictionarySize; i++) {//arbitrary number as not to crowd the dot image.

		unsigned int seed = rando(english.dictionarySize); //call a random selection of those words and stuff them into the trie.

		//insert dictionary size random words into the trie
		//set times for time test

		insertT->setT1();

		trie->insert(english.dictionary[seed]); //insert random seeded words

		insertT->setT2();

		insertT->graph(i); //push number of inputs and the summation of time per inputs of period.
		
	}

	//print .m files

	insertT->printTimer(insertTime, "plot", "k");
	
	//clear allocated memory

	delete trie;
	
	delete insertT;

}


//Test 1 million inputs
//Output total time to console
void oneMilInputs() {

	std::cout << "\nTest 5 : 1 Million Inputs\n"
		<<"No output files, just console message of total milliseconds to insert inputs\n";

	system("pause");

	Trie* trie = new Trie;

	Timer* insertT = new Timer;

	Dictionary english; //load 42000+ words

	insertT->setT1();

	for (unsigned int i = 0; i < 1000000; i++) {//arbitrary number as not to crowd the dot image.

		unsigned int seed = rando(english.dictionarySize); //call a random selection of those words and stuff them into the trie.

		trie->insert(english.dictionary[seed]);

	}
	
	insertT->setT2();

	auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(insertT->t2 - insertT->t1);

	std::cout << "Total time to insert 1 million inputs is " << std::setprecision(10) << int_ms.count() << " milliseconds\n";

	//clear allocated memory

	delete trie;
	
	delete insertT;
}



//Wrapper for all tests to clean up main
void testSuite() {

	tenInput();
	twoFiveInput();
	fiveZeroInput();
	fortyThouInputs();
	oneMilInputs();

}


#endif // !_TESTS_

