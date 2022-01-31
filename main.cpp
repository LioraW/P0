#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{

	const int ARRAY_SIZE = 5;
	int grades[ARRAY_SIZE] = {1,2,3,4,5};
	int count = 0;
	fstream inputfile;

	inputfile.open("file.sp2022");


	// reading the file into the array
	//while (count < ARRAY_SIZE && inputfile >> grades[count]) 
	//	count++;

    if (inputfile.is_open()) {
        string line;

        cout << "File opening successfull!!" << endl;
        while (getline(inputfile, line)) { //while ( inputfile >> line) {
            std::cout << "Line 1: " << line << std::endl;
        }
    } else {
        std::cerr << "Unable to open file:  file.sp2022" << std::endl;
        return -1;
    }   

	inputfile.close();
    std::cout << "hi " << std::endl;
    // for (int i = 0; i < ARRAY_SIZE; i++){
    //     cout << grades[i] << endl;
    // }
	//print all the scores
	// for (int index : grades)
	// 	cout << index << endl;

}
