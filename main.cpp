#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{

	const int ARRAY_SIZE = 5;
	int grades[ARRAY_SIZE] = {1,2,3,4,5};
	int count = 0;
	ifstream inputfile;

	inputfile.open("file.sp2022");


	// reading the file into the array
	while (count < ARRAY_SIZE && inputfile >> grades[count]) 
		count++;

    if (inputfile.is_open()) {
        std::string line;

        std:: cout << "File opening successfull!!" << endl;
        while (inputfile >> line) {
        std::cout << "Line 1: " << line << std::endl;
        }
    } else {
        std::cerr << "Unable to open ile:  file.sp2022" << std::endl;
        return -1;
    }   

	inputfile.close();
    cout << "hi " << endl;
    // for (int i = 0; i < ARRAY_SIZE; i++){
    //     cout << grades[i] << endl;
    // }
	//print all the scores
	// for (int index : grades)
	// 	cout << index << endl;

}
