#include "digits.h"

void Digits::readTrainData(ifstream& input){
    string line;
    string cell;
    int number;
    istringstream buffer, lineStream;
    
    // Dumping first line
    getline(input, line);
    

    while (getline(input, line)){
	lineStream.str(line);
	getline(lineStream, cell, Digits::DELIM);
	buffer.str(cell);
	buffer >> number;
	digits.push_back(number);
	vector<int> current_img;

	while(getline(lineStream, cell, Digits::DELIM)){
	    buffer.str(cell);
	    buffer >> number;
	    digits.push_back(number);
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

	    
