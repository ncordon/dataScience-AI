#include "digits.h"
#include "knn.h"

int main(){
    ifstream train_file("./data/train.csv");
    ifstream test_file("./data/test.csv");

    Digits problem;
    problem.readTrainData(train_file);
    problem.readTestData(test_file);
    
    int k=1;
    KNN predictor(k, problem);
    predictor.predict(problem.getTest()).submit("./data/knn_1.csv");
}
