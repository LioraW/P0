#include <iostream>
#include <string>
#include <ctype.h>
#include <fstream>
 
#include "node.h"
#include "tree.h"

using namespace std;

//PRIVATE 
bool Tree::wordIsGreater(string word1, string word2) {
	return tolower(word1.back()) < tolower(word2.back()); // "greater" means lexicographically first
}

bool Tree::wordIsSame(string word1, string word2) {
	return tolower(word1.back()) == tolower(word2.back());
}

void Tree::insert(Node *&nodePtr, Node *&newNode) {			//insert a node in the correct place

	if (nodePtr == nullptr)
		nodePtr = newNode;
	else if ( wordIsGreater(newNode -> str, nodePtr -> str))
			insert(nodePtr->left, newNode);
	else if ( wordIsSame(newNode -> str, nodePtr -> str))
		insert(nodePtr -> middle, newNode);
	else
		insert (nodePtr -> right, newNode);
}
void Tree::insertNewNode(string letters) {		//create a new node and insert it

	Node *newNode = nullptr;

	//Create a new node
	newNode = new Node;
	newNode->str = letters;
	newNode->left = newNode->middle = newNode->right = nullptr;

	//Insert the node
	insert(root, newNode);
}

void Tree::destroySubTree(Node *nodePtr) {						//delete all of the nodes below and including the given node
	if (nodePtr) {
		if (nodePtr -> left)
			destroySubTree(nodePtr->left);
		if(nodePtr -> middle)
			destroySubTree(nodePtr->middle);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

void Tree::processNode(string word, int level) const {
	
	int numSpaces = level*2;
	while (numSpaces--)
		cout << " ";

	cout << word.back() << ": " << word << endl;
}

void Tree::printInorder(Node *nodePtr, int level) const {
	//display the tree's nodes in order
	if (nodePtr) {
		printInorder(nodePtr->left, level + 1);
		processNode(nodePtr->str, level);
		printInorder(nodePtr->middle, level + 1);
		printInorder(nodePtr->right, level + 1);
	}
}

void Tree::printPreorder(Node *nodePtr, int level) const {
	//display the tree's nodes in pre order
	if (nodePtr) {
		processNode(nodePtr->str, level);
		printPreorder(nodePtr->left, level + 1); 
		printPreorder(nodePtr->middle, level + 1);
		printPreorder(nodePtr->right, level + 1);
	}
}

void Tree::printPostorder(Node *nodePtr, int level) const {
	//display the tree's nodes in post order
	if (nodePtr) {
		printPostorder(nodePtr->left, level + 1); 
		printPostorder(nodePtr->middle, level + 1);
		printPostorder(nodePtr->right, level + 1);
		processNode(nodePtr->str, level);
	}
}

//PUBLIC

//constructor
Tree::Tree(string file) {
	 root = nullptr;
	 fileName = file;
}				

//destructor	
Tree::~Tree() {
	 destroySubTree(root);
}

//create the tree from the given input file
void Tree::buildTree(string fileName) {
	fstream file;
	string word;
	
	file.open(fileName);

	if (file.is_open()) {
		
		while (file >> word) {
			insertNewNode(word);
		}

	} else {
		cerr << "Unable to open file: " << fileName << endl;
	}   

	file.close();

}

void Tree::printInorder() const	{
	cout << "Words in order:" << endl << endl;
	printInorder(root, 0); 
}
void Tree::printPreorder() const {
	cout << endl << "Words pre order:" << endl;
	printPreorder(root, 0);
} 
void Tree::printPostorder() const {
	cout << endl << "Words in Post order" << endl;
	printPostorder(root, 0); 
}		


	

