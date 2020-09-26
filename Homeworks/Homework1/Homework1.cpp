/*
    Programmer : Aritra Das
    File Name  : lab1.cpp
    Date       : 8-26-2020
    Version    : 1.0
    Description
    This program askes the user for they budget for the month and compare it with a pre-exsisting budget to tell them wheather they are over budget or under budget
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Function prototypes 
struct MonthlyBudget;
void isUnderOrOver(int i, string name);
MonthlyBudget askBudget();
void BudgetDiffrence(const MonthlyBudget &planedBudget, const MonthlyBudget &actualBudget);

//This is the budget structure that keeps track of all the catigory of spending
struct MonthlyBudget
{
    double Housing;
    double Utilities;
    double Household_Expenses;
    double Transportation;
    double Food;
    double Medical;
    double Insurance;
    double Entertainment;
    double Clothing;
    double MISC;
};

// Executes the program to see wheather the budget is over or under, and in what categories
int main() 
{
    MonthlyBudget planedBudget = {500,150,65,50,250,30,100,150,75,50};
    MonthlyBudget actualBudget = askBudget();
    cout << endl;
    BudgetDiffrence(planedBudget, actualBudget);
}

// This is a function that returns a MonthlyBudget type populated with user created data
MonthlyBudget askBudget()
{
    MonthlyBudget budget;
    cout << "Enter your budget for the following catagories -\n";

    cout << "Housing : ";
    cin >> budget.Housing;
    cout << "Utilities : ";
    cin >> budget.Utilities; 
    cout << "Household_Expenses : " ;
    cin >> budget.Household_Expenses ;
    cout << "Transportation : " ;
    cin >> budget.Transportation ;
    cout << "Food : " ;
    cin >> budget.Food ;
    cout << "Medical : ";
    cin >> budget.Medical;
    cout << "Insurance : ";
    cin >> budget.Insurance;
    cout << "Entertainment : ";
    cin >> budget.Entertainment ;
    cout << "Clothing : " ;
    cin >> budget.Clothing ;
    cout << "MISC : " ;
    cin >> budget.MISC ;

    return budget;
}

// This function see where they are diffrent and tell if they are overbudget or under budget
void BudgetDiffrence(const MonthlyBudget &planedBudget, const MonthlyBudget &actualBudget)
{
   double balance{}; //Makes a balace double
   MonthlyBudget Diffrence = {actualBudget.Housing-planedBudget.Housing, actualBudget.Utilities-planedBudget.Utilities, actualBudget.Household_Expenses-planedBudget.Household_Expenses,actualBudget.Transportation-planedBudget.Transportation, actualBudget.Food-planedBudget.Food, actualBudget.Medical-planedBudget.Medical, actualBudget.Insurance-planedBudget.Insurance, actualBudget.Entertainment-planedBudget.Entertainment,actualBudget.Clothing-planedBudget.Clothing, actualBudget.MISC-planedBudget.MISC};//Makes a MonthlyBudget witht the diffrence of the actual and planned
   
   //Adds all the diffrence to balance to see whether budget all together is over, or under
   balance += Diffrence.Housing;
   balance += Diffrence.Clothing;
   balance += Diffrence.Entertainment;
   balance += Diffrence.Food;
   balance += Diffrence.Household_Expenses;
   balance += Diffrence.Insurance;
   balance += Diffrence.Medical;
   balance += Diffrence.MISC;
   balance += Diffrence.Transportation;
   balance += Diffrence.Utilities;
   
   //Prints out the categories that went over or under
   isUnderOrOver(Diffrence.Housing, "Housing");
   isUnderOrOver(Diffrence.Utilities, "Utilities");
   isUnderOrOver(Diffrence.Household_Expenses, "Household_Expenses");
   isUnderOrOver(Diffrence.Transportation, "Transportation");
   isUnderOrOver(Diffrence.Food, "Food");
   isUnderOrOver(Diffrence.Medical, "Medical");
   isUnderOrOver(Diffrence.Insurance, "Insurance");
   isUnderOrOver(Diffrence.Entertainment, "Entertainment");
   isUnderOrOver(Diffrence.Clothing, "Clothing");
   isUnderOrOver(Diffrence.MISC, "MISC");
   isUnderOrOver(balance, "balance");
   if(balance == 0)
   {
       cout << "You are on budget" << endl;
   }
}

void isUnderOrOver(int i, string name)
{
    if(i > 0)
   {
        cout << "Your budget for " << name << " is over by Amount : " << i<< endl;
        
        
   }
   else if (i < 0)
   {
       cout << "Your budget for " << name << " is under by Amount : " << i<< endl;
   }
}