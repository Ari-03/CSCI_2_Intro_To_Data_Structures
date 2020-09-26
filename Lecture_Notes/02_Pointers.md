# 2 Pointers
## Pointers to Structures
- A structure Variable has an address
- Pointers to structures are variables that can hold the address of a structure
- ```cpp
    Student *sptr = &str1;
  ```
- Structure pointer can be a function parameter.
- We can use **'()'** to dereference **pointer variable**, **not** the **field** within.
- Structure :
    ```cpp
    cout<<(*sptr).studentID << endl;
    ```
- Another way to dereference is by using structure pointer operator **'->'** : to eleminate **'()'** and use clearer notation
    ```cpp
    cout << sptr->studentID << endl;
    sptr->gpa = 3.65;
    sptr->studentID = 12312;
    ```
***
## Structure pointter as a function paramerter
```cpp
void getData(Student *s)
{
    cout << "Enter Name: " << endl;
    getline(cin, s->name);//s.name
    cout << "Enter GPA: " << endl;
    getline(cin, s->gpa);//s.name
    ...
}
```
***
## Dynamically Allocating a Structure
#### *This happens during runtime, not compile time*
```cpp
Circle *cptr = nullptr;//Circle pointer
cptr = new Circle;
cptr->radius = 10;
```
### Dynamically Allocating an array of structures:
- How to make it:  
    ```cpp
   Circle *cptr = new Circle[5];//
    /* How To Access the Array */
    for(int i{}; i<5; i++)
    {
        cout << "Enter the radius for Circle " << (i+1 << ": ";
        cin >> cptr[i].radius;
    }
    ```
***
## Pointers 
#### *Each variable is stored at an unique address in memory(RAM)*
``` cpp
int num = 75;
/* To display address for num */
cout << &num << endl; // Displays hexadecimal --Base 16--
```
### Pointer Variable :
***Holds an address of memory location** which it can also **access** the content of memory*

- pointers are **low lever**(*close to machine language*) than arrays and refrence variables
```cpp
int *iptr; 
/* 
    iptr can hold address of int value. 
    If you don't assign the pointer to anything the address is garbage, and can give undefined behavior.
    ASSIGN your pointers to something, even nullptr.
*/

int x = 25;
int *iptr = &x;
cout << x << endl; /* 25 */
cout << iptr << endl; /* 0x7e00 */
```
- The indirection operator **'*'** dereferences a pointer variable -
```cpp
int x = 35;
int *iptr = &x;
cout << *iptr << endl; /* 35 */
*iptr = 100; /* x = 100 */
cout << x << endl; /* 100 */
cout << *iptr << endl; /* 100 */
cout << *iptr + 1 << endl; /* 101 */
cout << *(iptr + 1) << endl; /* This will move the address by one and it will be garbage */
```
***
## Relationship between arrays and pointers:
```cpp
int vals[] = {4,7,11};
cout << vals << endl; /* Displays address of the first element */
```
- Array name is starting address of arrays:
    ``` cpp
    val[0]; /* 4 */
    val[i]; /* 7 */
    val[2]; /* 11 */

    int *val_ptr = val;
    cout << val_ptr[1]; /* 7 */
    cout << *(val_ptr+1); /* 7 */
    cout << *(val_ptr+2); /* 11 */
    ```
- Must use **'()'** with * to get the values.
    ```cpp
    val[1] == *(val+1);
    ```
- *In C++ There is no bounds checking. **No** Array Index Out Of Bound, RIP*

```cpp
int vals[] = {4,7,11};
int *val_ptr = val;
val_ptr++; /* Points to 7 */
val_ptr--; /* Points to 4 */
cout << *(val_ptr+2); /* 1 */
val_ptr = vals; /* Points to 4 */
val_ptr += 2; /* Points to 11 */ 
cout << val_ptr - vals; /* Diffrence in the number of ints between val_ptr and valsa */
```
- You cannot store diffrent types in pointers
    ```cpp
    double cost = 17.50;
    int *ptr = &cost;
    ```
- There will be an error as the type of the pointer and the type of the cost are diffrent.
***
## Pointer as function paramerter:
```cpp
void getNum(int *ptr); /* Function Prototype */
...
cin >> *ptr; /* To Get data from user and store in *ptr */
...
getNum(&num);  /* Function Call */
```
***
## Dynamic Memory Allocation
```cpp
double *sales;
int numDays;
cout << "Enter number of days : " << endl;
cin >> numDays;
sales = new double[numDays]; 
/* This is Dynamic Memory Allocation */
/* The users input creates the size of Array */
```
***
## Pointer to Pointers 
```cpp
int main()
{
    int x = 5;
    int *p = &x;
    *p = 6;
    int **q = &p; 
    int ***r = &q;
    cout << *p << endl; /* 6 */
    cout << *q << endl; /* &p */
    cout << *(*q) << endl; /* 6 */
    cout << *(*r) << endl; /* &p */
    cout << *(*(*r)) << endl; /* 6 */
}
```