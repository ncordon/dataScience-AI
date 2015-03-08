#include "digits.h"

void Digits::readTrainData(ifstream& input){
    string value;
    int number;
    istringstream buffer;

    // Dumping first line
    getline(input, value);
    

    while (input.good()){
	getline(input, value, Digits::DELIM);
	buffer.str(value);
	buffer >> number;
	digits.push_back(number);
	vector<int> current_img;

	cerr << number;

	// Reading a single image
	while(input.peek()!='\n'){
	    getline(input, value, Digits::DELIM);
	    cerr << value;
	    buffer.str(value);
	    buffer >> number;
	    current_img.push_back(number);
	}
	images.push_back(current_img);
    }
}

void Digits::readTestData(ifstream& input){
    string value;
    int number;
    istringstream buffer;
    
    while (input.good()){
	vector<int> current_img;

	// Reading a single image
	while(input.peek()!='\n'){
	    getline(input, value, Digits::DELIM);
	    buffer.str(value);
	    buffer >> number;
	    current_img.push_back(number);
	}
	
	test.push_back(current_img);
    }
}

	    
