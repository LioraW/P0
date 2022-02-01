#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "tree.h"
using namespace std;

int main(int argc, char **argv)
{
	fstream inputfile;
    int ARRAY_SIZE = 7;
    string arr[ARRAY_SIZE] = {};
    int count = 0;
    Tree tree;

    if (argc > 1) {
        tree.buildTree(argv[1]);
        tree.displayInOrder();

    } else {
        cout << "No file given. Please type in your text: " << endl;
        string text;

        while (count < ARRAY_SIZE && cin >> text) {
            if (text != "EOF") {
                arr[count] = text;
                count ++;
            } else {
                break;
            }
        }
    }

    // cout << endl << "Here are the words you wrote: " << endl;
    // for (string word: arr)
    //     cout << word << endl;

    return 0;
}
