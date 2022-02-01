#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	fstream inputfile;
    int ARRAY_SIZE = 7;
    string arr[ARRAY_SIZE] = {};
    int count = 0;

    if (argc > 1) {
        inputfile.open(argv[1]);

        if (inputfile.is_open()) {
            string line;

            cout << "File opening successful" << endl;
            while (count < ARRAY_SIZE && inputfile >> arr[count]) {
                count++;
            }
        } else {
            cerr << "Unable to open file: " << argv[1] << endl;
            return -1;
        }   

        inputfile.close();
    
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

    cout << endl << "Here are the words you wrote: " << endl;
    for (string word: arr)
        cout << word << endl;

    return 0;
}
