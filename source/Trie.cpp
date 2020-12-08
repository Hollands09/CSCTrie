#include "Trie.h"


Trie::Trie(){

	count = 1;
	depth = 0;
	endString = false;

	for (int i = 0; i < 26; i++) {

		this->child[i] = nullptr;

	}

}

Trie* Trie::createNode(){

	Trie* node = new Trie;

	node->endString = false;

	for (int i = 0; i < 26; i++) {

		node->child[i] = nullptr;

	}

	return node;
}

void Trie::insert(Trie* root, std::string key) {

	Trie* curr = root;

	for (size_t i = 0; i < key.length(); i++) {

		int index = key[i] - 'A';

		if (!curr->child[index]) {

			curr->child[index] = createNode();
			
		}

		curr = curr->child[index];

		if (curr->endString && i == key.length() - 1) {

			curr->count += 1;

		}

	}

	curr->endString = true;

}

int Trie::search(Trie* root, std::string key) {

	Trie* curr = root;

	for (size_t i = 0; i < key.length(); i++) {

		int index = key[i] - 'A';

		if (!curr->child) {

			std::cout << key << " does not exist in Trie\n";

			return 0;

		}

		curr = curr->child[index];

	}

	if (curr != nullptr && curr->endString) {

		std::cout << key << " exists " << curr->count;
		curr->count == 1 ? std::cout << " time in the Trie\n" : std::cout << " times in the Trie\n";

		return curr->count;

	}

}

bool Trie::empty(Trie* root) {

	for (int i = 0; i < 26; i++) {

		if (root->child[i]) {

			return false;

		}
		else

			return true;

	}

}

Trie* Trie::deleteNode(Trie* root, int depth, std::string key) {

	if (!root) {

		return nullptr;
	}

	if (depth == key.size()) {

		if (root->endString) {

			root->endString = false;

		}

		if (Trie::empty(root)) {

			delete root;
			root = nullptr;
		}

		return root;

	}

	int index = key[depth] - 'A';
	root->child[index] = Trie::deleteNode(root->child[index], depth + 1, key);

	if (Trie::empty(root) && root->endString == false) {

		delete root;
		root = nullptr;

	}

	return root;

}

