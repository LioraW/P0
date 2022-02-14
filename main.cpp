#include <iostream>
#include <fstream>
#include <iomanip>
#include <regex>
#include <string>
#include "tree.h"

using namespace std;

bool fileNameContainsDot(string FileName);
string validateFileName(string fileName);

int main(int argc, char **argv) {
	string fileName;

    if (argc <= 1) {
        
        // open a temp file 
        fileName = "output";
        ofstream inputfile(fileName + ".sp2022", ios::app);
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

bool fileNameContainsDot(string fileName) {
    for (int i = 0; i < fileName.length(); i++) {
        if (fileName[i] == '.') {
            return true;
        }
    }
    return false;
}

string validateFileName(string fileName) {
    
    string fileExtension = fileName.substr(fileName.length() - 7, fileName.length());
    
    //the file should have the extension .sp2022 or no extension at all
    if (!fileNameContainsDot(fileName)){
        return fileName;
    } else if (fileExtension == ".sp2022") {
        return fileName.substr(0, fileName.length()  - 7);
    } else {
        cerr << "Bad file name: " << fileName << endl;
        return "";
    }
}