#include "digits.h"
#include <cmath>
#include <list>
#include <utility>
#include <algorithm>

/**
   @brief Implements euclidean distance
   @param x instance of image
   @param y instance of image
   @pre x.size == y.size
**/
double euclidean_d(vector<int> x, vector<int> y);
double pseudo_euclidean_d(vector<int> x, vector<int> y);



/**
   @class KNN
   @brief Contains definitions and functions to work with KNN classifier algorithm
**/

class KNN{
 private:
    // Set of train data
    vector<vector <int>> train;
    // Set of classified train data
    vector<int> target;
    // Number of neighbors
    const int K;

 public:
    /**
       @brief Allows to introduce the train and target set of datas
    **/
    void fit(Digits& problem);

    /**
       @brief Constructor with train data provided
       @param train set of data
       @param target classification for given train data
    **/
    KNN(int neighbors, Digits& problem) 
	:K(neighbors){
	fit(problem);
    }
    
    /**
       @brief Default constructor
    **/
    KNN(int neighbors)
	:K(neighbors){}

    /**
       @brief Allows to add an element and its related prediction to the KNN
    **/
    void addInstance(vector<int>& image, int digit);
    
    /**
       @brief Does a prediction for a given set of images
       @param test containing images to predict
       @return prediction for given test data
    **/
    Solution predict(vector<vector<int>> to_solve, 
		     double (*distance)(vector<int> x, vector<int> y) = pseudo_euclidean_d);
};
