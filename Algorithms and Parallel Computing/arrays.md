<div align="center">
<h1> Arrays and Structs
</div>
<div align="center">
    <em>Algorithms and Parallel Computing</em>
    <em>Juan Pablo Vallejo Montañez</em><br>
    <em>Notes from Politecnico di Milano 2025/2026 Y.</em><br>
</div>

# 1. Array 
<div align="justify">
An array is a collection of elements of the <strong>same data type (homogeneous) </strong> that can be accessed by their position (index).

- Have fixed size and the dimesion must be known at compile time ( The dimension must be a constant expression ).
- We cannot add or remove elements to an array (fixed size). The array is <strong>static</strong>.
- We can modify existing elements of the array.

The declaration syntax is 

````cpp
base_type array_name[array_size]    // General

int numbers[5]                      // Example
````

</div>

## 1.1 Memory of Arrays

The name of an array represents a memory address. It acts as a pointer to the first element of the array. The memory space is allocated contiguously in the physical address 
space. The total memory space occupied by an array is calculated as:
````cpp
Total memory = (size of one element) × (number of elements)
````

### 1.1 Constant Expression

`const` declares a <strong>constant variable</strong>, meaning its value cannot change after initialization.

A constant expression `constexpr` is an expression whose value is known and fixed at compile time.

 - A literal is a constant expression
 - A const variable that is initialized from a constant expression is also a constant expression
 - Functions (with some restrictions) can be used to define constexpr
````cpp
const int x = 10;           // constant variable
constexpr int y = x + 5;    // constant expression
````

## 1.2 Array Initialization

<div align="justify">

Arrays can be initialized in two main ways:

 - Specify the size explicitly: 

    - If dim > intiliazers, there will be elements that are  <strong>value-initialized</strong>.
    - if dim < intiliazers , <strong>there is an error.</strong>

 ````cpp
 const unsigned sz = 3
 int a1[sz] = {0,1,2}
 ````

 <i>Note: If we specify the dimesion, the number of initializers must not exced the specified size.</i>
 
 - From the elements (List initialization): 

 ````cpp
 int a2[] = {0,1,2}  
 ````

In this case, the compiler deduces the size from the number of elements. 

</div>

## 1.3 Copying Arrays

The copy between arrays in not allowed. The array name is an address, not a separate data structure.
Copying would mean copying the address, not the elements.

````cpp
 int a[] = {0,1,2}
 int a2[] = a         // Error a is an address
 a2 = a               // Error
 ````
To copy arrays, you must do it element by element:
````cpp
for (int i = 0; i < 3; i++) {
    a2[i] = a[i];
}
````

## 1.4 Multidimensional Arrays.

You can define arrays with more than one dimension:
````cpp
 int matrix [size_2][size_1]
 ````
This is  new variable <strong>(matrix)</strong> that is an array of <i>size_2</i> elements, and each element is an array <i>of size_1</i> integers. In this way: 

 - <code>size_1</code> is the number of columns. 
 - <code>size_2</code> is the number of rows.

It can be interpreted as a <code>size_2</code> rows of arrays,
each row containing <code>size_1</code> elements.

Elements of the matrix are stored in row-major order,
meaning the elements of the first row are stored contiguously,
followed by those of the second row, and so on.

````cpp
matrix[0][0]  matrix[0][1]  matrix[0][2]  ...  matrix[1][0]  matrix[1][1]  ...
````

Elements are accessed using two indices:
````cpp
matrix[i][j];
````
Where:

 - i = row index
 - j = column index

# 2. Structures

A struct in C++ is a user-defined data type that allows you to group together variables of different types under a single name.It is particularly useful for representing real-world entities that have multiple attributes.

Structs are similar to classes in C++, but with one key difference: <i>By default, members of a struct are <strong>public</strong>.</i> One of it's purpose is group data.

| Feature |Description|
| ------- | -------- |
| **User-defined type**     | Created by the programmer to represent complex data.     |
| **Heterogeneous members** | Can store variables of different data types.                 |
| **Public by default**     | All members are accessible unless specified otherwise. |
| **Supports methods**      | Functions (methods) can be defined inside the struct.  |


Exmaple
````cpp
using namespace std;

// Define a struct
struct Student {
    string name;
    int age;
    float grade;

    // Method inside struct
    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << ", Grade: " << grade << endl;
    }
};

int main() {
    // Create a struct variable
    Student student1;

    // Assign values to members
    student1.name = "Alice";
    student1.age = 20;
    student1.grade = 8.5;

    // Access and display struct members
    student1.displayInfo();

    return 0;
}
````

<i>Note: Individual fields can be accessed through the dot notation: <strong>var_name.field_name</strong> ( Student.age ) </i>




At this stage, comparison between structs is done field by field. You must compare each member manually unless you define a custom comparison operator.

<i>Note: Use capitalized names for struct types (Student, Book, Company ) and sse lowercase or descriptive names for struct variables.</i> 
