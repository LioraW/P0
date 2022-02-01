#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

struct Node
	{
		string str;
		Node *left;		//pointer to left child node
        Node *middle;   //pointer to middle child node
		Node *right;	//pointer to right child node
	};

#endif