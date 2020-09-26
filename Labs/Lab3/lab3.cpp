/*
    Programmer : Aritra Das
    File Name  : lab3.cpp
    Date       : 9-11-2020
    Version    : 1.2
    Description
    This lab is designed to make a class, TestScore, that will keep trake of the test scores and return the average of the test score.
*/

#include <iostream>
using namespace std;

const int NumberOfTest = 3;

class TestScore
{
private:
    double test[NumberOfTest];

public:
    //This constructor intilizes the all of the test scores to zero if nothing is passed in as a paremeter
    TestScore()
    {
        for (size_t i = 0; i < NumberOfTest; i++)
        {
            test[i] = 0;
        }
        
    }
    //This constructor takes in a array of grade and set the value of the test to the values present in the array
    TestScore(double *t)
    {
        for (size_t i = 0; i < NumberOfTest; i++)
        {
            test[i] = *(t+i);
        }
        
    }
    //Getter function that takes in which test to retrive and returns the testscore
    double getTestScore(int tNumber)
    {
        return test[tNumber];
    }
    //Setter funtion that takes the test number and the nre test score that is want to be set to.
    void setTestScore(int tNumber, double score)
    {
        test[tNumber] = score;
    }
    //Returns the average testscore 
    double getAverageTestScore()
    {
        double avg{};
        for (size_t i = 0; i < NumberOfTest; i++)
        {
            avg += test[i];
        }
        return avg/NumberOfTest;
    }
};

int main()
{
    //Creates an array to store the test score given my the user
    double t[NumberOfTest]{};
    
    //User inputs the test scores
    for (size_t i = 0; i < NumberOfTest; i++)
    {
        cout << "Enter score for Test " << i+1 << endl;
        cin >> t[i];
    }
    TestScore tests(t);

    //Uses the Getter, Setter and the avg Test Score function.
    cout << "Your grade of Test 3 is " << tests.getTestScore(2) << endl;
    tests.setTestScore(2, 100);
    cout << "Your grade of Test 3 is " << tests.getTestScore(2) << endl;

    cout << "Your Average Test Score was : " << tests.getAverageTestScore() << endl;
}