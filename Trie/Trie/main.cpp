#include <iostream>
#include "Trie.h"
#include <string>

int main() {

	std::string inputs[6] = { "JAMIE", "JAMIE", "JAIME","RYAN", "BARBS","BARB" };
	
	int n = sizeof(inputs) / sizeof(inputs[0]);

	std::cout << "The contents of the trie contains the words ";

	for (int i = 0; i < 6; i++) {

		std::cout << inputs[i] << " ";

	}

	std::cout << "\n";

	Trie* trie = new Trie();
	for (int i = 0; i < n; i++){
		trie->insert(trie, inputs[i]);
	}
	trie->search(trie, "JAMIE");


	system("pause");
}