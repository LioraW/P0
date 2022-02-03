#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "tree.h"
using namespace std;

string validateFileName(string fileName);

int main(int argc, char **argv) {
	string fileName;

    if (argc <= 1) {
        cout << "No file given. Please type in your text: " << endl;
        
        // open a temp file 
        fileName = "output";
        ofstream inputfile(fileName);
        string text = "";

        //read keyboard input into temp file
        while (cin >> text && text != "EOF") {
                inputfile << text << endl;
        }

        inputfile.close();

    } else {
        fileName = validateFileName(argv[1]);
    }
        Tree tree(fileName);
        tree.buildTree(fileName);
        tree.printInorder();
        tree.printPreorder();
        tree.printPostorder();

    return 0;
}

//TODO
string validateFileName(string fileName) {
    return fileName;
}
