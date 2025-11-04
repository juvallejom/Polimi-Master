<div align="center">
<h1> Algorithms and Parallel Computing
</div>
<div align="center">
    <em>Juan Pablo Vallejo Montañez</em><br>
    <em>Notes from Politecnico di Milano 2025/2026 Y.</em><br>
</div>

# 0. Content
 - [Introduction to C++](#1-introduction-to-c)
 - [Terminology](#2terminology)
# 1. Introduction to C++
<div align="justify">
C and C++ are programming languages designed with the goal of achieving high performance and efficiency.

- C is a procedural language that allows close interaction with hardware and memory.
- C++ extends C by adding object-oriented, generic, and functional programming features, while maintaining the same focus on speed and low-level control.
- C++ is generally faster than many other object-oriented languages (such as Java or Python) because it is compiled to native machine code and provides fine-grained control over memory management.

<i style="color:#2E86C1;">Types of Programming Languages</i><br>
Programming languages can be broadly categorized based on their level of abstraction and programming paradigm.<br>
By Abstraction Level
- <strong>Low-level languages:</strong> These are close to the hardware, such as machine language (binary code) or assembly language.
They are fast but hard to write and maintain.

- <strong>High-level languages:</strong>
These are closer to human language and abstract away hardware details.
Examples include C, C++, Java, Python, and Go.<br>

  <i>Note :A strong feature of Java is <strong>portability</strong>. It runs on the Java Virtual Machine (JVM), which allows the same compiled code to run on any system that has a JVM. </i>

<strong style="color:#FF0000;">I think there are a lot of ways to organise the programming languages "Maybe study this later.</strong>

<i style="color:#2E86C1;">Programming Paradigms (Styles of Programming)</i><br>
High-level programming languages often support one or more programming paradigms:
- <strong>Procedural Programming:</strong> Focuses on writing procedures or functions that operate on data (e.g., C).
- <strong>Object-Oriented Programming (OOP):</strong> Organizes code into objects that combine data and behavior (e.g., C++, Java).
- <strong>Functional Programming:</strong> Emphasizes functions as first-class citizens and avoids changing state (e.g., Haskell, Lisp, Python, C++17+ (partially)).
</div>



////////////////////////////////////

Explain how it works the programming paradigms and then what is the bottom-up aprppach processing. -- Read the book then do a summray here and add the mimages of the notebook.

Tok complete this notes, put the process of compilation and linking for C++.


Classes  is a template

Objetc is a instance of the class



Boilerplate code refers to sections of code that are repetitive and standardized, often required in multiple places within a program or application with little to no modification. It is commonly used to set up the basic structure or framework for a program, ensuring consistency and efficiency.

///////////////////////////////////////////////////
<div align="justify">
<i style="color:#2E86C1;">C++ Code Structure</i><br>
C++ can be understood as having three main components:

- <strong>Low-level Language Features:</strong> (largely inherited from C). These provide direct control over memory and hardware resources.
    - Data types
    - Flow control (if, while, for, etc.)
    - Functions
    - Arrays
    - Pointers

- <strong>Advanced Language Features: </strong>Used to define custom data types and enable more abstract, reusable code.
    - Classes
    - Inheritance
    - Polymorphism
    - Templates
- <strong>Standard Library: </strong>A collection of predefined data structures, algorithms, and utilities that make C++ more powerful and convenient.
    - Containers (e.g., vector, map, set, list)
    - Iterators
    - Algorithms (e.g., sort, find, for_each)
</div>

///////////////////////////////

Caraterusctucs: 

-The final retunr 0 is optional in main () fuction but you may need to include it to pacify your compiler

cout with <<
cin with >>
endl manipulator 

In C++, std::endl is a manipulator used with output streams (like std::cout) to insert a newline character (\n) and flush the output buffer. Here's a breakdown of its behavior and when to use it:


Difference between C and C++
- Mostly differences are cosmetic 
- definition of char in c is with fixed length (char name[100] and in c++ the string is variable-lenght)



# 2. Standard I/O.

<div align="justify">
A <strong>stream</strong> is a sequence of characters that flows between the program and an <i>I/O device (input and output)</i>.
It can be used to read or write data.<br>

 - <i>istream</i> is the  input stream.
 - <i>output</i> is the  output stream.

The <strong>iostream</strong> library (similar to <i>stdio.h</i> in C) provides facilities for input and output (I/O) operations.

| Stream | Type          | Description                                       |
| ------- | ------------- | ------------------------------------------------- |
| `cin`  | Input stream  | Handles user input (keyboard).                    |
| `cout` | Output stream | Handles normal program output (screen).           |
| `cerr` | Error stream  | Used for warning and error messages (unbuffered). |
| `clog` | Log stream    | Used for general information or logs (buffered).  |

`endl` Ends the current line and flushes the buffer associated with the output device.
<strong style="color:#FF0000;">( what us flushing????)</strong>

<i style="color:#2E86C1;">Input Behavior with cin</i><br>
The `cin`  stream reads characters until it finds a whitespace charcater. Whitespace charcaters include: Space ` ` ; Tab `\t` ; New Line `\n`.<br>
The input operation with cin only completes when you press <strong>Enter</strong>.It means, you can type many words separated by spaces, but when you press <strong>Enter</strong>, `cin` only takes the first word before the first whitespace character.
The rest of the words remain in the input buffer.

To summarize, while typing, you can write several words separated by spaces, but `cin` will only take the first word.

If you put two variables in the cin, you can read two words separated by a whitespace.
````cpp
cin >> variable1 >> variable2;
````

We can use `cin`  directly as a condition in if or while statements. A stream evaluates to true as long as input operations succeed.
It becomes false when:

 - The end-of-file (EOF) is reached, or
 - An invalid input occurs (for example, entering a letter when a number is expected).

````cpp
 int number;

while (cin >> number) {
    cout << "You entered: " << number << endl;
}
````
The loop continues as long as valid integers are entered. When the user types something invalid (like a letter) or the input reaches EOF,
the stream becomes invalid, and the condition becomes false, ending the loop.
</div>

///////////////////////////////////////////////


Operations
+ concatenates strings
+=s add the string s at end
+s is error
- isan error


Arithmenthcs 

///////////////////////////////////////////////

# 3.Namespaces.
<div align="justify">
A namespace is a <strong>named scope</strong>. It provides a way to group related identifiers (such as variables, functions, and classes) under a single name.<br>
A namespace is a fundamental concept in programming used to organize and manage identifiers such as variables, functions, classes, and other entities.<br>
Namespaces ensure that all identifiers within a given context are unique, helping to prevent naming conflicts and allowing for better code organization and help us avoid unintended naming collisions between the identifiers we define and those defined in other libraries.<br>
All the names defined by the <i>Standard Library</i> are in the <code>std</code> namespace.
</div>

<i style="color:#2E86C1;">Use</i><br>
We use the scope resolution operator <code>::</code> to indicate that a variable, function, or class belongs to a specific namespace.
For example:

````cpp
std::cin >> value;
````

A using declaration can be placed at the beginning of the code.
It allows you to use specific identifiers from a namespace without writing the namespace prefix in the body of the program. For example:

````cpp
using std::cin;
using std::cout;
using std::endl;

int main() {
    cout << "Enter a number: ";
    int n;
    cin >> n;
    cout << "You entered: " << n << endl;
}
````

Alternatively, we can write
````cpp
using namespace std;
````

at the beginning of the code.
This allows us to use all the identifiers from the <code>std</code> namespace without the <code>std::</code> prefix.
<i style="color:#FF0000;">However, in large projects, this is considered bad practice because it can cause naming conflicts between the standard library and user-defined identifiers.</i>

Namespaces are not strictly required for small programs,
but they become very important as your codebase (or project) grows.


# 4.Build-in Types in C++.

<div align="justify">
The type of a variable determines:

 - The domain of values it can hold
 - Which operations are valid for it

C++ provides several built-in (primitive) types, and also allows defining new types.

The <i>C++ Standard Library</i> adds many commonly used types such as string, vector, and complex.

<i style="color:#2E86C1;">Built-in Fundamental Types</i>

| Category | Examples | Description |
|-----------|-----------|-------------|
| **Integer types** | `short`, `int`, `long`, `unsigned` | Store whole numbers (positive, negative, or only positive for `unsigned`). |
| **Floating-point types** | `float`, `double`, `long double` | Store real numbers with decimal fractions. |
| **Boolean type** | `bool` | Represents `true` or `false`. |
| **Character type** | `char` | Represents a single character (e.g. `'A'`, `'3'`). |

- <i>Note: An <strong>unsigned</strong> type can store only non-negative values,
which effectively doubles the maximum positive range compared to its signed version.</i>

<i style="color:#2E86C1;">Sizes and Ranges of Common Data Types in C++ </i>

| S. No | Data Type             | Size (in bytes) | Range                          |
|:------|:----------------------|:----------------|:-------------------------------|
| 1 | `short int`              | 2 | -32,768 to +32,767 |
| 2 | `unsigned short int`     | 2 | 0 to 65,535 |
| 3 | `long int`               | 4 | -2,147,483,648 to +2,147,483,647 |
| 4 | `float`                  | 4 | 3.4e−38 to 3.4e+38 |
| 5 | `char`                   | 1 | -128 to +127 |
| 6 | `unsigned char`          | 1 | 0 to 255 |
| 7 | `unsigned long int`      | 4 | 0 to 4,294,967,295 |
| 8 | `double`                 | 8 | 1.7e−308 to 1.7e+308 |
| 9 | `long double`            | 10 | 1.7e−308 to 1.7e+308 |


<i style="color:#2E86C1;">Standart Library Types</i>

| Type | Description |
|------|--------------|
| `string` | Represents a sequence of characters (text). |
| `complex<double>` | Complex number type with double precision. |
| `complex<float>` | Complex number type with float precision. |
</div>

## 4.1 Declarations and Initialization.

<div align="justify">
A <strong>declaration</strong> is a statement that tells the compiler to create a variable of a specific type and name.
It reserves memory for that variable, but does not assign it an initial value. Also a  declaration introduces a name into a scope and specifies its type. It tells the compiler that something exists with that name and type.

<br>

A <strong>definition</strong> provides the actual implementation or allocates memory for a declared entity. Every definition is also a declaration,
but not every declaration is a definition. Definitions are often placed in another part of the program, such as: <i>Later in the same file, in another file (e.g., a .cpp file) ir in a library (written by someone else)</i> 

````cpp
double add(double, double);                       // Declaration
double add(double a, double b) { return a + b; }  // Definition
````

````cpp
struct point;                                      // Declaration
                                      
Struct point{                                       // Definition
    int age;
    int heifhht
} 
````

<i style="color:limegreen">Note: Every definition is a declaration that fully describes and creates the entity.</i>

<strong>Initialization</strong> is the process of assigning an initial value to a variable at the time it is declared.

````cpp
int x;        // Declaration
int x = 10;   // Initialization
````

<i style="color:#2E86C1;">Rules for Using Variables</i>

 - A variable must be used only after it has been initialized.
Using a variable before giving it a value can lead to undefined behavior or unexpected results.
 - Only operators defined for the variable’s declared type can be applied to it.For example, arithmetic operators (+, -, *, /) work with numeric types, but not with bool or string (unless overloaded).
 - Every operation applied to a variable should leave it with a valid value according to its type. Always initialize your variables and use only valid operations for their data type.
 - Changing a value from one data type to another can cause loss of information, especially when converting from a larger type to a smaller one.
    ````cpp
    int i = 2000;
    char m = i;   // m does NOT store 2000. Is the conversion of 2000 to a char format 

    ````
 - A variable declared without an initializer is said to be <strong>default-initialized</strong>.
This means that the variable is created, but its value is indeterminate (unpredictable or random).

- If we assign an out-of-range value to a variable of a signed type,
the result is undefined behavior. The program may produce unpredictable results or crash.

- <strong>In C++, you cannot define something twice,
but you can declare something multiple times (as long as the declarations are identical).</strong>. The most common case where we declare something more than once —
but define it only once — is with functions. <i style="color:#FF0000;">See the notes later for this </i>
</div>

 - <strong style="color:limegreen">In complex projects place all declarations in header files (.h / .hpp) and definitions in source files (.cpp).</strong>


//////////////////////////////////////////

For the string when i put string s1 = "Hello World!" in memory the string works like 12|"Hello World!  . The first one is the length 
What is the differeence between Runtime error and compile time error.
 
 I think that shis is more for operators

 Logical operator && and , || or , ! not
 RElation opratiosn < less than > more than

 For integer and  floating point types +,-,*,/

 top down --break up big computations into manylittle ones
bottom-up provide a higher level concept that hides details


/////////////////////////////////////////////////

# 5. Control Structures.
<div align="justify">
An <strong>expression</strong> is a combination of operators and operands that produces a value.

 - Operators specify what operation to perform.
 - Operands specify the data on which the operator acts.

<i style="color:#2E86C1;">For Booleans</i>

 - Type: <code>bool</code>
 - Values: <code>true,false</code>

    | Operator | Meaning       |
    |-----------|----------------|
    | `==`      | Equal          |
    | `!=`      | Not equal      |
    | `&&`      | Logical AND    |
    |  "||"      | Logical OR     |
    | `!`       | Logical NOT    |

<i style="color:#2E86C1;">For Integers</i><br>
Arithmetic operators: +, -, *, /, % 

<i style="color:#2E86C1;">For Doubles</i><br>
Arithmetic operators: +, -, *, /

</div>

## 5.1 Selection
A selection statement allows a program to choose which statements to execute based on one or more conditions.Remmeber that statements are executed sequentially and sometimes we must select between alternatives.<br>
C++ provides three main selection statements:

 - <code>if</code> statement.
 - <code>if...else</code> statement
 - <code>switch</code> statement

## 5.2 Iterators
Iteration is the process of repeating a block of code multiple times until a specified condition is met.
In C++, iteration is implemented using loops such as:

 - for. 
 - while
 - do...while.

## 5.3 Functions

A function is a block of code that performs a specific task and can be reused multiple times throughout a program.
Functions help make programs modular, readable, and easier to maintain.

We want to separate a computation because it is:

 - Logically separate — it represents a distinct operation.
 - Clearer — improves readability and understanding of the code.
 - Reusable — can be called multiple times without rewriting code.
 - Easier to test and debug — errors are isolated in smaller sections.

 /////////////////////////////////

C++ Strucutre :

 - Low-level language (inhertit from C)
 - Advanced languages features
 - standart library 
https://www.stroustrup.com/applications.html

/////////////////////////////////////////////

# 6. Header files.
<div align="justify">
A <strong>header file</strong> is a file that contains declarations of functions, classes, constants, and other components that can be shared across multiple .cpp (source) files. Header files usually have the extension <strong>.h or .hpp.</strong> The purpose of a header file is to propagate declarations to code files that need them.

As programs grow larger, you often divide your code into multiple files:

 - .cpp files → contain definitions (the actual implementation).
 - .h / .hpp files → contain declarations (interfaces and prototypes).

 A header file typically holds:

 - Function declarations (prototypes)
 - Class and struct definitions
 - Constant and macro definitions
 - Type definitions (typedef, using)
 - Template declarations

Example: This is  <i>MyFriendLibrary.h</i>  which declarates function bar
````cpp
#ifndef MY_LIBRARY
#define MY_LIBRARY

void bar();

#endif
````
The definition and implementation of <i>void bar</i> is in the <i>MyFriendLibrary.cpp</i> file.
````cpp
#include <iostream>
#include "MyLibrary.h"          // Declaration file

void bar(){
    ...
    std::cout<< "MyFriendLibrary bar"<< std::endl;
    return;
}
````
If the main file uses the function, we have to include the library .h
````cpp
// Main file main.cpp
#include<iostremam>
#include"MyFriednLibrary.h"  

int main {
    bar();
    retunr 0;
}
````

In other words, the preprocessor replaces the <code>#include</code> line with the entire content of that file. So when the compiler processes <code>main.cpp</code>, it’s as if all the code from the header file were written directly inside it.

## 6.1 Headers Files and Compilation Process.
<i style="color:#2E86C1;">For Small Libraries</i><br>
If a library is very small, you can define its functions directly inside your main file. However, for larger or reusable code, it’s better to place them in separate .h (header) and .cpp (source) files.

C++ compilation happens in several stages, involving headers, source files, and the linker.

1. Header inclusion
    - The #include directive literally copies the content of a header file into a source file before compilation.
    - Header files (.h / .hpp) contain declarations (function prototypes, class definitions, constants, etc.).

2. Source files
    - Source files (.cpp) contain the definitions (actual implementations of functions or classes).
    - Each .cpp file is compiled separately into an object file (.o or .obj).

3. Object files

    - The compiler transforms source code into machine code (object code) using the assembler.
    - Each .cpp file becomes its own compiled object file.

4. Linking
    - Linking is the process of putting together all the object code files
(from your .cpp files and libraries) to form the final executable.
    - The linker combines all object files (.o) and libraries into one executable program.
    - It “resolves” function calls and references between files.
    - Reports errors if something is missing (like undefined references).

````lua
   +-------------+       +-------------+
   |  math.h     |       |  utils.h    |
   +-------------+       +-------------+
         ↓                       ↓
   +-------------+       +-------------+
   |  math.cpp   |       |  utils.cpp  |
   +-------------+       +-------------+
         ↓                       ↓
      math.o                 utils.o
         ↓                       ↓
         └───► (linked together by the linker)
                      ↓
               main.exe 
````

| File Type     | Contains          | Used For                      | Example             |
| -------------- | ----------------- | ------------------------------ | ------------------- |
| `.h` / `.hpp` | **Declarations**  | Interface — tells what exists  | `#include "math.h"` |
| `.cpp`        | **Definitions**   | Implementation — how it works  | `math.cpp`          |
| `.o` / `.obj` | **Compiled code** | Intermediate machine code      | `math.o`            |
| (Executable)  | **Linked code**   | Final program                  | `main.exe`          |

<strong>Summarize</strong>

- Header files declare what exists.
- Source files define how it works.
- The compiler translates each source file to object code.
- The linker merges everything into one executable.

Example:
````cpp
#include <iostream>

#ifndef MY_FRIEND_LIBRARY_H
#define MY_FRIEND_LIBRARY_H
void bar();                   // 1 Declaration inside include guard
#endif                        // 2 MY_FRIEND_LIBRARY_H

void bar();                   // 3 Another declaration (outside guard)

int main() {
    bar();                    // 4 Function call (OK)
    bar();                    // 5 Function call again (OK)
    return 0;
}

void bar() {                  // 6 Definition
    std::cout << "Running main bar" << std::endl;
}

````
Step-by-step explanation

1. <strong>void bar();</strong> This is a function declaration.
It tells the compiler “there exists a function named bar that returns void and takes no parameters.”

2. <strong>#ifndef / #define / #endif</strong>
These are include guards — they prevent a header file from being included multiple times.
But here, you’re not actually using a header file (It's only for example)

3. <strong> bar()</strong>
We declared bar() again, this time outside the include guard.
This is redundant but not illegal — multiple identical declarations are allowed.

4. Call of the function.

5. Call of the function again.

6. <strong>Definition of bar()</strong>

This is the actual implementation of <i>bar()</i>
So far, the program works fine — it will print:
````
Running main bar
Running main bar
````

<i style="color:#FF0000;">Conceptual Error Here</i>

We wrote everything inside a single <code>.cpp</code> file. In the main file we have one version of bar() and another version from a library.

C++ does not allow two function definitions with the same name and same signature in the same program (unless you use namespaces).

In this example, the bar() function that runs is the one defined inside the main.cpp file, not the one that might exist in another library.

Even if myFriendLibrary.h declares a function bar() (and there’s a definition for it in myFriendLibrary.cpp),
the compiler and linker will use your definition from main.cpp, because <strong>when two functions have the same name and signature,
the one that’s defined in the same compilation unit (file) takes priority.
The linker doesn’t need to look for another one in external libraries — it already found one locally.</strong>

## 6.2 Header Guards.
A <strong>header guard</strong> is a preprocessor mechanism used to prevent a header file from being included more than once in the same program.

When you include the same header multiple times (directly or indirectly through other headers),
you could get multiple definition or redefinition errors because the compiler sees the same declarations more than once. The Header Guards solve this.

If our program uses multiple libraries, and each of those libraries includes the same header file (for example, <code><aux.h></code>),
then when we include all those libraries in your main file, the compiler would try to include <code><aux.h></code> multiple times. Without header guards, this leads to multiple inclusion errors,
because the compiler would see the same declarations and definitions again and again.
</div>


Header guards avoid inlcudidn multiple times header files in the corresponding declaration. STUDY MIRE THIS CONCEOT OF HEADR GUARDS

# 2.Terminology
<div align="justify">

- <strong>Scope: </strong> Defines the region of a program where a name (such as a variable, function, or object) is visible and accessible.

    |Type|Description|
    | ---------| -----------|
    | **Local scope**     | A variable declared inside a function, block `{}`, or loop. It exists only inside that block.                |
    | **Global scope**    | A variable declared **outside** of all functions or classes. It is visible everywhere after its declaration. |
    | **Function scope**  | Each function name has its own scope.|
    | **Class scope**     | Members (variables or methods) declared inside a class belong to that class’s scope. |
    | **Namespace scope** | Names declared inside a namespace are visible only within that namespace unless qualified. |


- <strong>Statment: </strong>A statement is the smallest independent executable unit in a C++ program.It represents a <i>complete unit of work</i>.<br>
Statements can perform different actions, such as:
    - <strong>Declaration Statement: </strong> Introduces a new variable or object into the program.
    ```cpp
    int x = 10;
    double pi = 3.14;
    ```
    - <strong>Expression Statement: </strong> Performs an operation or computation.
    ```cpp
    x = x + 1;
    std::cout << x;
    ```
    - <strong>Control Statment: </strong> Changes the flow of execution.
    ```cpp
    if (x > 0) { ... }
    for (int i = 0; i < 10; i++) { ... }
    while (condition) { ... }
    ```
</div>