#ifndef TREE_H
#define TREE_H

#include <string.h>
#include "node.h"

class Tree
{
private:
	Node *root;			//pointer to root node
	string inputFileName;	//file name to get input from
	string outputFileName;	//file name for output files
    
    bool wordIsGreater(string word1, string word2); //check if one word's last letter is lexographically greater than the other
    bool wordIsSame(string word1, string word2);    //check if two words' last letters are the same
    void insert(Node *&nodePtr, Node *&newNode);    //insert a node in the correct place
	void insertNewNode(string letters);				//create a new node and insert it		
	void destroySubTree(Node *nodePtr);				//delete all of the nodes below and including the given node
	
	void processNode(string fileType, string word, int level) const; 			//print the node
	void printInorder(Node *nodePtr, int level) const;			//display the tree's nodes in order
    void printPreorder(Node *nodePtr, int level) const;        //display the tree's node in pre order
    void printPostorder(Node *nodePtr, int level) const;       //display the tree's node in post order

    
public:
	Tree(string fileName);			//constructor
	~Tree();						//destructor
    void buildTree();               //build a new tree with the words in the file with the given file name
	void printInorder() const;		//display the tree's nodes in order
	void printPreorder() const;		//display the tree's nodes in pre order
	void printPostorder() const;	//display the tree's nodes in post order

};

#endif