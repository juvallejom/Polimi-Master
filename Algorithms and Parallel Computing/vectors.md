<div align="center">
<h1> Vectors
</div>
<div align="center">
    <em>Algorithms and Parallel Computing</em><br>
    <em>Juan Pablo Vallejo Montañez</em><br>
    <em>Notes from Politecnico di Milano 2025/2026 Y.</em><br>
</div>

## 1. Definition.

<div align="justify">
A <strong>vector</strong> is a <i>variable-sized</i> array that can grow or shrink dynamically during program execution.
Vectors are often referred to as <i>containers</i> because they contain other objects.

Vectors are defined in the Standard Library `<vector>`.To use them, you must include the appropriate header and namespace:

````cpp
#include <vector>
using std::vector;
````

<i style="color:#2E86C1;">Features.</i>

- A vector is a class template that is part of the <strong>Standard Template Library (STL)</strong>.
- Vectors grow efficiently. When more space is needed, they automatically allocate a larger memory block and copy existing elements. Because of this, it is usually unnecessary (and can even reduce performance) to define a vector with a fixed size in advance.
- Exception: If all elements must have the same value, defining the vector with an initial size and value is appropriate.
- If elements will have different values, it is generally more efficient to define an empty vector and add elements dynamically at runtime using <code>push_back()</code>.

We can define vectors to hold objects of most any type:

````cpp
vector<int> ivec;               // ivec holds objects of type int 
vector<Sales_item> Sales_vec;   // holds Sales_items and imagine Sales_item as a struct or a class
vector<vector<string>> file;    // vector whose elements are vectors
````

<i style="color:#FF0000;">SEE SLIDES PAGE 181-182 TO LOOK HOW WORK THE VECTORS FROM A VISUAL WAY</i>

## 1.2 Adding Elements.
To add an element to a vector, we use the method:
````cpp
vector.push_back(element);
````
This function appends the new element to the end of the vector.

<div style="text-indent: 30px;">
<i style="color:#FF0000;">This is an error</i>
</div>

````cpp
vector<int> ivec;               
for (int ix = 0; ix != 10; ++ix) 
    vec[ix] = ix; 
````
<div style="text-indent: 30px;">
<i style="color:limegreen;">This is the correct way</i>
</div>

````cpp
for (int ix = 0; ix != 10; ++ix) 
    ivec.push_back(ix); 
````

## 1.3 Accessing Array Elements
To access an element in a vector, we use the <strong>subscript operator ([])</strong>:
````cpp
vector[i];
````
where i is the index (or position) of the element in the vector, starting from 0.

We can access the elements of a vector recursively (sequentially) using a regular for loop or a range-based for loop.

````cpp
for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << '\n';
}
````

<strong>Range-based for loop</strong>: This version automatically iterates over each element in the vector. We don’t need to manage indices manually.

````cpp
for (int x : v) {
    cout << x << '\n';
}
````

## 1.4 Declaration.
| **Declaration** |**Description** |
| --------------- |--------------- |
| `vector<T> v1`                | Vector that holds objects of type `T`. Default initialization — `v1` is empty.                               |
| `vector<T> v2(v1)`            | `v2` is a **copy** of each element in `v1`.                                                                  |
| `vector<T> v2 = v1`           | Same as above — creates a copy of `v1`.                                                                      |
| `vector<T> v3(n, val)`        | `v3` has **`n` elements**, each initialized with the value `val`.                                            |
| `vector<T> v4(n)`             | `v4` has **`n` value-initialized** elements (e.g., zeros for numeric types).                                 |
| `vector<T> v5{a, b, c, …}`    | `v5` has as many elements as there are initializers; each element is initialized by the corresponding value. |
| `vector<T> v5 = {a, b, c, …}` | Same as above — list initialization with assignment syntax.                                                  |
## 1.5 Operations
| **Operation**  | **Description** |
| -------------- |---------------- |
| `v.empty()`          | Returns `true` if `v` is empty; `false` otherwise.                                          |
| `v.size()`           | Returns the **number of elements** in `v`.                                                  |
| `v.push_back(t)`     | Adds an element with value `t` to the **end** of the vector.                                |
| `v[n]`               | Returns a **reference** to the element at position `n` in `v`.                              |
| `v1 = v2`            | Replaces the elements in `v1` with a **copy** of the elements in `v2`.                      |
| `v1 = {a, b, …}`     | Replaces the elements in `v1` with a **copy** of the given initializer list.                |
| `v1 == v2`           | Returns `true` if both vectors have the same size and all corresponding elements are equal. |
| `v1 != v2`           | Returns `true` if the vectors differ in size or any element differs.                        |
| `<`, `<=`, `>`, `>=` | Compare vectors in **lexicographical (dictionary) order**.                                  |

• We can fetch a given element using the subscript operator (i.e., indexing
starting from 0)

• We can compute an index and directly fetch the element at that position
    
</div>




