#include "Trie.h"


//Default constructor, initilize child array to nullptr.
Trie::Trie() {

	for (int i = 0; i < Lang::english; i++) {

		child[i] = nullptr;

	}

	endString = false;
	count = 0;
}

//destructor
Trie::~Trie() {


}


void Trie::insert(std::string key) {

	Trie* root = this;

	for (int i = 0; i < key.size(); i++){

		if (root->child[key[i]] == nullptr) { //Trie does not have a node at the letter key[i]

			root->child[key[i]] = new Trie; //Insert one

		}

		root = root->child[key[i]]; //Swap to new node and continue adding child nodes until end of string.

	}

	root->count++;
	root->endString = true; //is leaf.
}

bool Trie::search(std::string key, std::string ret) {

	if (this == nullptr || key.empty()) { //If no word is input or the trie is empty return.

		if (ret == "true") {

			std::cout << "trie or key is empty\n";
		
		}

		return false;

	}

	Trie* root = this;

	for (int i = 0; i < key.size(); i++){ //if root has a nullptr instead of node, return does not exist.

		root = root->child[key[i]];

		if (root == nullptr) {

			if (ret == "true") {

				std::cout << key << " does not exist in trie\n";

			}

			return false;
	
		}

	}

	if (root->endString) { //Fancy looking way of saying 1 time or 0 or multiple times.  Grammar eeerbody.

		if (ret == "true")
		
			std::cout << key << " exists " << root->count << (root->count == 1 ? " time in trie\n" : " times in trie\n");
		
		}
		
		return true;

	}


bool Trie::hasChildren(Trie const* root) {  //specific node to see if it has children.

	for (int i = 0; i < Lang::english; i++) {

		if (root->child[i]) {

			return true;
		}
	
	}

		return false;

}

void Trie::labelPrint(Trie*& trie, std::string key, std::fstream& dotfile) {

	if (trie == nullptr) {

		return;

	}

	Trie* root = trie;

	for (int i = 0; i < key.size(); i++) {  //print each node and a node<pointervalue> [label="key[i]"] i.e node00A96AD8 [label="I"]

		root = root->child[key[i]];

		dotfile << "node" << root << " [label=\"" << key[i] << "\"]\n";

	}



}


void Trie::printDot(Trie*& trie, std::string key, std::fstream& dotfile) { //does the rest of the printing of the dotfile. calls label first.

	if (trie == nullptr) {

		return;

	}

	labelPrint(trie, key, dotfile);//organize the nodes first.

	Trie* root = trie;

	for (int i = 0; i < key.size(); i++) {

		if (i == 0) {  //make sure each node it linked to a root to keep the dotfile clean.

			dotfile << "rootNode -> ";

		}

			root = root->child[key[i]];

			dotfile << "node" << root;

			if (i == key.size() - 1) { //if last node dont print "->" for syntax reasons

				dotfile << "\n";

			}
			else {  //else print -> to connect nodes.

				dotfile << " -> ";

			}


	}
	dotfile << "\n";
}
