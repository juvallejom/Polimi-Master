Arrays

Arrays are collection of data od the same datatype (are homogeneous) that we access  by position

- Have fixed size, the dimesion must be known at compile time.
- We cannot add elements to an array (fixed size). We can modify the elements of the array.

base_type array_name[array_size]

Memory of arrays

An array name is  a memory address ( a pointer)
The total memory sapce is given by the space required to store each individaul element times the size of the array

const and constexpr ???

const = What is a const, a costant variable ???
a cnstab exrpression is an expression whose value cannot change and that can be evaluated at compile time
 - a literal is a caontsan expression
 - a const variable that is intialized from a constant expression is also  a consrant expression    

 two ways toinitaliza an array 

 with the size or with the elements

 const unsigned sz = 3

 int ia1[sz] = {0,1,2}

 int a2[] = {0,1,2}  // List initialization - in this case we can omit the dimesion. the compile infers it from the number of initializers


 If we  specify the dimesion, the number of initializers must not exced the specified size.

 If dim > intiliazers, there will be elements that are  value-initialized

 if dim<intilizaers , there is an error 


 The copy between arrays in not allowed

 int a[] = {0,1,2}
 int a2[] = a 
 a2 = a

 This is an error 

 The reason of that the name of the array is an adress, what we're tryning is to copy the adress and in  vector it does not make sense


 Copy needs to be perfomed element by element (Whit a for loop)

 Multidemsional arrays

 int matrix [size_2][size_1]
 DEfine  a new variable as  an array of size_2 elements and each of them is an array of size_1 elements

 size_1 -- columns 
 size_2 -- rows

 i can interpretate this as a size_2 number of arrays with size_1 elemenrs.

 In memory, elements of the matrix are stored by rows in contoguis locations.

 Acces to the matrix elements is by matrix[i][j]

 __________________
 Strucutres

 A struct in C++ is a user-defined data type that allows you to group together variables of different types under a single name. It is particularly useful for representing real-world entities or objects that have multiple attributes. Structs are similar to classes in C++, but by default, their members are public.


 Exmaple

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


comparison, at this stage, is implemented by performing comparison field bu field 

Good pratice --- use a capital letter when initialize a structu
struct Boook
struct Student 
