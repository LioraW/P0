#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "tree.h"
using namespace std;

string validateFileName(string fileName);

int main(int argc, char **argv) {
	string fileName;
    Tree tree;

    if (argc <= 1) {
        cout << "No file given. Please type in your text: " << endl;
        
        // open a temp file 
        fileName = "tempfile.sp2022";
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
        tree.buildTree(fileName);
        cout << "Words in order:" << endl << endl;
        tree.printInorder();

        cout << endl << "Words pre order:" << endl;
        tree.printPreorder();

        cout << endl << "Words in Post order" << endl;
        tree.printPostorder();

    return 0;
}

//TODO
string validateFileName(string fileName) {
    return fileName;
}
