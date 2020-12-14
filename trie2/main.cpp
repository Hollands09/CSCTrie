#include "Trie.h"
#include "Dictionary.h"
#include "Rando.h"
#include "Timer.h"
#include <iomanip>;

//Test 10 inputs into the trie
//Output dotfile
void tenInput();

//Test 25 inputs into the trie
//Output dotfile
void twoFiveInput();

//Test 50 inputs into the trie
//Output dotfile
void fiveZeroInput();

//Test 40 thousand inputs to the trie
//Output total insert/time file search/time file
void fortyThouInputs();

//Test 1 million inputs
//Output total time to console
void oneMilInputs();

//Wrapper for all tests to clean up main
void testSuite();


int main() {

	testSuite();

	system("pause");
	return 0;
}

//Test 10 inputs into the trie
//Output dotfile, insert/time file, search/time file
void tenInput() {
	
	std::cout << "Test 1 : 10 inputs\n";

	Trie* trie = new Trie;

	Timer* insertT = new Timer("Input Total");
	Timer* searchT = new Timer("Word Length");

	std::fstream dotfile("10dotfile.txt", std::fstream::out); //output to a .txt file for graphviz  supposed to be a dot file but for ease of use I just copied and paste into a web version.
															  //could be changed easilly by putting .dot instead of .txt.

	std::fstream insertTime("10insertTime.m", std::fstream::out);
	std::fstream searchTime("10searchTime.m", std::fstream::out);


	dotfile << " strict digraph G {\n" << "rootNode [label=\"root\"]\n";  //Strict diagraph, 1 line per node.

	Dictionary english; //load 42000+ words

	for (int i = 0; i < 10; i++) {//arbitrary number as not to crowd the dot image.

		unsigned int seed = rando(english.dictionarySize); //call a random selection of those words and stuff them into the trie.

		insertT->setT1();

		trie->insert(english.dictionary[seed]);

		insertT->setT2();

		dotfile << "//" << english.dictionary[seed] << "\n";  //puts word in trie as a comment in the .dot file
		
		trie->printDot(trie, english.dictionary[seed], dotfile);

		searchT->setT1();

		trie->search(english.dictionary[seed], "true");

		searchT->setT2();

		insertT->graph(i);
		searchT->graph(english.dictionary[seed].size());

	}

	insertT->printTimer(insertTime);
	searchT->printTimer(searchTime);

	delete trie;
	delete insertT;
	delete searchT;

	dotfile << "}"; //closing brace for dot syntax.

}

//Test 25 inputs into the trie
//Output dotfile, insert/time file, search/time file
void twoFiveInput() {
	
	std::cout << "Test 2 : 25 inputs\n";

	Trie* trie = new Trie;

	std::fstream dotfile("25dotfile.txt", std::fstream::out); //output to a .txt file for graphviz  supposed to be a dot file but for ease of use I just copied and paste into a web version.
															  //could be changed easilly by putting .dot instead of .txt.

	dotfile << " strict digraph G {\n" << "rootNode [label=\"root\"]\n";  //Strict diagraph, 1 line per node.

	Dictionary english; //load 42000+ words

	for (int i = 0; i < 25; i++) {//arbitrary number as not to crowd the dot image.

		unsigned int seed = rando(english.dictionarySize); //call a random selection of those words and stuff them into the trie.

		trie->insert(english.dictionary[seed]);

		dotfile << "//" << english.dictionary[seed] << "\n";  //puts word in trie as a comment in the .dot file

		trie->printDot(trie, english.dictionary[seed], dotfile);

		trie->search(english.dictionary[seed], "true");

	}
	

	//search from a random set of words in the trie after the insertion
	for (int i = 0; i < 25; i++) {

		unsigned int seed = rando(english.dictionarySize);

		trie->search(english.dictionary[seed], "true");

	}

	delete trie;

	dotfile << "}"; //closing brace for dot syntax.


}

//Test 50 inputs into the trie
//Output dotfile, insert/time file, search/time file
void fiveZeroInput() {

	std::cout << "Test 3 : 50 inputs\n";

	Trie* trie = new Trie;

	std::fstream dotfile("50dotfile.txt", std::fstream::out); //output to a .txt file for graphviz  supposed to be a dot file but for ease of use I just copied and paste into a web version.
															  //could be changed easilly by putting .dot instead of .txt.

	dotfile << " strict digraph G {\n" << "rootNode [label=\"root\"]\n";  //Strict diagraph, 1 line per node.

	Dictionary english; //load 42000+ words

	for (int i = 0; i < 50; i++) {//arbitrary number as not to crowd the dot image.

		unsigned int seed = rando(english.dictionarySize); //call a random selection of those words and stuff them into the trie.

		trie->insert(english.dictionary[seed]);

		dotfile << "//" << english.dictionary[seed] << "\n";  //puts word in trie as a comment in the .dot file

		trie->printDot(trie, english.dictionary[seed], dotfile);

	}

	delete trie;

	dotfile << "}"; //closing brace for dot syntax.

}

//Test 40 thousand inputs to the trie
//Output insert/time file, search/time file
void fortyThouInputs() {
	
	Trie* trie = new Trie;

	Timer* insertT = new Timer("Input Total");
	Timer* searchT = new Timer("Word Length");

	std::fstream insertTime("40ThouhinsertTime.m", std::fstream::out);
	std::fstream searchTime("40ThoughsearchTime.m", std::fstream::out);

	Dictionary english; //load 42000+ words

	for (int i = 0; i < english.dictionarySize; i++) {//arbitrary number as not to crowd the dot image.

		unsigned int seed = rando(english.dictionarySize); //call a random selection of those words and stuff them into the trie.

		insertT->setT1();

		trie->insert(english.dictionary[seed]);

		insertT->setT2();

		searchT->setT1();

		trie->search(english.dictionary[seed], "false");

		searchT->setT2();

		insertT->graph(i);
		searchT->graph(english.dictionary[seed].size());

	}

	insertT->printTimer(insertTime);
	searchT->printTimer(searchTime);

	delete trie;
	delete insertT;
	delete searchT;

}


//Test 1 million inputs
//Output total time to console
void oneMilInputs() {

	std::cout << "Test 4 : 1 million inputs\n";

	Trie* trie = new Trie;

	Timer* insertT = new Timer;

	Dictionary english; //load 42000+ words

	insertT->setT1();
	for (int i = 0; i < 1000000; i++) {//arbitrary number as not to crowd the dot image.

		unsigned int seed = rando(english.dictionarySize); //call a random selection of those words and stuff them into the trie.

		trie->insert(english.dictionary[seed]);

	}
	insertT->setT2();

	auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(insertT->t2 - insertT->t1);

	std::cout << "Total time to insert 1 million inputs is " << std::setprecision(10) << int_ms.count() << " milliseconds\n";

	delete trie;
	delete insertT;
}



//Wrapper for all tests to clean up main
void testSuite() {

	tenInput();
	twoFiveInput();
	fiveZeroInput();
	oneMilInputs();

}

