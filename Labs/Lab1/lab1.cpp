/*
    Programmer : Aritra Das
    File Name  : lab1.cpp
    Date       : 8-26-2020
    Version    : 1.0
    Description
    This program creates a MovieData structure and creates two moveie object in the main
*/

#include <iostream>
#include <string>

using namespace std;

//This creates the MovieData Stucture
struct MovieData
{
    //This is the members of the Structure
    string Title;
    string Director;
    int Year_Released;
    int Running_Time;
   
    //Prints out all of the members of the function
    void printMovie()
    {
        std::cout << "Title : " << Title << endl << "Director : " << Director << endl << "Year Released : " << Year_Released << endl << "Running Time (in minutes) : " << Running_Time << endl;
    }
};

int main() 
{
    //Makes and populates the Movies
    MovieData A_Silent_Voice = {"A Silent Voice","Naoko Yamada", 2016, 130};
    MovieData Ponyo = {"Ponyo", "Hayao Miyazaki", 2009, 103};
    
    //Prints out the Movie
    A_Silent_Voice.printMovie();
    cout << endl;
    Ponyo.printMovie();
}