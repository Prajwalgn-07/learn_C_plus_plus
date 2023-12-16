# learn_c++

## 1.  How does c++ code gets compiled?
- The Below image shows the compilation process of c++ code.
- The C++ code is first compiled by the preprocessor, which converts the code into a different code by replacing the macros, comments, etc. with actual code.
- The output of the preprocessor is then compiled by the compiler, which converts the code into assembly code.
- The linker then links the assembly code with the library code and converts it into machine code.
![C++](images/compiler_system.png)

## 2.  How does namespace help in avoiding name conflicts?
- Namespaces are used to group related variables and functions, without them, all the variables and functions would exist in the global scope. This would increase the chance of naming conflicts.
- In [this](code/namespace/) example there are two header files with same class name `Speed`, by using namespace we can avoid name conflicts. and use both the classes in the same file.

## 3. Pointers in C++
- A pointer is a variable that stores the address of another variable.
```
int a = 10;
int *p = &a;(here the pointer p is decalred and it stores the address of a int *p -> p = &a)
cout << "Address of a: " << &a << endl;
cout << "Value of p: " << p << endl;
```

## 4. Reference Variables in C++
- A reference variable is an alias, that is, another name for an already existing variable. Once a reference is initialized with a variable, either the variable name or the reference name may be used to refer to the variable.
```
int a = 10;
int &r = a;
cout << "Value of a: " << a << endl;
cout << "Value of r: " << r << endl;
```

## 5. Dynamic Memory Allocation in C++
- Dynamic memory allocation refers to performing memory allocation manually by the programmer.
- The new operator is used for dynamic memory allocation in C++. It allocates memory on the heap at runtime.
- The delete operator is used to deallocate memory that was allocated using new.
```
int *p = new int;
*p = 10;
cout << "Value of p: " << *p << endl;
delete p;
```
- if the sufficient memory is not available then the new operator returns a null pointer. Therefore, it is good practice to check for null pointers after allocating memory dynamically.
```
int *p = new int;
if (!p) {
    cout << "Allocation of memory failed\n";
}
```


## 6. Scope resolution operator
- The scope resolution operator is used to resolve the scope of variables, functions and class objects.
- The scope resolution operator is ::. It is used for the following purposes:
  - To access a global variable when there is a local variable with the same name
    ``` 
        int x = 10; // global variable
        int main() {
            int x = 20; // local variable
            cout << "Value of global x is " << ::x;
            cout << "Value of local x is " << x;
        }
    ```
  - To define a function outside a class
  ```
    class A {
        public:
        void func();
    };
    void A::func() {
        // code
    }
  ```
  - To access a class’s static variables
    ```
        class A {
            public:
            static int x;
        };
        int A::x = 0;
    ```
  - To access a class’s member variables and functions from a member function that has the same name as a member variable
    ```
        class A {
            public:
            int x;
            void func(int x);
        };
        void A::func(int x) {
            A::x = x;
        }
    ```

## 7.  Implicit Type Conversion
- Implicit type conversion, also known as coercion, is an automatic type conversion by the compiler.
- It uses waterfall model, which means that the lower type is converted to the higher type.
- int->unsigned int->long->unsigned long->long long->unsigned long long->float->double->long double
``` 
  m = 5 + 2.75; // 5 is converted to float
```