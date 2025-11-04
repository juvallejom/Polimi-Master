<div align="center">
<h1> Pointersm, References and Function Parameters
</div>
<div align="center">
    <em>Algorithms and Parallel Computing</em><br>
    <em>Juan Pablo Vallejo Montañez</em><br>
    <em>Notes from Politecnico di Milano 2025/2026 Y.</em><br>
</div>

# 1. Pointers

## 1.1 Definition.

A <strong>pointer</strong> is a variable whose value is the address of another variable (or object) in memory. Instead of holding a direct value (like <code>int x = 5;</code>), a pointer holds the location in memory where that value is stored.

<i style="color:#2E86C1;">Intuitive Idea</i>

Every variable or object in a C++ program is stored in a specific location in memory.
That location has a unique memory address.

- The variable name refers to the contents stored at that address.
- The address-of operator (&) allows us to obtain the memory address of a variable or object.

A pointer is a special variable that can store such an address.
In this way, the pointer “points” to the memory location of another variable — it doesn’t hold a value directly, but rather the location of that value.

<i>This is a lower level feature bring form C </i>

Every variable, object or piece of ingomraiton on our code is stored in memory for any progaming language.

Each memeory location has a physical address and:
 - the name of the variable indicates the contents of the memory location
 - the operator & allows to obtain the momery address of the location associadted with the variable to wich the operator is applied

 See image from slides 2 (pointers) page 3  

 Pointers  --- think like an integer (can i do opoertations with pointers??)
  -Variable which store memory address
  - To declare a pointer you must  also specify what type of object tje pointer points to 


   syntax = double *p   // it means p is a pointer.
   if p is a pointer to an integer, then *p is a simple integer value.

   *p = 5
   p is the direction of this element

   then p = 5 is an error beacuse p is a memory address

The dereference operator (*) is used in C++ to access the value stored at the memory address a pointer is pointing to. It allows you to retrieve or modify the value of the variable indirectly through its pointer.


  A pointer variable usually requires 2 bytes or 4 bytes  depending  on the architecture


We can store in a pinter variable the address of another variable .Ssee slide 2 page 6 for image.   

p will point  to the memory  area where the value  of x is  stored

A point types  determines how the memory reffered to by  the pointer's value is used


See exmplae page 7 
What is the difference between & and *

Be careful where the pinter is pointing :v


FUNCTION PARAMETERS

return_type name (formal arguments); // a declaration
return_type name (formal arguments){...}; // a definition

formal arguments ---> parameters

void ---> does not return a value


 In a function definition we use formal parameters representing a symbolic 
reference (identifiers) to objects used within the function
 • radius is a formal parameter
 • They are used by the function as if they were local variables
 • The initial value of formal parameters is defined when the function is called 
using the actual parameters specified by the caller
 • r in our running example

 formal parameter fun(souble radius)
 actual parameter fun(5.0)

 There are a lot of techniques.
 The two most common are 
 pass by value and pass by reference

 - Pass by value 

 the acutal parameter is copied into the memory location of the correspoding formal parameter. In other owords the actual and formal parameter refer to differnet memeoty locations

 See computer memory Pages 18
 in the exmaple of page 14 de variable res is in the stack memory

 The variables inside the function (local variabeles of the funciton) is only put in memeory when the function is invoqued and is sotred in the stack. When the function termines the stack is deallocated.

 Fress Store --> Indepentede piece of memory where we can allocate memory when we nedeed

 See and exmplae of pass by value in pge 19


 - Pass by reference 
 actual and fromal parameter share the same memory.

 The running function works in its environment on the formal parameters (and 
consequently also on the actual parameters) and each change on the formal 
parameter is reflected on the corresponding actual parameter
 • The function execution affects the caller with modifications to the caller's 
environment
 • In this way we can return multiple results!

To use pass by reference we have to use memory address ( pointers)

We need a pointer for each forlam parameter
the deference opoerator in the function body to access the actual parameter

In the functin  call, the addrress of the actual parameter is used

Arrays always passed by reference. The name of an array varaible is an address i.e its a pinter

This is very efficient

Pass by refernce example     in page 28


other examples in page 34

&a is the address ????

call of functions

    function y = f(x)
    void function f(x)

Example of procedure in45 

Summary at 48


REFERENCES

     An automatically dereferenced pointer:
 • Or as “an alternative name for an object”
 • A reference is introduced though the & modifier in a variable declaration
 • A reference must be initialized
 • The value of a reference cannot be changed after initialization
 • i.e., you cannot make a reference refer to another object after initialization
 int x = 9;
 int y = 8;
 int &r = x;    

  Pointers and references
 • A pointer is a compound type that “points to” another type
 • Like references, pointers are used for indirect access to other objects
 • Unlike a reference, a pointer is an object in its own right
 53
 • Pointers can be assigned and copied; a single pointer can point to several different 
objects over its lifetime
 • Unlike a reference, a pointer does not need to be initialized at the time it is defined
 • Like other built-in types, pointers have undefined value if they are not 
initialized.  Be very careful !!


REferences PAge 54 is very importsnt

See 54 and 62 to undesrtand all of this 



CONST QUALIFIER

const -- variable unchangeab
Because we cant change   the value of a const object after creation, it must be initialized

References to const :
 - a reference to const cannot be used to change the object to which the reference is bound Page 66 example of error


 I dont undesrtanth the example of the age 67-68-69

 Guide for passing values  page  73

 STUDY ALL OF THIS
 
 Variable Scope 

The scope of an identifier is the portion of the program in which the identifier can be referenced (some can be referenced throughout the program and others can be referenced from only portions of a program)

Global variable Global variable
 • declared very early stage
 • available always and from anywhere
 76
 • created at the start of the program, and lasts until the end, stored in the static data
 • difficult to debug

 NEVER USE GLOBAL VARIABLES -5 points at exam
 Use global variables bad programming practice

 Local on-the-fly variables.
  - simply created when they are nedeed
  - only available from whitin the routine/block in which they were created,stored in the stack
  - easy to debug

  If i hace a glocal variable called x and a local variable also called x in my function all the operation that are defined in function of "x" inside my function will take the local variable


POINTERS TO OBJECTS  IN THE FREE STORE AND MEMORY LEAKS

Raw Pointers ---> very low-level mechanismo to allows us to have a refernce of some piece of memory.
 - Those that you already know C-like pointers ??????
 - They can point to memory allocated dynamically in the free store
 - Memory Leak??
 - maloc() and free()

The hardware provides memory and address


 Smart Pointers
 - Manage by the compiler
 - Allocated objects are associadted with the counter
 - See slides 3



Slide 4


The free store --"the heap"

You request memory to be allocated on the free store thorugh the new operator.

the new opoerator returns a pointer to the allocated memeory
A prointer is an address of the first byte of the memory

See page 5 


Pointers states page 6


Null pointers oage 7 until page 12


the pointers does not know the number of elements that its pointing to.

I have a doutb, in the slide 17 they say that p1 = p2. I know that the arrayws works as pointers but what is the limit of that simplification concept

If i change pointsres maybe an element will be without pointer

A pointer does know the type of the objetc that its pointing to

I cant not assing an int* to a oduble*

Free Store

 With old C, when you do not know a priori your data structure size and you do not 
want to over-allocate memory
 • For this purpose in C++ use STL containers
 • With pointers and arrays we are "touching" hardware directly with only the most 
minimal help from the language
 • Here is where serious programming errors can most easily be made, resulting in malfunctioning 
programs and obscure bugs
 • Be careful and operate at this level only when you really need to
 • If you get "segmentation fault", "bus error", or "core dumped", suspect an uninitialized or 
otherwise invalid pointer
 • vector (and other STL containers) is one way of getting almost all of the flexibility 
and performance of arrays with greater support from the language (read: fewer 
bugs and less debug time



 double* make(int n)            // allocate n doubles
 { 
double* p = new double[n];
 return p;
 }

 In the stack, we have an activing and record of make with two vairbales, n and p

 but in the free store, we allocate the necessarrly n elements.
 When the make function finish, the stack dissapear but the allocated memory in the free store remains. Outside the make function, we can still use that piece of memory, andit reamins until we deallocated or removed from free store wirh the delete function


 Why use raw pointers? 
  -  When you want to share large data structures and avoid multiple copies (this 
is the use of raw pointers we will make in the course even without new and 
delete)
 • Copies waste memory
 • Copies need to be kept in sync and this introduces additional overhead (and we may also 
forget!!!)

MEMORY LEAK

when we allocate dmemory on the free store but we forget to remove it.

- Memory which is no longer needed is not released
- An object is stored in memeory but  cannot be accessed by the running code



 double* calc(int result_size, int max)
 {
 double *result = new double[result_size]; 
double *p = new double[max];     
// allocate another max doubles
 26
 // i.e., get max doubles from the free store
 // … use p to calculate values to be put in result …
 return result;
 }
 double *r = calc(200,100); // oops! We "forgot" to giv


 Here, pointers p and result are in the stack of the function. The elements that points p and result are in the free store. When the function finish , the stack dissapear (result and p are removed as pointers) and the elements of "reuslt" in the free store will be pointing by r but the elements on the free store of "p" will not have pointer

 we have to use delete [] p inside the function to deallocate or free that aaray from our memeory

 Its the same with r. At the final part of the code we have to deallocated r



  A program that needs to run “forever” can’t afford any memory leaks
 • An operating system is an example of a program that “runs forever”
 • All memory is returned to the system at the end of the program
 • If you run using an operating system (Windows, Unix, whatever)
 28
 • Program that runs to completion with predictable memory usage may leak 
without causing problems
 • i.e., memory leaks aren’t “good/bad” but they can be a major problem in specific 
circumstances


 Memory leaks
 • How do we systematically and simply avoid memory leaks?
 • don't mess directly with new and delete
 • Use vector, etc.
 • or use a garbage collector
 32
 • A garbage collector is a program that keeps track of all the memory you allocated 
dynamically 
• In C++ we have Smart Pointers!
 • Allocate and return unused free-store-allocated memory to the free store 
• Unfortunately, even a garbage collector and Smart Pointers do not prevent all leak


 Free store summary
 • Allocate using new
 33
 • new allocates an object on the free store, sometimes initializes it, and returns a pointer to it
 • int *pi    = new int;           
• char *pc   = new char('a');     
• double *pd = new double[10];    
// default initialization (none for int)
 // explicit initialization
 // allocation of (uninitialized) array
 • Deallocate using delete and delete[ ]
 • delete and delete[ ] return the memory of an object allocated by new to the free store so that the 
free store can use it for new allocations
 • delete pi;       
• delete pc;       
• delete[ ] pd;    
// deallocate an individual object
 // deallocate an individual object
 // deallocate an array
 • Delete of the null pointer does nothing
 • char *p = nullptr;
 // harmless
 • delete p;      


Pointer is like a variable that stores an address
 A reference is not a object. Hence, we cannot have pointer to a reference.
 ¿Unsigned?
 A reference is not a value, is not an object. The reference is a binding that you create when you declare the reference. WE cannot take a pointer to a refrence beacuse a reference is not an objects, the pointer is only for piece of memory


 Reference to consntant.

 A reference to const may refer to an object that is not 
const 
• A reference to const restricts only what we can do through that reference
 • Binding a reference to const to an object says nothing about whether the 
underlying object itself is const
 • Because the underlying object might be non const, it might be changed by 
other means
 int i = 42; 
int &r1=i;          
// r1 bound to i
 const int &r2 = i;  // r2 also bound to i, but cannot be used to 
// change i 
r1 = 0;            
r2 = 0;             
// r1 is not const; i is now 0 
// error: r2 is a reference to const


Refernce can not be stored in vector

std::vector<int> hello;    // OK
 std::vector<int &> hello;  // Error! Pointer to reference is illegal!
 • Container values must be assignable
 • References are non-assignable (you can only initialize them once when they 
are declared, and you cannot make them refer to something else later)
 • Other non-assignable types are also not allowed as components of containers
 • e.g., vector<const int> is not allowed


We can poit a pointer. See slide 4 page 7 to wathc this 

The auto specifier.

auto allows to c++ to asign the data type of a varibale. We dont have to specfify the data type i fwe put a variable with the auto specifer.

A variable that uses auto as it type specifer must have an intializer

 // the type of item is deduced from the type of the result of 
// adding val1 and val2 
10
 auto item = val1 + val2; // item is initialized to the result of 
// val1 + val2 

Traversing vector 

Traversing a vector
 vector<int> v{1,2,3,4,5,6,7,8,9};
 11
 for (auto &i: v) // for each element in v (note: i is a reference) 
i *= i;      // the same as i = i*i, i.e, square the element value 
for (auto i : v)           // for each element in v 
cout << i << " ";    // print the element 
cout << endl; 


auto specifier is useful to for travesing vectoes

We can use auto to access a multidimesional arrays.

constexpr size_t rowCnt = 3, colCnt = 4;
 int ia[rowCnt][colCnt];  // array of size 3; 
// each element is an array of ints of size 4
 size_t cnt = 0;
 for (auto &row : ia)        
// for every element in the outer array 
for (auto &col : row){  // for every element in the inner array 
col = cnt;          // give this element the next value 
++cnt;              // increment cnt 
}


Iterators
What is an iterator

What is the sucrpt opertor ??? (Is this [i])????

begin() returns the first element
end () retunrs is an interator posutiones ONE PAST THE END of the associaded contianer

Using Iterators 
// the compiler determines the type of b and e
 // b denotes the first element and e denotes one past the
 // last element in v 
19
 auto b = v.begin(), e = v.end();     // b and e have the same type 
• If the container is empty, the iterators returned by begin and end are equal, 
they are both off-the-end iterators


   Using Iterators 
string s("some string");
 if (s.begin() != s.end()) {   // make sure s is not empty 
auto it = s.begin();      // it denotes the first character in s 
*it = toupper(*it);       // make that character uppercase 
} 
20
 Means "go to the next element"
 // process characters in s until we run out of characters or we hit a whitespace
 for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
 *it = toupper(*it);      // capitalize the current character 
Equivalent to
 Important: use != instead of <
 If we change the type it might not work 
string::iterator it = 

See Slide 20



Standard container iterator operatiosn

Standard container iterator operations
 Matteo Rossi - Pointers 21
 *iter Returns a reference to the element denoted by the iterator iter
 iter->memb Dereferences iter and fetches the member memb from the underlying 
element (*iter).memb
 ++iter Increments iter to refer to the next element in the container--iter Decrements iter to refer to the previous element in the container
 iter1 == iter2 Compares two iterators.  Two iterators are equal if they denote the same 
element or if they are the off-the-end iterator for the same container

Operations supported by vector and string iterators
 (Only by vector and strings! Be careful!!)
 Matteo Rossi - Pointers 22
 iter + n Adding (subtracting) an integral value n from the iterator iter yields an 
iterator n elements forward (backward) w.r.t. iter within the container iter - n
 iter += n Assign to iter the value of adding (subtracting) n to iter
 iter -= n
 iter1 - iter2 Compute the number of elements between iter1 and iter2
 >,>=,<,<= One iterator is less than another if it denotes an element that appears in 
the container before the one referred to



iterator Types


 Iterator types 
23
 • The library types that have iterators define types named iterator and 
const_iterator that represent actual iterator types
 vector<int>::iterator it1;  // it1 can read and write int elements 
// in a vector<int>
 string::iterator it2;       // it2 can read and write characters in a 
// string 
vector<int>::const_iterator it3;  // it3 can read but not write
 // int elements 
string::const_iterator it4;   // it4 can read but not write characters 


The cbegin and cend operations 
vector<int> v;
 const vector<int> cv;
 24
 auto it1 = v.begin();  // it1 has type vector<int>::iterator 
auto it2 = cv.begin(); // it2 has type vector<int>::const_iterator
 • It is usually best to use a const type (such as const_iterator) when we need 
to read but do not need to write to an object
 • To let us ask specifically for the const_iterator type, since C++11, two new 
functions named cbegin() and cend() are available
 auto it3 = v.cbegin();   // it3 has type vector<int>::const_iterator


Example Binary Search page 25. Its good idea to watch this again. The class is in the 8 of October.


Artihmetic opoeratoes in iterators binary search

sort(initial postion, final position) - sort the container. ITS IS IMPORATN TO KNOW 
s is the sting that i want to find 

Arithmetic operations on iterators – Binary search 
vector <string> text                           // intitialize text
 sort(text.begin(), text.end());                // text must be sorted 
auto beg = text.cbegin(), end = text.cend();   // beg and end denote the range we're searching
 auto mid = text.cbegin() + (end - beg)/2;      // original midpoint
 s = …
 while ( mid != end && *mid != s ) {    // while there are still elements to look at
                                       // and we haven't yet found s
    if (s < *mid)                      // is the element we want in the first half?
        end = mid;                     // if so, adjust the range to ignore the second half
 else // the element we want is in the second half
 beg = mid + 1;                 // start looking for the element just aftermid
 mid = beg + (end -beg)/2;         // new midpoint
 }
 if ( mid != text.cend() && s== *mid )
 cout<< "Yes I found " <<s<< " intext" <<endl;
 else
 cout<< "Sorry I cannot find " <<s<< " intext" <<endl;

 Wach slide 26 
 What is this Complexity

Wjats the slides beacuse there a lot of things that the techaer did not say in the class

 Why bother with the public/private distinction?
 • Why not make everything public?
 • To provide a clean interface
 • Data and messy functions can be made private
 9
 • To allow data representation (and implementation in general) to change freely
 • You need only to change a fixed set of functions
 • You don't really know who is using a public member
 If internal representation is hidden (information hiding principle):
 • It is easier to support code evolution
 • We can change the internals without changing the remaining code


 Public/private benefits
 • Why bother with the public/private distinction?
 • Why not make everything public?
 • To provide a clean interface
 • Data and messy functions can be made private
 10
 • To allow data representation (and implementation in general) to change freely
 • You need only to change a fixed set of functions
 • You don't really know who is using a public member
 • To ease debugging
 • (known as the “round up the usual suspects” technique)
 • To maintain an invariant

Invariants
 12
 • If we can’t think of a good invariant, we are probably dealing with plain 
data
 • if so, use a struct
 • Try hard to think of good invariants and use classes, rather than structs
 • that saves you from poor buggy code

Wathc the structure for 13 


View Examples of Dates  page 34 / Class 14 

this 

this
 27
 • Member functions access the object on which they were called through an extra, 
implicit parameter named this
 • When we call a member function, this is initialized with the address of the 
object on which the function was invoked. For example, when we call 
my_birthday.month();
 the compiler passes the address of my_birthday to the implicit this parameter. It 
is as if the compiler rewrites this call as 
// illustration of how a call to a member function is translated 
int Date::month(Date * this) 
Date::month(&my_birthday) 
which calls the month member of Date passing the address of  my_birthday 

 this
 28
 • Inside a member function, we can refer directly to the members of the object on which the 
function was called
 • Any direct use of a member of the class is assumed to be an implicit reference through this. 
• That is, when month() uses m, it is implicitly using the member to which this points.
 • It is as if we had written this->m

  this
 • The this parameter is defined for us implicitly: 
• It is illegal for us to define a parameter or variable named this
 • Inside the body of a member function, we can use this
 • It would be legal, although unnecessary, to define month() as 
int month() { return this->m; } 
because this is intended to always refer to “this” object
 • this is a const pointer, we cannot change the address that this holds


  Const member functions
 // Distinguish between functions that can modify (mutate) objects
 // and those that cannot ("const member functions")
 class Date {
 public:
 // …
 int day() const;       
// …
 void add_day(int n);    
// …
 };
 // get (a copy of) the day 
// move the date n days forward
 const Date dx {2008, 11, 4};
 int d = dx.day();     
// fine
 // error: can't modify constant (immutable) date
 32
 dx.add_day(4);        
Matteo Rossi - Classes
 Const member functions
 Date d (2004, 1, 7);              
const Date d2 (2004, 2, 28);      
d2 = d;                           
d2.add(1);                        
d = d2;                           
d.add(1);                         
// a variable
 // a constant
 // error: d2 is const
 // error: d2 is const
 // fine
 // fine
 33
Matteo Rossi - Classes
 Classes: What makes a good interface?
 • Minimal
 • As small as possible
 • Complete
 • And no smaller
 • Invariant-preserving
 34
 • Invariants hold from object creation (i.e., constructors!) and for every operation performed 
(non-const methods!)
 • const correct
Matteo Rossi - Classes
 Interfaces and “helper functions”
 • Keep a class interface (the set of public functions) minimal
 • Simplifies understanding
 • Simplifies debugging
 • Simplifies maintenance
 35
 • When we keep the class interface simple and minimal, we need extra “helper functions” 
outside the class (non-member functions)
 • next_weekday(), next_Sunday()
 • == (equality) , != (inequality)
Matteo Rossi - Classes
 Helper functions
 Date next_Sunday(const Date& d)
 {
 // access d using d.day(), d.month(), and d.year()
 // make new Date to return
 }
 Date next_weekday(const Date& d) { /* … */ }
 bool operator==(const Date& a, const Date& b)
 {
 36
 return a.year()==b.year()  &&  a.month()==b.month()  &&  a.day()==b.day();
 }
 bool operator!=(const Date& a, const Date& b) { return !(a==b); }
Matteo Rossi - Classes
 Helper functions
 Date next_Sunday(const Date& d)
 {
 // access d using d.day(), d.month(), and d.year()
 // make new Date to return
 }
 Date next_weekday(const Date& d) { /* … */ }
 • Declare helper functions in the Class header
 • Define helper functions in the Class source (.cpp) file 
37
 bool operator==(const Date& a, const Date& b)
 {
 return a.year()==b.year()  &&  a.month()==b.month()  &&  a.day()==b.day();
 }
 bool operator!=(const Date& a, const Date& b) { return !(a==b); }


Operator overloading
 • You can define only existing operators
 • E.g., + - = += * / % [] () ^ ! & < <= > >=
 • You can define operators only with their conventional number of operands
 • E.g., no unary <= (less than or equal) and no binary ! (not)
 • int operator+(int,int);     
• An overloaded operator must have at least one user-defined type as operand
 // error: you can't overload built-in +
 • Vector operator+(const Vector&, const Vector &);     
// ok
 39
Matteo Rossi - Classes
 Suggestions
 • Overload operators only with their conventional meaning
 • + should be addition, * be multiplication, [] be access, () be call, etc.
 • Don’t overload unless you really have to
 • Don’t overload , * && || !
 • Operand-evaluation are not preserved
 • Short circuit does not work anymore
 40
Matteo Rossi - Classes
 Class example: MatlabVector 
• We want to implement Matlab-like vectors in C++
 • Implement row vectors of type double
 • Element indexing follows the C++ convention, i.e., the first element has index 0!
 • Vectors can grow as in Matlab 
• Simplified version: reading an element that does not exist does not return an error
 v[0] 
v:
 0.33
 v[6] = 4.1 
v[0] 
v:
 0.33
 v[1] 
22.0
 v[2] 
27.2
 v[3] 
54.2
 v[1] 
22.0
 v[2] 
27.2
 v[3] 
v[4] v[5] v[6] 
0.0
 0.0
 4.1
 41
 54.2
Matteo Rossi - Classes
 Class example: MatlabVector 
• Goals:
 • Provide operator+
 • Implement the product with a scalar: operator*
 • Provide operator[] to access individual elements 
• Neglect, in the beginning, errors (e.g., vectors' sizes do not match)
 43
Matteo Rossi - Classes
 MatlabVector
 class MatlabVector {
 vector<double> elem;
 public:
 double get(size_t n);           // access: read
 void set(size_t n, double v);   // access: write
 size_t size() const;            // return number of elements
 MatlabVector operator*(double scalar) const;
 };
 MatlabVector operator+(MatlabVector& v1, MatlabVector& v2);
 44
Matteo Rossi - Classes
 MatlabVector
 size_t MatlabVector::size() const {
 return elem.size();
 }
 double MatlabVector::get(size_t n){
 while (elem.size() < n+1)
 elem.push_back(0.);
 return elem[n];
 }
 46
Matteo Rossi - Classes
 MatlabVector
 void MatlabVector::set(size_t n, double v){
 while (elem.size() < n+1)
 elem.push_back(0.);
 elem[n] = v;
 }
 MatlabVector MatlabVector::operator*(double scalar) const{
 MatlabVector result;
 for (size_t i=0; i < elem.size(); ++i)
 result.set(i, scalar*elem[i]);
 return result;
 47
 }
Matteo Rossi - Classes
 MatlabVector
 MatlabVector operator+(MatlabVector& v1, MatlabVector& v2)
 {
 MatlabVector result;
 for (size_t i=0; i < v1.size(); ++i)
 result.set(i, v1.get(i) + v2.get(i));
 return result;
 }
 48
Matteo Rossi - Classes
 MatlabVector (primitive access)
 MatlabVector v;
 for (size_t i=0; i < 10; ++i) {    // quite ugly:
 v.set(i,i);   
cout << v.get(i);
 }
 for (size_t i=0; i < 10; ++i) {   // we're used to this:
 v[i]=i;  
cout << v[i];
 }
 49
Matteo Rossi - Classes
 50
 MatlabVector (we use references for access)
 class MatlabVector {
 vector<double> elem;
 public:
 double & operator[](size_t n);      // access: return reference
 size_t size() const;                 // return number of elements
 MatlabVector operator*(double scalar) const;
 };
 MatlabVector operator+(MatlabVector& v1, MatlabVector& v2);
 MatlabVector v;
 for (size_t i=0; i < 10; ++i) {       
v[i] = i;                         
cout << v[i];
 // works and looks right!
 // v[i] returns a reference to the element of index i
 }
Matteo Rossi - Classes
 MatlabVector
 double & MatlabVector::operator[](size_t int n) {
 while (elem.size() < n+1)
 elem.push_back(0.);
 return elem[n];
 }
 51
Matteo Rossi - Classes
 Operator member functions
 • First operand (left hand) is bound to this
 • They have one less explicit operator
 class MatlabVector {
 vector<double> elem;
 public:
 double & operator[](size_t n);    
size_t size() const;              
// access: return reference
 // return number of elements
 MatlabVector operator*(double scalar) const;
 MatlabVector operator+(const MatlabVector& rhs) const;
 };
 52
Matteo Rossi - Classes
 Operator member functions
 • First operand (left hand) is bound to this
 • They have one less explicit operator
 MatlabVector operator+(const MatlabVector& rhs) const
 {
 MatlabVector result;
 for (size_t i=0; i < elem.size(); ++i)
 result[i] = elem[i] + rhs.elem[i];
 return result;
 }
 53
 Notice the access to the private element of rhs
Matteo Rossi - Classes
 Class example: Sales_data
 class Sales_data {
 private:
 54
 Sales_data
 string bookNo; 
unsigned units_sold; 
double revenue; 
public:
 Sales_data() :
 bookNo(""),
 units_sold(0), 
revenue(0.0)
 {}- bookNo- units_sold- revenue
 + Sales_data()
 + get_bookNo() const
 + get_unit_sold() const
 + get_revenue() const
 + void set_bookNo (const string &)
 + set_unit_sold(unsigned)
 + set_revenue(double)
 + operator+ (const Sales_data &) 
Matteo Rossi - Classes
 Class example: Sales_data
 55
 Sales_data
 /* Getters and Setters */
 string get_bookNo() const;
 unsigned get_unit_sold() const;
 double get_revenue() const;
 void set_bookNo(const string & bn);
 void set_unit_sold(unsigned u);
 void set_revenue(double r);
 }; - bookNo- units_sold- revenue
 + Sales_data()
 + get_bookNo() const
 + get_unit_sold() const
 + get_revenue() const
 + void set_bookNo (const string &)
 + set_unit_sold(unsigned)
 + set_revenue(double)
 + operator+ (const Sales_data &) 
Matteo Rossi - Classes
 Operator member functions
 • First operand (left hand) is bound to this
 56
 Sales_data
 • They have one less explicit operator
 class Sales_data {
 // Other code
 public:
 Sales_data operator+(const Sales_data &rhs) const;
 }
 Sales_data Sales_data::operator+(const & Sales_data rhs) const {
 Sales_data ret;
 ret.bookNo = bookNo;
 ret.units_sold = units_sold + rhs.units_sold;
 ret.revenue = revenue + rhs.revenue; 
return ret;
 }- bookNo- units_sold- revenue
 + Sales_data()
 + get_bookNo() const
 + get_unit_sold() const
 + get_revenue() const
 + void set_bookNo (const string &)
 + set_unit_sold(unsigned)
 + set_revenue(double)
 + operator+ (const Sales_data &) 
access to the private elements of rhs
Matteo Rossi - Classes
 Operator non-member functions
 • Same number of parameters as the operator
 57
 Sales_data
 Sales_data
 • They need to access to all data members of type
 • Typically declared as friend, we will see how in the next lecture
 Sales_data operator+( const Sales_data & lhs, 
const Sales_data & rhs ) 
{
 Sales_data ret;
 ret.set_bookNo(lhs.get_bookNo());- bookNo- units_sold- revenue- bookNo- units_sold- revenue
 + Sales_data()
 + isbn() const
 + get_unit_sold() const
 + get_revenue() const
 + void set_bookNo (const string &)
 + set_unit_sold(unsigned)
 + Sales_data()
 + get_bookNo() const
 + get_unit_sold() const
 + get_revenue() const
 + void set_bookNo (const string &)
 + set_unit_sold(unsigned)
 + set_revenue(double)
 ret.set_units_sold(lhs.get_units_sold() + rhs.get_units_sold()); 
ret.set_revenue(lhs_get_revenue() + rhs.get_revenue());
 return ret;
 }
Matteo Rossi - Classes
 Memberor non-member?
 • Must be member
 = [] () ->
 • Should be member
 • Compound assignments: += -= /= %= %= ^= &= |= *= <<= >>=
 • Modify operators: ++ -- *
 • Better non-member
 • Arithmetic operators: + - * %
 • Bitwise operators: ^ & |
 • Equality operators: < > <= => != ==
 • Relational operators: ! &&  ||
 58
Matteo Rossi - Classes
 Memberor non-member?
 • Better not overloaded
 * && || !
 • Cannot be overloaded
 :: .* . ?:
 59
Matteo Rossi - Classes
 Defining a Function to Return “this” Object 
class Sales_data {
 private:
 60
 Sales_data
 std::string bookNo; 
unsigned units_sold; 
double revenue; 
public:
 std::string isbn() const { return bookNo; } 
Sales_data& operator+=(const Sales_data&);
 double get_revenue() const; 
}; - bookNo- units_sold- revenue
 + Sales_data()
 + get_bookNo() const
 + get_unit_sold() const
 + get_revenue() const
 + void set_bookNo (const string &)
 + set_unit_sold(unsigned)
 + set_revenue(double)
 + & operator+=(const string &)
Matteo Rossi - Classes
 Why return a reference 
• += = etc. must return a reference
 • mimic built-in operators
 • a = b = c
 • works even with copies
 • (a = b) = c
 • Return copy: a takes value of b
 • Return reference: a takes value of c
 61
Matteo Rossi - Classes
 Defining a Function to Return “this” Object 
Sales_data trans; 
/* modify trans */
 Sales_data total;
 /* modify total */
 total += trans;
 63
Matteo Rossi - Classes
 Defining a Function to Return “this” Object
 • The object on which this operator is called represents the left-hand operand of the 
assignment. The right-hand operand is passed as an explicit argument
 Sales_data& Sales_data::operator+=(const Sales_data &rhs) 
{
 units_sold += rhs.units_sold;  // add the members of rhs 
revenue += rhs.revenue;        
return *this;            
64
 // into the members of "this" object 
// return the object on which the function was called 
}
Matteo Rossi - Classes
 Defining a Function to Return “this” Object
 total += trans; // update the running total
 65
 • the address of total is bound to the implicit this parameter and rhs is bound to trans
 • Thus, when += executes
 units_sold += rhs.units_sold; 
the effect is to add total.units_sold and trans.units_sold, storing the result back into 
total.units_sold
 • the same happens for revenue
Matteo Rossi - Classes
 Defining a Function to Return “this” Object
 66
 • The interesting part about this operator is its return type and the return 
statement
 • When we define an operator, it should mimic the behavior of the built-in 
operator
 • The built-in assignment operators return their left-hand operand as an lvalue
 • To return an lvalue, our operator must return a reference, because the left-hand operand is a 
Sales_data object, the return type is Sales_data&
Matteo Rossi - Classes
 Defining a Function to Return “this” Object
 67
 • As we have seen, we do not need to use the implicit this pointer to access the members of 
the object on which a member function is executing. However, we do need to use this to 
access the object as a whole: 
return *this;   
// return the object on which the function was called
 • Here the return statement dereferences this to obtain the object on which the operator is 
executing
_______________________________________________________
SMART POINTERS

 Memory management in C++
 3
 • Most of the programs we’ve written so far have used objects that have well
defined lifetimes
 • C++ lets us allocate objects dynamically
 • Dynamically allocated objects have a lifetime that is independent of where they are 
created; they exist until they are explicitly freed
 • Programs use the free store or heap for objects that they dynamically 
allocate (i.e., at run time)
 • The program controls the lifetime of dynamic objects
 • Code must explicitly destroy such objects when they are no longer needed
Smart Pointers
 Pointers in action
 Kitten k_obj;
 Kitten* k1 = &k_obj;
 Kitten* k2 = new Kitten;
 Kitten* k3 = nullptr;
 heap
 k3 null
 k2
 k1
 stack
 4
 k_obj
Smart Pointers
 Memory management in C++
 5
 • Properly freeing dynamic objects turns out to be a surprisingly rich source of 
bugs
 • Biggest question is how to ensure that allocated memory will be freed when it 
is no longer in use
 • If we forget to free the memory we have a memory leak
 • If we free the memory when there are still pointers referring to that memory, we have a 
pointer that refers to memory that is no longer valid (dangling pointer)
 • If we subsequently delete the other pointers, then the free store may be corrupted
 • These kinds of errors are considerably easier to make than they are to find 
and fix!!!
Memory leakage
 double* calc(int result_size, int max)
 {
    double* p = new double[max];   // allocate another max doubles
                                   // i.e., get max doubles from the free store
    double* result = new double[result_size]; 
    // … use p to calculate results to be put in result …
    return result;
 }
 double* r = calc(200,100);  // oops! We "forgot" to give the memory
                         // allocated for p back to the free store
 Smart Pointers 6
Memory leakage
 double* calc(int result_size, int max)
 {
    double* p = new double[max];   // allocate another max doubles
                                   // i.e., get max doubles from the free store
    double* result = new double[result_size]; 
    // … use p to calculate results to be put in result …
    delete[] p;
    return result;
 }
 double* r = calc(200,100);
 delete[] r;                         // easy to forget
 Smart Pointers 7
Smart Pointers
 Memory leakage (another example)
 // factory returns a pointer to a dynamically allocated object 
// the caller must remember to delete the memory
 Foo* factory(T arg) 
{
 // process arg as appropriate 
8
 return new Foo(arg); // caller is responsible for deleting this memory
 } 
void use_factory(T arg) 
{
 Foo *p = factory(arg);  // use p but do not delete it
 } // p goes out of scope, but the memory to which p points is not freed! 
Smart Pointers
 Memory leakage (another example)
 // factory returns a pointer to a dynamically allocated object 
// the caller must remember to delete the memory
 Foo* factory(T arg) 
{
 // process arg as appropriate 
9
 return new Foo(arg); // caller is responsible for deleting this memory
 } 
void use_factory(T arg) 
{
 Foo *p = factory(arg);
 delete p;
 }
Smart Pointers
 Smart pointers
 10
 • To make using dynamic objects safer, the library defines smart pointer types 
that manage dynamically-allocated objects
 • Smart pointers ensure that the objects to which they point are automatically 
freed when it is appropriate to do so
 • Goal: implement pointer-like objects in simple and leak-free programs 
Smart Pointers
 Evolution of smart pointers
 • boost::scoped_ptr
 • std::auto_ptr   
has problems with a C-style array!
 deprecated!
 • std::unique_ptr
 • std::weak_ptr
 • std::
 shared_ptr
 C++11
 11
Smart Pointers
 C++11 smart pointers
 • shared_ptr
 • allows multiple pointers to refer to the same object
 • unique_ptr
 • “owns” the object to which it points ⟶ advanced feature (APSC)
 • Both are defined in the memory header
 • Implemented through templates
 12
Smart Pointers
 What is a “smart pointer?”
 13
 • Loose definition: object that behaves like a pointer, but somehow “smarter”
 • Major similarities to raw pointers:
 • Is bound to 0 or 1 objects at a time, often can be re-bound
 • Supports indirection: operator *, operator ->
 • Major differences:
 • Has some “smart feature”
 • Automatic deletion of the owned object
 • Iterators: it++


The shared_ptr Class
 shared_ptr<string> p1;     
// shared_ptr that can point at a string 
shared_ptr<list<int>> p2;  // shared_ptr that can point at a list of ints 
// if p1 is not null, check whether it's the empty string 
if (p1 && p1->empty()) 
15
 *p1 = "hi";  // if so, dereference p1 to assign a new value to that string 
Smart Pointers
 The make_shared Function 
• Safest way to allocate and use dynamic memory 
16
 • Allocates and initializes an object in dynamic memory and returns a shared_ptr that points to that object 
// shared_ptr that points to an int with value 42
 shared_ptr<int> p3 = make_shared<int>(42);
 // p4 points to a string with value "9999999999"
 shared_ptr<string> p4 = make_shared<string>(10, '9'); 
// p5 points to an int that is value-initialized to 0 
shared_ptr<int> p5 = make_shared<int>(); 
// p6 points to a dynamically-allocated, empty vector<string> 
auto p6 = make_shared<vector<string>>(); 
auto p = make_shared<int>(42);   // object to which p points has one user 
auto q(p);     
// p and q point to the same object, object to which p and q point has two users 
Smart Pointers
 shared_ptr implementation 
17
 • We can think of a shared_ptr as if it has an associated counter, usually 
referred to as a reference count
 • Whenever we copy a shared_ptr, the count is incremented
 • The counter is decremented when we assign a new value to the shared_ptr 
and when the shared_ptr itself is destroyed (e.g., when a local shared_ptr 
goes out of scope)
 • Once a shared_ptr counter goes to zero, the shared_ptr automatically 
frees the object that it manages 
This avoids memory leaks!
shared_ptr operations
 Smart Pointers 19
 shared_ptr<T> sp Null smart pointer that can point to objects of type T
 p Use p as a condition; true if p points to an object
 *p Dereference p to get the object to which p points
 p->mem Same as (*p).mem
 p.get() Returns the pointer in p.  Be very careful!
 swap(p,q)
 p.swap(q)
 Swap the pointers in p and q
shared_ptr operations
 Smart Pointers 20
 make_shared<T> args Returns a shared_ptr pointing to a dynamically allocated object of 
type T; use args to initialize that object
 shared_ptr<T> p(q) p is a copy of the shared_ptr q; increments the count in q.
 The pointer in q must be convertible to T*
 p = q p and q are shared_ptrs  holding pointers that can be converted to 
one another. 
Decrements p's reference count and increments q's count; 
deletes p's existing memory if p's count goes to 0
 p.unique() Returns true if p's count is one; false otherwise
 p.use_count() Returns the number of objects sharing with p;
 slow, use for debugging 
Smart Pointers
 shared_ptr implementation 
shared_ptrs automatically destroy their objects ... 
...and automatically free the associated memory 
// factory returns a shared_ptr pointing to a dynamically-allocated object 
shared_ptr<Foo> factory(T arg) 
{
 // process arg as appropriate 
// shared_ptr will take care of deleting this memory 
return make_shared<Foo>(arg); 
} 
void use_factory(T arg) 
{
 shared_ptr<Foo> p = factory(arg);   
// use p 
21
 // p goes out of scope; the memory to which p points is automatically freed 
}   
Smart Pointers
 shared_ptr implementation 
shared_ptrs automatically destroy their objects ... 
...and automatically free the associated memory 
// factory returns a shared_ptr pointing to a dynamically-allocated object 
shared_ptr<Foo> factory(T arg) 
{
 // process arg as appropriate 
// shared_ptr will take care of deleting this memory 
return make_shared<Foo>(arg); 
} 
shared_ptr<Foo> use_factory(T arg)
 {
 shared_ptr<Foo> p = factory(arg);    // use p
 return p;                
22
 // reference count is incremented when we return p
 }   // p goes out of scope; the memory to which p points is not freed
Smart Pointers
 23
 Classes with resources that have dynamic lifetime
 • Programs use dynamic memory for one of three purposes: 
1. They don’t know how many objects they’ll need
 2. They don’t know the precise type of the objects they need 
3. They want to share data between several objects 
vector<string> v1;    
{ // new scope 
// empty vector 
vector<string> v2 = {"a", "an", "the"}; 
v1 = v2;       
// copies the elements from v2 into v1 
}   // v2 is destroyed, which destroys the elements in v2 
// v1 has three elements, which are copies of the ones originally in v2
Smart Pointers
 24
 Classes with resources that have dynamic lifetime
 • Some classes allocate resources with a lifetime that is independent of the 
original object
 • Assume we want to define a class LPVector that will hold a collection of 
elements
 • Unlike the vector, we want LPVector objects which are copies of one another 
to share the same elements (Like-a-Pointer)
 • In the following we will consider a LPVector specialization to store string: 
StrLPVector
Smart Pointers
 26
 Classes with resources that have dynamic lifetime
 • In general, when two objects share the same underlying data, we can’t 
unilaterally destroy the data when an object of that type goes away
 StrLPVector b1;    
{ // new scope 
// empty StrLPVector 
StrLPVector b2 = {"a", "an", "the"}; 
b1 = b2;     
// b1 and b2 share the same elements
 }  // b2 is destroyed, but the elements in b2 must not be destroyed 
// b1 points to the elements originally created in b2 
Smart Pointers
 Defining the StrLPVector Class
 • We can’t store the vector directly in a StrLPVector object
 • Members of an object are destroyed when the object itself is destroyed
 27
 • If b1 and b2 are two StrLPVector that share the same vector, if that vector were stored in 
one of those StrLPVector —say, b2— then that vector, and therefore its elements, would no 
longer exist once b2 goes out of scope
 • To ensure that the elements continue to exist, we’ll store the vector in 
dynamic memory
 • We’ll give each StrLPVector a shared_ptr to a dynamically-allocated vector
 • That shared_ptr member will keep track of how many StrLPVector share the same vector 
and will delete the vector when the last StrLPVector using that vector is destroyed
Defining the StrLPVector Class
 class StrLPVector { 
public: 
    typedef std::vector<std::string>::size_type size_type; 
    StrLPVector();
    StrLPVector(std::initializer_list<std::string> il); 
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // add and remove elements 
    void push_back(const std::string &t) { data->push_back(t); } 
    void pop_back() { data->pop_back(); }
    // element access 
    std::string& front() { return data->front(); }
    std::string& back() { return data->back(); }
 private:
    std::shared_ptr<std::vector<std::string>> data;
    // write msg if data[i] isn't valid
 }; 
Smart Pointers 28
Smart Pointers
 StrLPVector Constructors
 StrLPVector::StrLPVector(): data(make_shared<vector<string>>()) { } 
29
 StrLPVector::StrLPVector(initializer_list<string> il): 
data(make_shared<vector<string>>(il)) { } 
Smart Pointers
 30
 Copying, assigning, and destroying StrLPVectors
 • StrLPVector uses the default versions of the operations that copy, assign, and 
destroy objects of its type 
• These operations copy, assign, and destroy the data members of the class (in this case 
only its shared_ptr)
Smart Pointers
 31
 Copying, assigning, and destroying StrLPVectors
 • When we copy, assign, or destroy a StrLPVector, its shared_ptr member will 
be copied, assigned, or destroyed
 • Copying a shared_ptr increments its reference count
 • Assigning one shared_ptr to another increments the count of the right-hand operand and 
decrements the count in the left-hand operand
 • Destroying a shared_ptr decrements the count
 • If the count in a shared_ptr goes to zero, the object to which that shared_ptr 
points is automatically destroyed
 • The vector allocated by the StrLPVector constructors will be automatically destroyed when 
the last StrLPVector pointing to that vector is destroyed 
Smart Pointers
 Be wary of shared ownership
 32
 • Do not design your code to use shared ownership without a very good reason
 • One such reason is to avoid expensive copy operations, but you should only do this if the 
performance benefits are significant, and the underlying object is immutable (i.e. 
shared_ptr<const Foo>)
 • In many cases copies can be avoided by correctly using references
 • If you do use shared ownership, preferably use shared_ptr
Smart Pointers
 shared_ptr and built-in pointers
 • The smart pointer constructors that take pointers are explicit
 33
 • We cannot implicitly convert a built-in pointer to a smart pointer; we must use the 
direct form of initialization to initialize a smart pointer
 shared_ptr<int> p1 = new int(1024); // error: must use direct 
//        
initialization
 shared_ptr<int> p2(new int(1024));  // ok: uses direct initialization 
• The initialization of p1 implicitly asks the compiler to create a shared_ptr from 
the int* returned by new. Because we can’t implicitly convert a pointer to a 
smart pointer, this initialization is an error
Smart Pointers
 shared_ptr and built-in pointers
 34
 • For the same reason, a function that returns a shared_ptr cannot implicitly convert 
a plain pointer in its return statement: 
shared_ptr<int> clone(int p) { 
// error: implicit conversion to shared_ptr<int> 
return new int(p);
 } 
• We must explicitly bind a shared_ptr to the pointer we want to return: 
shared_ptr<int> clone(int p) {
 // ok: explicitly create a shared_ptr<int> from int* 
return shared_ptr<int>(new int(p)); 
}
Smart Pointers
 Don’t Mix Ordinary Pointers and Smart Pointers! 
35
 • A shared_ptr can coordinate destruction only with other shared_ptrs that are 
copies of itself
 • This fact is one of the reasons it is recommended to use make_shared rather than new
 • We bind a shared_ptr to the object at the same time that we allocate it
 • There is no way to inadvertently bind the same memory to more than one independently
created shared_ptr
 It is dangerous to use a built-in pointer to access an object owned by a 
smart pointer, because we may not know when that object is destroyed
Smart Pointers
 Which type of pointer should I use?
 • Raw Pointer:
 • When you need to store addresses of existing variables
 int a = 10;
 int* ptr_a = &a;
 *ptr_a = 15;
 • Smart pointer:
 • When you want to declare a new dynamic variable
 shared_ptr<int> ptr_a = make_shared<int>(10);