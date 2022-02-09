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

    } else {
        cerr << "Bad file name!" << endl;
    }
    
    return 0;
}

string validateFileName(string fileName) {
    regex e("^.+/.(sp2022)$"); //needs at least one . before file extension... +?? 

    if(regex_match(fileName, e)) {
        return fileName; // return just the file name, not the extension 
    } else {
        return "";
    }
}