#include "digits.h"

void Digits::readTrainData(ifstream& input){
    string line;
    string cell;
    int number;
    istringstream lineStream,buffer;

    // Dumping first line
    getline(input, line);
    
    while (getline(input, line)){
	lineStream.str(line);
	lineStream.clear();
	getline(lineStream, cell, Digits::DELIM);
	buffer.str(cell);
	buffer.clear();
	buffer >> number;
	digits.push_back(number);
	vector<int> current_img;

	while(getline(lineStream, cell, Digits::DELIM)){
	    buffer.str(cell);
	    buffer.clear();
	    buffer >> number;
	    current_img.push_back(number);
	}
	images.push_back(current_img);
    }
}

void Digits::readTestData(ifstream& input){
    string line;
    string cell;
    int number;
    istringstream buffer, lineStream;
    
    // Dumping first line
    getline(input, line);
    
    while (getline(input, line)){
	lineStream.str(line);
	lineStream.clear();
	vector<int> current_img;

	while(getline(lineStream, cell, Digits::DELIM)){
	    buffer.str(cell);
	    buffer.clear();
	    buffer >> number;
	    current_img.push_back(number);
	}
	test.push_back(current_img);
    }
}

	    
void Solution::submit(string file){
    ofstream output;
    output.open(file);

    output << "ImageId,Label" << endl;
    
    for (int i=0; i<size(); ++i)
	output << (i+1) << ',' << at(i) << endl;
}
