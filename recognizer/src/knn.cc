#include "knn.h"

void KNN::addInstance(vector<int>& image, int digit){
    train.push_back(image);
    target.push_back(digit);
}

void KNN::fit(Digits& problem){
    train = problem.getTrainImages();
    target = problem.getTrainDigits();
}

double euclidean_d(vector<int>& x, vector<int>& y){
    double suma = 0;
	
    for (unsigned int i=0; i<x.size(); ++i){
	suma += (x[i]-y[i])*(x[i]-y[i]);
    }
	
    return sqrt(suma);
}

double pseudo_euclidean_d(vector<int>& x, vector<int>& y){
    double suma = 0;

    for (unsigned int i=0; i<x.size(); ++i){
	suma += (x[i]-y[i])*(x[i]-y[i]);
    }
	
    return suma;
}

double displacement_d(vector<int>& x, vector<int>& y){
    const int tolerance = 5;
    double left(0), right(0), top(0), bottom(0);
    double value;
    int n = x.size();
    int dim = 28;
    double distance;
    
    for (unsigned int tol = 0; tol < tolerance; ++tol){
	// Row
	for (unsigned int i = 0; i < n/dim; ++i){
	    for (unsigned int j = 0; j < dim; ++j){
		// Displacement to the right
		if (j < (tol+1))
		    right += x[i*dim + j] * x[i*dim +j];
		else{
		    value = (x[i*dim + j - tol - 1] - y[i*dim + j - tol - 1]);
		    value *= value;
		    right += value;
		}
		// Displacement to the left
		if (j > (dim-tol-2))
		    left += x[i*dim + j] * x[i*dim + j];
		else{
		    value = (x[i*dim + j + tol + 1] - y[i*dim + j + tol + 1]);
		    value *= value;
		    left += value;
		}
		
		// Displacement
		if (i < (tol+1))
		    bottom += x[i*dim + j] * x[i*dim +j];
		else{
		    value = (x[(i-tol-1)*dim + j] - y[(i-tol-1)*dim + j]);
		    value *= value;
		    bottom += value;
		}
		// Displacement to the left
		if (i > (n/dim-tol-2))
		    top += x[i*dim + j] * x[i*dim + j];
		else{
		    value = (x[(i+tol+1)*dim + j] - y[(i+tol+1)*dim + j]);
		    value *= value;
		    top += value;
		}
	    }
	}
	distance = min(min(left,right), min(bottom,top));
    }
    return min(distance, pseudo_euclidean_d(x, y));
}

Solution KNN::predict(vector<vector<int>> to_solve, 
		 double (*distance)(vector<int>& x, vector<int>& y), int tolerance3){
    // Vectors of pair distances and digits
    vector<list <pair<double,int>>> k_nearest (to_solve.size());
    // Contains prediction for to_solve set
    Solution prediction(to_solve.size());
    train.reserve(train.size() + to_solve.size());
    target.reserve(train.size() + to_solve.size());

    // For each instance to predict, compute k nearest neighbors    
    #pragma omp parallel for
    for(unsigned int i=0; i<to_solve.size(); ++i){
	k_nearest[i] = list <pair<double,int>>();

	int n_data = train.size();

	for (unsigned int j=0; j<n_data; ++j){
	    k_nearest[i].push_back (make_pair(distance(to_solve[i], train[j]), target[j]));
	    k_nearest[i].sort();
				    
	    if (k_nearest[i].size() > K)
		k_nearest[i].resize(K);
	}
	int max_digit;
	int max_count = 0;
	int current_count = 0;

	// Calculates the predominant digit for current instance of test
	for (unsigned int k=0; k<10; ++k){
	    current_count = 0;
	    
	    for(list<pair<double,int>>::iterator it=k_nearest[i].begin(); it!=k_nearest[i].end(); ++it){
		if((*it).second == k)
		    current_count++;
	    }
	    
	    if(current_count > max_count){
		max_count = current_count;
		max_digit = k;
	    }
	}
	prediction[i] = max_digit;
	#pragma omp critical
	{
	    addInstance(to_solve[i], max_digit);
	}
    }
    return prediction;
}

    
		
	
    
