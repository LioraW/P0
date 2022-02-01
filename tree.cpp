#include <iostream>
#include <string>
#include <ctype.h>
#include <fstream>
 
#include "node.h"
#include "tree.h"

using namespace std;

//PRIVATE 
    bool Tree::wordIsGreater(string word1, string word2)  
    {
        return tolower(word1.back()) < tolower(word2.back()); // "greater" means lexicographically first
    }
    bool Tree::wordIsSame(string word1, string word2) 
    {
        return tolower(word1.back()) == tolower(word2.back());
    }

    void Tree::insert(Node *&nodePtr, Node *&newNode)				//insert a node in the correct place
	{
		if (nodePtr == nullptr)
			nodePtr = newNode;
		else if ( wordIsGreater(newNode -> str, nodePtr -> str))
				insert(nodePtr->left, newNode);
		else if ( wordIsSame(newNode -> str, nodePtr -> str))
			insert(nodePtr -> middle, newNode);
        else
            insert (nodePtr -> right, newNode);
	}

	void Tree::destroySubTree(Node *nodePtr)							//delete all of the nodes below and including the given node
	{
		if (nodePtr)
		{
			if (nodePtr -> left)
				destroySubTree(nodePtr->left);
            if(nodePtr -> middle)
                destroySubTree(nodePtr->middle);
			if (nodePtr->right)
				destroySubTree(nodePtr->right);
			delete nodePtr;
		}
	}

	Node * Tree::searchNodes(string text)								//search for a node containing the given text and return it if it is found
	{
		Node *nodePtr = root;

		while (nodePtr)
		{
			if(wordIsSame(nodePtr->str, text))
				return nodePtr;
			else if (wordIsGreater(nodePtr->str, text))
				nodePtr = nodePtr->left;
			else
				nodePtr = nodePtr->right;
		}
		return nodePtr; //if the node was not found nodePtr would return as a nullptr
	}

	void Tree::printInorder(Node *nodePtr) const	{
		//display the tree's nodes in order
		if (nodePtr) {
			printInorder(nodePtr->left);
			 cout << nodePtr->str << endl;
            printInorder(nodePtr->middle);
			printInorder(nodePtr->right);
		}
	}

    void Tree::printPreorder(Node *nodePtr) const	{
		//display the tree's nodes in pre order
		if (nodePtr) {
            cout << nodePtr->str << endl;
			printPreorder(nodePtr->left); 
            printPreorder(nodePtr->middle);
			printPreorder(nodePtr->right);
		}
	}

    void Tree::printPostorder(Node *nodePtr) const	{
		//display the tree's nodes in post order
		if (nodePtr) {
			printPostorder(nodePtr->left); 
            printPostorder(nodePtr->middle);
			printPostorder(nodePtr->right);
            cout << nodePtr->str << endl;
		}
	}

//PUBLIC
	Tree::Tree()	{ root = nullptr; }				//constructor
		
	Tree::~Tree()	{ destroySubTree(root);}		//destructor
	
	void Tree::insertNewNode(string letters) {		//create a new node and insert it
	
		Node *newNode = nullptr;

		//Create a new node
		newNode = new Node;
		newNode->str = letters;
		newNode->left = newNode->middle = newNode->right = nullptr;

		//Insert the node
		insert(root, newNode);
	}
    
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

	void Tree::printInorder() const	    { printInorder(root); }
	void Tree::printPreorder() const	{ printPreorder(root); } 
	void Tree::printPostorder() const	{ printPostorder(root); }		


		

