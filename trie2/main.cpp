#include "Trie.h"
#include "Dictionary.h"
#include "Rando.h"

int main() {

	Trie* trie = new Trie;

	std::fstream dotfile("dotfile.txt", std::fstream::out); //output to a .txt file for graphviz  supposed to be a dot file but for ease of use I just copied and paste into a web version.
															//could be changed easilly by putting .dot instead of .txt.



	dotfile << " strict digraph G {\n" << "rootNode [label=\"root\"]\n";  //Strict diagraph, 1 line per node.

	Dictionary english; //load 42000+ words

	for (int i = 0; i < 25; i++) {//arbitrary number as not to crowd the dot image.

		unsigned int seed = rando(english.dictionarySize); //call a random selection of those words and stuff them into the trie.

		trie->insert(english.dictionary[seed]);
		dotfile << "//" << english.dictionary[seed] << "\n";  //puts word in trie as a comment in the .dot file
		trie->printDot(trie, english.dictionary[seed], dotfile);
		trie->search(english.dictionary[seed]);

	}

	trie->search("CAPTAINCAVEMAN");

	delete trie;
	
	dotfile << "}"; //closing brace for dot syntax.


	system("pause");
	return 0;
}