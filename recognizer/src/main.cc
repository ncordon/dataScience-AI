#include "digits.h"

int main(){
    ifstream train_file("./data/train.csv");
    ifstream test_file("./data/test.csv");

    Digits problem;
    problem.readTrainData(train_file);
    problem.readTestData(test_file);

    //cout << problem.getTrainImages().size();
}
