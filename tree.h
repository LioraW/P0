#ifndef TREE_H
#define TREE_H

#include "node.h"

class Tree
{
private:
	Node *root;			//pointer to root node
    
    bool wordIsGreater(string word1, string word2);
    bool wordIsSame(string word1, string word2);
    void insert(Node *&nodePtr, Node *&newNode);		//insert a node in the correct place
	void destroySubTree(Node *nodePtr);					//delete all of the nodes below and including the given node
	Node * searchNodes(string text);					//search for a node containing the given text and return it if it is found
	void displayInOrder(Node *nodePtr) const;			//display the tree's nodes in order
    // void deleteNode(string letters, Node *&nodePtr);	//find the node to delete
    // void makeDeletion(Node *&nodePtr);				//delete the given node
public:
	Tree();											//constructor

	~Tree();										//destructor

	void insertNewNode(string letters);				//create a new node and insert it
	
    void buildTree(string fileName);                //build a new tree with the words in the file with the given file name
    
	void remove (string letters);					//remove a node

	void displayInOrder() const;					//display the tree's nodes in order
};

#endif