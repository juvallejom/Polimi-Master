<div align="center">
<h1> Strings
</div>
<div align="center">
    <em>Algorithms and Parallel Computing</em><br>
    <em>Juan Pablo Vallejo Montañez</em><br>
    <em>Notes from Politecnico di Milano 2025/2026 Y.</em><br>
</div>

# 1. Definitions.

A <strong>string</strong> is a variable-length sequence of characters.

To use the string type, we must include its header.
Since it is part of the C++ Standard Library, string is defined in the std namespace.

````cpp
#include <string>
using std::string;
````

## 1.1 Declaration.

| **Declaration**       | **Description** |
| --------------------- | --------------- |
| `string s1;`          | Default initialization — `s1` is an empty string.                |
| `string s2 = s1;`     | `s2` is a copy of `s1`.                                          |
| `string s3 = "hiya";` | `s3` is initialized from a string literal.                       |
| `string s4(10, 'c');` | `s4` contains 10 copies of the character `'c'` → `"cccccccccc"`. |

<i style="color:#2E86C1;">Direct and Copy forms of initialization.</i>

When we initialize a variable using the <code>=</code>operator, we are performing a copy initialization. The compiler copies the initializer on the right-hand side into the newly created object.

When we omit the <code>=</code>, we are performing a direct initialization. The object is created directly with the given arguments.

| **Form**              | **Example** | **Type** |
| --------------------- | ----------- | -------- |
| `string s5 = "hiya";` | Uses `=` → **Copy initialization**                 |          |
| `string s6("hiya");`  | Without `=` → **Direct initialization**            |          |
| `string s7(10, 'c');` | Creates `"cccccccccc"` → **Direct initialization** |          |


## 1.2 Accessing String Elements.

There are two ways to access individual characters in a std::string:

1. Using the <strong>subscript operator ([]).</strong>

    The subscript operator takes a string::size_type value that represents the position of the character to access.

    It returns a reference to the character at that position.Subscripts start at 0.

    ````cpp
    string s = "Hello";
    cout << s[0];  // 'H' — first character
    cout << s[1];  // 'e' — second character
    cout << s[s.size() - 1];  // 'o' — last character
    ````
    <i>Accessing a position outside the valid range (e.g., s[s.size()]) causes undefined behavior.</i>

2. Using an iterator.

    We can also access string elements using iterators.

    ````cpp
    for (auto it = s.begin(); it != s.end(); ++it)
    cout << *it;
    ````
# 1.3 Operations.

| **Operation** | **Description**   |
| ------------- | ----------------- |
| `os << s`            | Writes `s` to the output stream `os`. Returns `os`.                                        |
| `is >> s`            | Reads a **whitespace-separated string** from the input stream `is` into `s`. Returns `is`. |
| `getline(is, s)`     | Reads an entire **line** (until `'\n'`) from `is` into `s`. Returns `is`.                  |
| `s.empty()`          | Returns `true` if `s` is empty; `false` otherwise.                                         |
| `s.size()`           | Returns the **number of characters** in `s`.                                               |
| `s[n]`               | Returns a **reference** to the character at position `n` in `s`.                           |
| `s1 + s2`            | Returns a **new string** formed by concatenating `s1` and `s2`.                            |
| `s1 = s2`            | Replaces the contents of `s1` with a **copy** of `s2`.                                     |
| `s1 == s2`           | Returns `true` if both strings contain the **same sequence of characters**.                |
| `s1 != s2`           | Returns `true` if the strings differ.                                                      |
| `<`, `<=`, `>`, `>=` | Perform **lexicographical (dictionary)** comparisons — case sensitive.                     |

# 1.4 Dealing with Characters in a String.

| **Function**  | **Description** |
| ------------- | --------------- |
| `isalnum(c)`  | Returns `true` if `c` is a **letter or a digit**.                                               |
| `isalpha(c)`  | Returns `true` if `c` is a **letter**.                                                          |
| `iscntrl(c)`  | Returns `true` if `c` is a **control character** (e.g., newline, tab).                          |
| `isdigit(c)`  | Returns `true` if `c` is a **digit** (`0–9`).                                                   |
| `isgraph(c)`  | Returns `true` if `c` is **printable and not a space**.                                         |
| `islower(c)`  | Returns `true` if `c` is a **lowercase letter**.                                                |
| `isprint(c)`  | Returns `true` if `c` is a **printable character** (includes space).                            |
| `ispunct(c)`  | Returns `true` if `c` is a **punctuation character** (e.g., `. , ! ?`).                         |
| `isspace(c)`  | Returns `true` if `c` is **whitespace** (space, tab, return, newline, etc.).                    |
| `isupper(c)`  | Returns `true` if `c` is an **uppercase letter**.                                               |
| `isxdigit(c)` | Returns `true` if `c` is a **hexadecimal digit** (`0–9`, `A–F`, `a–f`).                         |
| `tolower(c)`  | If `c` is **uppercase**, returns its **lowercase** equivalent; otherwise returns `c` unchanged. |
| `toupper(c)`  | If `c` is **lowercase**, returns its **uppercase** equivalent; otherwise returns `c` unchanged. |
