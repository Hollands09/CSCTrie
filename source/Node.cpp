#include "Node.h"

//This enum is used to easilly add new alphabets to Trie
//Right now it will stay as just English more will be implemented later
//
//TODO: add more langauges for final implementation
enum {

	English = 26



};


Node::Node() { }

Node *Node::getNode(void) {

	Node *nextNode = new Node;
		
	nextNode->endOfWord = false;

	for (int i = 0; i < English; i++) {


	}

}

Node::~Node() { }