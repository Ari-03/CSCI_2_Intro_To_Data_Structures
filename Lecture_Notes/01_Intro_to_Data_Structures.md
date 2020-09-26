# 1 : Intro to Data Structures - Aug 22, 2020
## What the professor grades on
1. ### How to write a **Version Control**
```cpp
/*
    programmer : Aritra Das
    File Name  : bob.cpp
    Date       : 8-22-2020
    Version    : 1.0
    Description
    This is what the program does
*/
```
2. ### **Inline Comment**
3. ### **Proper Grouping** with New Lines and General Organization
***
## Three diffrent types of Function call
1. Call by **Value**
2. Call by **Reference** 
3. Call by **Pointer**


### Call By **Value** 
```cpp
void swap(int x, int y);//Function prototype
```

### Call by **Reference**
```cpp
void swap(int &x, int &y);
```

### Call by **Pointer**
```cpp
void swap(int *x, int *y);
```
***
## Structures 

| Term | Defination |
|--|--|
| **ADT**(abstract data type) | It is a **programmer**'s defined data type |
| **Data Type** | Type of **value stored in memory**(ram) and **type of operation we are allowed** > *Ex.) We cannot divide or multiply char or string values* |
| **Abstraction** | A definition that captures **general** charecteristic **without details** |
| **Structure** | C++ construct allows **multiple variable** to be **grouped** together |
***
## How to make Sturcture 

```cpp
struct <struct Name>
{
    type1 feild1;
    type2 feild2;
};// YOU NEED THIS ; TO CREAT STRUCT. VERY IMPORTANT.
```
### EX.)
```cpp
struct Student//Good programming conduct to have struct name capitalize
{
    int studentID;
    string name;
    short yearInSchool;
    double goa;
};// YOU NEED THIS ; TO CREAT STRUCT. VERY IMPORTANT.
```
### Structures declation does not allocate memory or create variable
### We use dot(.) operator to access to the member of the struct variable
```cpp
Student student1;
student1.studentID = 1;
```

### Cannot print out Struct Variable with | EX | cout << st1
### Cannot compare Struct Variable directly | EX | st1 == st2
***
## How to Initilize a Structure
```cpp
Student st1 = {111010, "Bob the Builder", 2, 4.40};
OR 
st1.name("Bobo Bob");
st1.gpa(5.0);
OR
Student st2 = {111111, "JoJo Jostar"};
```
### You can initilize a stucture **all together**, **one a time**, or **patially**

### Cannot initilize in the structure declaration, since Struct does not allocate memory

***
## Array Of Structure
```cpp
const int arrSize =  100;
Student stList[arrSize];
...
cout << stList[4].gpa;//fifth student's gpa
```
***
## Nested Structure
```cpp
struct PersonInfo
{
    string name, address;
};
struct Student
{
    int studentId;
    PersonInfo pData;
    short yearInSchool;
    double gpa;
}
//To access the PersonInfo
int main()
{
    Student Bob;
    Bob.pData.name = "Bob";
}
```
- In structure declaration, we can have member functions.
- Structure as function arguments
  - CalcGpa(st1.gpa);
- Pass the entire struct variable to a function
  - ```cpp 
        void showData(Student S)
        {
            cout << s. name << endl;
            cout << s.gpa << endl;
            //etc
        }
    ```
- We can use refrence parameter if function needs to modify content of structure variable
  - Using value parameter can slow down a program, and waste of space
  - Using refrence parameter will in most cases speed up programs
  - Use ***const*** when you don't want to edit the struct
  - ```cpp
        void showData(const Student &S)
        {
            cout << s. name << endl;
            cout << s.gpa << endl;
            //etc
        }
    ```
- A function can return a struct Variable
  - ```cpp
        Student getData();//prototype function
        ...
        Student st1 = getData();
        ...
        Student getData()
        {
            Student temp;
            cin >> temp.studentId;
            getLine(cin, temp.pData.name);
            ...
            return temp;
        }
    ```
***
## Pointers to Structures
- A structure variable has an address
  - pointer to structure are variable that can hold the address of a structures
***
