#include "knn.h"

void KNN::addInstance(vector<int>& image, int digit){
    train.push_back(image);
    target.push_back(digit);
}

void KNN::fit(Digits& problem){
    train = problem.getTrainImages();
    target = problem.getTrainDigits();
}

double euclidean_d(vector<int> x, vector<int> y){
    double suma = 0;
	
    for (unsigned int i=0; i<x.size(); ++i){
	suma += (x[i]-y[i])*(x[i]-y[i]);
    }
	
    return sqrt(suma);
}

double pseudo_euclidean_d(vector<int> x, vector<int> y){
    double suma = 0;

    #pragma omp parallel for
    for (unsigned int i=0; i<x.size(); ++i){
	double value = (x[i]-y[i]);
	value *= value;

	#pragma omp atomic
	suma += value;
    }
	
    return suma;
}

Solution KNN::predict(vector<vector<int>> to_solve , double (*distance)(vector<int> x, vector<int> y)){
    // Vectors of pair distances and digits
    vector<vector <pair<double,int>>> k_nearest (to_solve.size());
    // Contains prediction for to_solve set
    Solution prediction(to_solve.size());

    // For each instance to predict, compute k nearest neighbors    
    #pragma omp parallel for
    for(unsigned int i=0; i<to_solve.size(); ++i){
	k_nearest[i] = vector <pair<double,int>>();

	for (unsigned int j=0; j<train.size(); ++j){
	    k_nearest[i].push_back (make_pair(distance(to_solve[i], train[j]), target[j]));
	    sort(k_nearest[i].begin(), k_nearest[i].end());
				    
	    if (k_nearest[i].size() > K)
		k_nearest[i].resize(K);
	}
	int max_digit;
	int max_count = 0;
	int current_count = 0;

	// Calculates the predominant digit for current instance of test
	#pragma omp parallel for
	for (unsigned int k=0; k<10; ++k){
	    current_count = 0;
	    
	    for(vector<pair<double,int>>::iterator it=k_nearest[i].begin(); it!=k_nearest[i].end(); ++it){
		if((*it).second == k)
		    current_count++;
	    }
	    
	    if(current_count > max_count){
		max_count = current_count;
		max_digit = k;
	    }
	}
	prediction[i] = max_digit;
    }
    return prediction;
}

    
		
	
    
