#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "tree.h"
using namespace std;

string validateFileName(string fileName);

int main(int argc, char **argv)
{
	string fileName;
    Tree tree;

    if (argc == 1) {

        fileName = "tempfile.sp2022";
        string text = "";
        
        ofstream inputfile(fileName);
        

        cout << "No file given. Please type in your text: " << endl;
        
        while (cin >> text) {
            if (text != "EOF") {
                
                inputfile << text << endl; //process word => put it into file
            
            } else {
                break;
            }
        }

        inputfile.close();

    } else {
        fileName = validateFileName(argv[1]);
    }
        tree.buildTree(fileName);
        tree.displayInOrder();

    return 0;
}

//TODO
string validateFileName(string fileName) {
    return fileName;
}
