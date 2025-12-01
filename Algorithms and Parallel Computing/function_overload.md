<div align="center">
<h1> Function Overload.
</div>
<div align="center">
    <em>Algorithms and Parallel Computing</em><br>
    <em>Juan Pablo Vallejo Montañez</em><br>
    <em>Notes from Politecnico di Milano 2025/2026 Y.</em><br>
</div>

<br>

Functions (methods) that have the same name but different parameter lists and that appear in the same scope are overloaded.

Function overloading means you we multiple functions with the same name but different parameter lists (different number or types of parameters). Each version of the function is a separate function, not a replacement of the previous one.

````cpp
void print(const string &s);
void print(const int ia[], size_t size);

int j[2] = {0,1};

print("Hello World");    // calls print(const string &)
print(j, 2);             // calls print(const int*, size_t)
````

<i>Note: Overloaded functions must differ in the number or the type(s) of their
parameters. It is an error for two functions to differ only in terms of their return types.</i>

````cpp
Record lookup(const Account&);
bool lookup(const Account&); // error: only the return type is different.
````

<i>Note: If there are two or more functions with the same name but different parameter lists, the compiler chooses which one to call based on the arguments provided in the function call. <strong>Function matching (also known as overload resolution)</strong> is the process by
which a particular function call is associated with a specific function from a set
of overloaded functions</i>

For any given call to an overloaded function, there are three possible outcomes:
- The compiler finds exactly one function that is a best match
- There is no function with parameters that match the arguments in the call. Error: no match
- There is more than one function that matches and none of the matches is clearly best.
Error: ambiguous call.

<strong>Candidate functions :</strong>All functions with the same name.

<strong>Viable functions :</strong> The ones from that set that match the call’s arguments. A viable function must have the same number of parameters as there are arguments in the call, and the type of each argument must match or be convertible to the type of its corresponding parameter.

````cpp
// These are the candidate functiones for f(5.6)

void f(); 
void f(int);                     // Viable function.
void f(int, int);
void f(double, double = 3.14);   // Viable function.

f(5.6); 
````
- <code>f(int)</code> is viable because a conversion exists that can convert the argument
of type double to the parameter of type <code>int</code>.
- <code>f(double, double)</code> is viable because a default argument is provided for the
function's second parameter and its first parameter is of type double, which
exactly matches the type of the parameter.

Finding the best match: f(int) requires to convert the argument from double to int and f(double, double) is an exact match for this argument.
 - An exact match is better than a match that requires a conversion. We call <code>f(double, double)</code>


<i style="color:#2E86C1;">Example</i>

Given the call <code>f(42, 2.56);</code> and the previous candidate functions.The viable functions are <code>f(int, int)</code> and <code>f(double, double)</code>.

There is an overall best match if there is one and only one function for which: 
 - The match for each argument is no worse than the match required by any other viable function.
 - There is at least one argument for which the match is better than the match provided by any other viable function. 

If after looking at each argument there is no single function that is preferable, 
then the call is erroneous (ambiguous call).

| **Viable Function** | **First Argument (42)** | **Second Argument (2.56)** |
| ------------------- | ------------------ | ------------- |
| <code>f(int,int)</code>        | Exact match |  Must be converted to <code>int<code> |
| <code>f(double,double)</code>  | Must be converted to <code>double<code>| Exact match            |

Finally, the compiler will reject this call because it is ambiguous. In well-designed systems, argument casts should not be necessary

## Overloading and const parameters

When a function parameter is passed by value, a top-level const does not affect the function signature.

 - Top-level const = the parameter itself is const.
 - Low-level const = the object it points to or refers to is const.

 ````cpp
Record lookup(Phone);        // parameter passed by value
Record lookup(const Phone);  // parameter passed by value, top-level const
````

Both declarations are effectively the same because passing by value makes a copy of the argument inside the function.Making the copy const does not change the function signature from the compiler’s perspective.<strong> That’s why the second declaration redeclares the first — it’s not a new overload.</strong>

In C++, you can create different overloads of a function depending on whether a parameter is a const reference/pointer or a non-const reference/pointer.

````cpp
Record lookup(Account&);       // function that takes a reference to Account
Record lookup(const Account&); // new function that takes a const reference 
````
The non-const version will not be viable for const actual parameters. Either version is viable for on a non-const actual parameter, but the non-const
version will be a better match

````cpp
Account a;
const Account ca;
lookup(a);             // calls the non-const version, lookup(Account&)
lookup(ca);            // calls the const version, lookup(const Account&)
````

In the first case, where a is a non-const object, both overloads are technically viable:

- <code>func(Phone& p)</code>→ exact match
- <code>func(const Phone& p)</code> → works too, because a non-const object can be treated as const

The compiler prefers the non-const version because it is an exact match. Choosing the const version would require an implicit conversion (treating a non-const object as const), which is less preferred.

## Overloading and const parameters
As with nonmember functions, member functions may be overloaded.The same function-matching process is used for calls to member functions as for nonmember functions.

 ````cpp
class Screen{
     private:
     unsigned x, y;
     char content[40][80];
     public:
     char get() const;
     char get(unsigned x, unsigned y) const;
};

Screen myscreen;
char ch = myscreen.get();     // calls Screen::get()
ch = myscreen.get(0,0);       // calls Screen::get(unsigned, unsigned)

 ````   
## Overloading based on const

We can overload a member function based on whether it is const.

````cpp
class C{
     public:
     f() const;
     f(); 
}
````

The non-const version will not be viable for const objects ( on a const object we can only call const member functions ).
We can call either version on a non-const object, but the non-const version 
will be a better match

