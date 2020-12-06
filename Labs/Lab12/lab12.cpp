/*
    Programmer : Aritra Das
    File Name  : lab11.cpp
    Date       : 11-14-2020
    Version    : 1.2
    Description: This program makes a test score class that trown exception when test score is negative or above 100 and find the avg value of all the testscores.
*/

#include <iostream>
#include <vector>
using namespace std;

//The test score class that throws Exception when a negative or number greater that 100 is given
class Date
{
private:
    vector<double> testArry;//Vector to store tests
public:
    class invalidTestscore{};//Class that is thrown as an exception  
    Date(vector<double> tArray);//Constructor that initilizes the testArray and throw exception if invalid input is given
    double avgTestScore();//Finds the average test score
};

int main()
{
    int numOfTest{};//Gets how many time the question is asked
    double input{};//The test score values
    vector<double> testArray;

    cout << "Enter the number of test do you wish to input : ";
    cin >> numOfTest;//input
    //If the number is negation we for num of test we ask user to another number
    while (numOfTest < 0)
    {
        cout << "The Number of Test cannot be Negative. Please Enter Another Value for Number of Test. : ";
        cin >> numOfTest;
    }
    
    //We input the number of test.
    for (size_t i = 0; i < numOfTest; i++)
    {
        cout << "Enter Your Score for Test " << i+1 << " : ";
        cin >> input;
        testArray.push_back(input);
    }
    //We use try block to catch the exception
    try
    {
        //If the test score array has negative or score > 100 there exception will be thrown
        Date Test(testArray);
        //Find and display the avg score
        double avg = Test.avgTestScore();
        cout << "The Average Test Score is : " << avg << endl;
    }
    catch(Date::invalidTestscore)
    {
        cout << "One of the Test Score you enter is invalid. Please enter again" << endl;
    }
    return 0;
}

Date::Date(vector<double> tArray)
{
    //For all Testscore in the array we see if there is any that is negative or < 100, if so we throw an exception.
    for (double testScore : tArray)
    {
        if(testScore < 0 || testScore > 100)
            throw invalidTestscore();
    }
    testArry = tArray;
}

double Date::avgTestScore()
{
    //Simpele sum of all test score and dividing by number of items
    int sum{}, counter{};
    for(double testScore : testArry)
    {
        sum += testScore;
        counter++;
    }
    return sum/counter;
}
