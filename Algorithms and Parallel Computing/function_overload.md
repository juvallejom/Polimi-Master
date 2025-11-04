functions with defaul parameters

Functions that have the same name but different parameters list and that appear in the same scope are overloaded

If theere are two differente decalrations with the smane name, the decalrario will be works in order to what is the strucutre of the invocation

Overloaded function must differ in the number ir the type of their parameters.

It is an error for two functionsto differ only in terms of their retunr types

Calling an overloaded function 
5
 • Function matching (also known as overload resolution) is the process by 
which a particular function call is associated with a specific function from a set 
of overloaded functions
 • For any given call to an overloaded function, there are three possible 
outcomes: 
• the compiler finds exactly one function that is a best match
 • there is no function with parameters that match the arguments in the call. Error: no match
 • there is more than one function that matches and none of the matches is clearly best. 
Error: ambiguous cal

Calling and overloading functio

 void f();
 void f(int);
 void f(int, int);
 void f(double, double = 3.14); 
f(5.6); 
• Identify the set of overloaded functions considered for the call:
 • candidate functions
 6
 • Select from the set of candidate functions those that can be called with the 
arguments in the given call: 
• viable functions

 Viable functions: a function must have the same number of parameters as 
there are arguments in the call, and the type of each argument must:
 • match
 • or be convertible to the type of its corresponding parameter


for this case the first and the last oprion are not viable fuctions beacuse the numner of parameters doent mathc

The second option can works beacuse, c¿¿ can convert the float to an int

     f(int) is viable because a conversion exists that can convert the argument 
of type double to the parameter of type int
 • f(double, double) is viable because a default argument is provided for the 
function's second parameter and its first parameter is of type double, which 
exactly matches the type of the parameter

 Finding the best match, if any! 
11
 • Finally look at each argument in the call and select the viable function (or 
functions) for which the corresponding parameter best matches the argument
 • the closer the types of the argument and parameter are to each other, the better the match
 • f(int) requires to convert the argument from double to int
 • f(double, double) is an exact match for this argument
 • An exact match is better than a match that requires a conversion
 • We call f(double, double)!


 Function matching with multiple parameters
 • f(42, 2.56);
 • The viable functions are  f(int, int)  and   f(double, double)
 12
 • There is an overall best match if there is one and only one function for which: 
• the match for each argument is no worse than the match required by any other viable 
function 
• there is at least one argument for which the match is better than the match provided by any 
other viable function 
• If after looking at each argument there is no single function that is preferable, 
then the call is erroneous (ambiguous call)

Function matching with multiple parameters
 • Consider the first argument
 • f(int, int) is an exact match
 • f(double, double): the int argument 42 must be converted to double
 • A match through a built-in conversion is “less good” than one that is exact
 • Consider the second argument
 • f(double, double) is an exact match to the argument 2.56
 • f(int, int):  the double argument 2.56 must be converted from double to int
 • The compiler will reject this call because it is ambiguous
 • In well-designed systems, argument casts should not be necessary


  Overloading and const parameters
 14
 • A parameter that has a top-level const is indistinguishable from one without a 
top-level const
 Record lookup(Phone);
 Record lookup(const Phone);    
// redeclares Record lookup(Phone)
Constructors and Classes Advanced Topics
 Overloading and const parameters
 15
 • We can overload based on whether the parameter is a reference (or pointer) to the 
const or non-const version of a given type
 Record lookup(Account&);            
Record lookup(const Account&);      
// function that takes a reference to Account 
// new function that takes a const reference 
• The non-const version will not be viable for const actual parameters;
 • Either version is viable for on a non-const actual parameter, but the non-const 
version will be a better match
 Account a;
 const Account ca;
 lookup(a);           // calls the non-const version, lookup(Account&)
 lookup(ca);          // calls the const version, lookup(const Account&)
Constructors and Classes Advanced Topics
 Overloading member functions
 • As with nonmember functions, member functions may be overloaded 
16
 • The same function-matching process is used for calls to member functions as for nonmember 
functions
 class Screen{
 private:
 unsigned x, y;
 char content[40][80];
 public:
 };
 char get() const;
 char get(unsigned x, unsigned y) const;
 Screen myscreen;
 char ch = myscreen.get();     // calls Screen::get()
 // calls Screen::get(unsigned, unsigned)
 ch = myscreen.get(0,0);       
Constructors and Classes Advanced Topics
 Overloading based on const
 • We can overload a member function based on whether it is const 
class C{
 public:
 f() const;
 f(); 
}
 • The non-const version will not be viable for const objects;
 • on a const object we can only call const member functions
 17
 • We can call either version on a non-const object, but the non-const version 
will be a better match

