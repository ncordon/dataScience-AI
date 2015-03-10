/**
   @file digits.h
   @brief Headers for the digits problem
**/

#ifndef __DIGITS__
#define __DIGITS__
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;


class Solution:public vector<int>{
 public:
    /**
       @brief Default constructor
    **/
    Solution(){}

    /**
       @brief Constructor with parameters
       @param size of vector
    **/
    
    Solution(int size)
	:vector<int>(size){};
    /**
       @brief Prints solution to file
       @param file which solution will printed to
    **/
    void submit(string file);
};

/**
   @class Digits
   @brief Contains a problem of digits (train set and test set)
**/
class Digits{
 private:
    // Delimiter character of .csv files
    const char DELIM=',';
    // Vector containing digits in images
    vector <int> digits;
    // Vector of images (an image is a vector of size 28x28 of int between 0 and 255)
    vector <vector<int>> images;
    // Test set
    vector <vector<int>> test;
 public:
    /**
       @brief Constructor
    **/
    Digits(){}
    
    /**
       @brief Reads train data from a file
       @param input file to read
    **/
    void readTrainData(ifstream& input);

    /**
       @brief Reads test data from a file
       @param input file to read
    **/
    void readTestData(ifstream& input);

    /**
       @brief Get train images
    **/
    vector<vector<int>> getTrainImages(){
	return images;
    }
    
    /**
       @brief Get train digits
    **/
    vector<int> getTrainDigits(){
	return digits;
    }
    
    /**
       @brief Get test set
    **/
    vector<vector <int>> getTest(){
	return test;
    }
};

#endif

    
