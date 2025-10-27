<div align="center">
<h1> Algorithms and Parallel Computing
</div>
<div align="center">
    <em>Juan Pablo Vallejo Montañez</em><br>
    <em>Notes from Politecnico di Milano 2025/2026 Y.</em><br>
</div>

# C++.
stars from C.
C and C++ have the goal to build programs with good performance and efficenty.

C++ is faster than others OO languages 

What is the types of programming languages


The strong item for Java is the portability.

Low level pogramming - machine legnuage (binary code)

In high level computer programming we have styles of pogramming

- Procedural Programming
- Object-Oriented Programming
- Functinal Programming

Tok complete this notes, put the process of compilation and linking for C++.


Classes  is a template

Objetc is a instance of the class



Boilerplate code refers to sections of code that are repetitive and standardized, often required in multiple places within a program or application with little to no modification. It is commonly used to set up the basic structure or framework for a program, ensuring consistency and efficiency.


Structure for code..

 -Libraries
 -



Caraterusctucs: 
-What is a statment?

A statment can be a delcaration or a math expressionot a control statment 
- A statment thta indtroudces a variables is called DECLARATION


-The final retunr 0 is optional in main () fuction but you may need to include it to pacify your compiler

cout with <<
cin with >>
endl manipulator 

In C++, std::endl is a manipulator used with output streams (like std::cout) to insert a newline character (\n) and flush the output buffer. Here's a breakdown of its behavior and when to use it:


Difference between C and C++
- Mostly differences are cosmetic 
- definition of char in c is with fixed length (char name[100] and in c++ the string is variable-lenght)



Standard I/O


-iostream library (studi.io in C) provides I/O (input and output)
istream - input instream
output - output stream
stream -- sequenece of charcaters read/wirte from/to and I/O device

cin - handgles input
cout - handles output
cerr - used for warning  and error messages
clog - used for general informationabout the execution of the program
andl -- ending the current line and flushing the  buffer assocuaited with the device ( what us flushing????)

the cin reads charcaters until a whitespace charcater is seen.
Whitespace: Space, tab, new line
Retunr only when you hint the eneter
Its means that you can write a lot of words seprated by spaces. Then, the cin only takes the first word before the first whitespace but only when yoy hit the enter

If you put two variables in the cin, you can read two words separated by one whitesapce
cin>> variable1 >> variable2

we can use stream as a condition (if or while)
An stream becomes  invalid when we hit end-of-file or encounter an invalid input- Then the condition will be false
____________________________

Operations
+ concatenates strings
+=s add the string s at end
+s is error
- isan error


Arithmenthcs 


Namespaces  

--- in the first escenario is not neccesary but in larges code is better to include them 

A namespace is a fundamental concept in computing and programming that helps in organizing and managing identifiers such as variables, functions, classes, and other entities. It ensures that all identifiers within a given set are unique, preventing naming conflicts and allowing for better code organization.

All the names included by the standart library are in the std namespace

Namespaces allow us to  avoid inadvertetn collisions between the names we define uses of those same names inside a library


We have to use the scope operator :: to say that a variable belongs to a namespace EX : std::cin

There is other example and is using decalration
using std::cin;
using std::cout;
using std::endl;
at the first part of the code and in the body you can use the variables without the namespace

or we can write using namespace std; in the header of the code but in large files is bad practice ..

What is a header ?????



__________

Build-in Types

The types of a variable determines
    - the domain for the variable
    - which operations are valid

C++ provides  a set of types like bool, char, int, double
In c++ can define new types 
the c++ standart library provides a set of types like string, vector, complex


integers (short, long, unsigned)
float (double or float)
bool
char
standard-librry types
    string 
    complex<double>
    complex<float>

WHAT IS UNSIGNED

    MORE DETAILS OF THIS IN THE BOOK

C++ Datatypes --- search the size and range in memeoty for each data type

DElcaration and initialization.
For the majorty od the data types is simple

For the string when i put string s1 = "Hello World!" in memory the string works like 12|"Hello World!  . The first one is the length

A variable must be used only after it has been initialized
only operators defined for the variable declarad type will be applied and every operator defined for a variable leave sthe variablewith  a valid value 


What is the differeence between Runtime error and compile time error.


Changes from one datatype to another may lost information. Example int i = 2000 and then char m = i , m is not 2000 is the conversion of 2000 to a char format  
very bad things do happen be very careful. Overflows and/or implicit narrowing are around  the corner

A variable without an initializaer (int x;) is default-initialized ( the value in undetermined)

If we asisign an out-of-range value to a varaibleof signed type the result is undefined 

 Equality operator == (equal) != not equal
 Logical operator && and , || or , ! not
 RElation opratiosn < less than > more than

 For integer and  floating point types +,-,*,/


____________________
Control structures:

top down --break up big computations into manylittle ones
bottom-up provide a higher level concept that hides details


iteriators

while lopp
do - while loop
for loop


Functions 

We define functions when we want to separatea computation because is :
 - logically separate
 - makes the program clear
 - 

C++ Strucutre :

 - Low-level language (inhertit from C)
 - Advanced languages features
 - standart library 
https://www.stroustrup.com/applications.html


________________________________________

DEclararion and definitons

declaration introduces a name into the scope
what is scpope????


declaration also specifeies a type for the namedobject
Sometimes a decalartion useda initilizer
A name must be decalred before it can be used in a C++ program

int a --- declared
int a = 1 declarad and initialized

what is definiton 
A definition provides the actual implementation or allocates memory for the declared entity. It tells the compiler "this is what it is."

A declaration that also full espesify the declared entity is a definition

double sqrt (double x){
    .....
}


struct point (declaration)
Struct pint{
    int age;
    int heifhht
}  (definiton)  -- Review this and be sure that is correct 


You cannot define somthing twice

int a ;
int a ; is a error



But we can decalrate something tiwice
double sqrt(double);    (declararion)
double sqrt(double) {....}  (definiotn also a declaration)

Place all the declarations  in HEADER FILES to ease sahring 

________________________________

HEADER FILES

As programs grow larger you make use of more code files
cpp. files ---- implementarion
header files (h.extesnion) .--- it ouropuse of the header file is to propagate to code files


Heade file holds decalaration of functions, types, constants and another compoenents

A header  file gives you access to functions, types, etc

#ifndef MY_LIBRARY
#define MY_LIBRARY

void bar();


#endif


the definition of vaid bar is in the cpp. file 

cpp file -----

#include <iostream>
#include "MyLibrary.h"

void bar(){
    -................
    rerunt;
}