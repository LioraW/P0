#include <iostream>
#include <fstream>
#include <iomanip>
#include <regex>
#include <string>
#include "tree.h"

using namespace std;

string validateFileName(string fileName);

int main(int argc, char **argv) {
	string fileName;

    if (argc <= 1) {
        
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

    if (fileName != "") {
        Tree tree(fileName);
        tree.buildTree();
        tree.printInorder();
        tree.printPreorder();
        tree.printPostorder();

    }
    
    return 0;
}

string validateFileName(string fileName) {
    smatch matches;

    regex e("^([a-zA-Z0-9_]+).+(sp2022)$");
    
    if(regex_match(fileName, matches, e)) {

        return matches[1]; // return just the file name, not the extension 
    
    } else {
        
        cerr << "Bad file name:" << fileName <<  endl;
        return "";
    }
}