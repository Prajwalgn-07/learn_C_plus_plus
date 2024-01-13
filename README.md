# learn_c++


## Manipulating Strings

### 1. Commonly used string constructors
```cpp
string s1; // s1 is an empty string
string s2(s1); // s2 is a copy of s1
string s3("value"); // s3 is a copy of the string literal
string s4(n, 'c'); // s4 is n copies of the character 'c'
```
### 2. Important fucntions supported by string class
```cpp
s.empty() // returns true if s is empty
s.size() // returns the number of characters in s
s[n] // returns a reference to the char at position n in s
s1+s2 // returns a string that is the concatenation of s1 and s2
s1=s2 // assigns s2 to s1
s1==s2 // returns true if s1 and s2 have the same value
s1!=s2 // returns true if s1 and s2 have different values
<, <=, >, >= // lexicographic comparisons
append()// adds characters to the end of a string
at() // returns a reference to the character at the given position; throws an out_of_range exception if the position is invalid
begin() // returns an iterator to the first character in the string
```

## New Features of ANSII C++
### 1. auto type specifier
```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    auto i = 0, *p = &i; // i is int, p is int*
    auto sz = 0, pi = 3.14; // error: inconsistent types for sz and pi
    return 0;
}
```
### 2. New Operators

#### 2.1. static_cast operator
- static_cast is used to convert one type to another
- static_cast can be used to convert an ordinary pointer to a void pointer
- static_cast can be used to convert a pointer to a base class to a pointer to a derived class
```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int i = 3.14;
    int j = static_cast<int>(3.14);
    void *p = &i;
    double *dp = static_cast<double*>(p);
    return 0;
}
```
#### 2.2. const_cast operator
- const_cast is used to convert a const object to a non-const object
```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    const char *pc;
    char *p = const_cast<char*>(pc);
    return 0;
}
```

#### 2.3. reinterpret_cast operator
- reinterpret_cast is used to convert a pointer to any other type of pointer
```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int *ip;
    char *pc = reinterpret_cast<char*>(ip);
    return 0;
}
```

#### 2.4. dynamic_cast operator
- dynamic_cast is used to convert a pointer to a base class to a pointer to a derived class
```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    Base *bp = new Derived;
    Derived *dp = dynamic_cast<Derived*>(bp);
    return 0;
}
```

### 3. Class Implementation
#### 3.1. explicit keyword in constructor
- The explicit keyword is used to prevent the compiler from using that constructor for implicit conversions
```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

clas ABC{
   int m;
   public 
   explicit ABC(int x) { m = x; }
};

int main()
{
    ABC a = 10; // error: no suitable conversion function from "int" to "ABC" exists
    ABC b(10); // OK
    return 0;
}
```
#### 3.2. Mutable keyword
- The mutable keyword allows a particular data member of const object to be modified
```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ABC{
   mutable int m;
   public 
   ABC(int x) { m = x; }
   void set(int x) const { m = x; }
};

int main()
{
    const ABC a(10);
    a.set(20); // OK
    return 0;
}
```

### Namespace scope
 #### 1. Namespace Definition
 ```cpp
   #include <iostream>
   using namespace std;
   
   namespace myNamespace {
      int x;
      int y;
      void display(int n){
         cout << "The number is: " << n << endl;
      }
   }

   int main(){
      myNamespace::x = 10;
      myNamespace::y = 20;
      myNamespace::display(myNamespace::x);
      myNamespace::display(myNamespace::y);
      return 0;
   }     
   ```
   #### 2. Nested Namespaces
   ```cpp
   #include <iostream>
   using namespace std;

   namespace first_space{
      void func(){
         cout << "Inside first_space" << endl;
      }
      namespace second_space{
         void func(){
            cout << "Inside second_space" << endl;
         }
      }
   }

   int main(){
      // Calls function from first name space.
      first_space::func();
      
      // Calls function from second name space.
      first_space::second_space::func(); 

      return 0;
   }
   ```
   #### 3. Un named namespace
   ```cpp
   #include <iostream>
   using namespace std;

   // unnamed namespace
   namespace {
      void func(){
         cout << "Inside unnamed namespace" << endl;
      }
   }

   int main(){
      func();
      return 0;
   }
   ```