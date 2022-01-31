#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	fstream inputfile;

    cout << argv[0] << " " << argv[1] << endl;

    if (argc > 1) {
        inputfile.open(argv[1]);

        if (inputfile.is_open()) {
            string line;

            cout << "File opening successful" << endl;
            while (inputfile >> line) {
                cout << line << endl;
            }
        } else {
            cerr << "Unable to open file: " << argv[1] << endl;
            return -1;
        }   

        inputfile.close();
    
    } else {
        cout << "No file given" << endl;
    }

    // for (int i = 0; i < ARRAY_SIZE; i++){
    //     cout << grades[i] << endl;
    // }
	//print all the scores
	// for (int index : grades)
	// 	cout << index << endl;

}
