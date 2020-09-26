/*
    Programmer : Aritra Das
    File Name  : homework2.cpp
    Date       : 9-2-2020
    Version    : 1.0
    Description
    Find the median value out of an array of ints. Gives an array and the size.
*/
#include <iostream>
#include <random>
using namespace std;

double findMedian(int *arr, int max);

int main()
{
    int arr1[1] = {6}; //Testing with only 1 element in the array
    double median = findMedian(arr1, 1);
    cout << "The median of the array : " << median << endl;

    int arr2[4] = {1,2,3,4}; //Testing with even number of elements in the array
    median = findMedian(arr2, 4);
    cout << "The median of the array : " << median << endl;

    int arr3[3] = {5,12,43}; //Testing with odd number of elements in the array
    median = findMedian(arr3, 3);
    cout << "The median of the array : " << median << endl;
}

double findMedian(int *arr, int size) //FindMedian function takes in a sorted array 
{
    double median{};  //The variable that will return the median
    int medianPosition = size/2; //Median position will be in the half of the size

    if(size == 1) //If there is only 1 element in the array it will be returned
        return *(arr);
    
    if(size%2 == 0)
        median = (static_cast<double>(*(arr+medianPosition-1)) + *(arr + medianPosition))/2; //If the array has even elements it finds the average of the middle two elements
    else
        median = *(arr + medianPosition); //Returns he middle value of the array
    
    return median;

}
