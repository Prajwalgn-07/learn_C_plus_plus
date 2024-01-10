# learn_c++

### 1. Manipulation of pointers

- We can manipulate the pointer with the indentation operator `*` , which is used to declare a pointer and to dereference a pointer.
- The `&` operator is used to get the address of a variable.

```c++
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int *p = &a;
    cout << "The address of a is " << p << endl;
    cout << "The value of a is " << *p << endl;
    *p = *p/2;
    cout << "The value of a is " << *p << endl;
    return 0;
}
```

### 2. Pointer expressions and pointer arithmetic

- Pointer expressions are expressions that contain pointers.
- Pointer arithmetic is the arithmetic of pointers to objects of a given type.
- A pointer can be incremented and decremented.
- Any integer can be added to or subtracted from a pointer.
- A pointer can be subtracted from another pointer of the same type.

```c++ 
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int *p = &a;
    cout << "The address of a is " << p << endl;
    cout << "The value of a is " << *p << endl;
    *p = *p/2;
    cout << "The value of a is " << *p << endl;
    cout << "The address of a is " << p << endl;
    p++;
    cout << "The address of a is " << p << endl;
    p--;
    cout << "The address of a is " << p << endl;
    return 0;
}
```

### 3. Using pointers
  
  a. Pointers with arrays
  - The name of an array is a pointer to the first element of the array.
    - The name of an array is a constant pointer to the first element of the array.
    - The name of an array is a constant pointer that cannot be incremented or decremented.
    - The name of an array is a constant pointer that cannot be assigned to another address.

    ```c++
    #include <iostream>
    using namespace std;

    int main() {
        int a[5] = {1, 2, 3, 4, 5};
        cout << "The address of a is " << a << endl;
        cout << "The value of a is " << *a <<
        cout << "The address of a[0] is " << &a[0] << endl;
        cout << "The value of a[0] is " << a[0] << endl;
        cout << "The address of a[1] is " << &a[1] << endl;
        cout << "The value of a[1] is " << a[1] << endl;

        int *p = a;

        cout << "The address of a is " << p << endl;
        cout << "The value of a is " << *p << endl;
        cout << "The address of a[0] is " << &p[0] << endl;
        cout << "The value of a[0] is " << p[0] << endl;
        cout << "The address of a[1] is " << &p[1] << endl;

        return 0;

    }
    ```
    b. Arrays of pointers
    - An array of pointers is an array whose elements are pointers to objects of a given type.
    - An array of pointers can be used to store a list of strings.

    ```c++
    #include <iostream>
    using namespace std;

    int main() {
        char *names[5] = {"John", "Jack", "Jill", "Jane", "James"};
        for (int i = 0; i < 5; i++) {
            cout << names[i] << endl;
        }
        return 0;
    }
    ```
    c. Pointers and strings

    ```c++
    #include <iostream>
    using namespace std;

    int main() {
        char str[] = "Hello";
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            cout << str[i] << i[str]<<*(str+i)<<*(i+str)<<endl;
        }
    }
    ```

    d. Pointer to functions
    - A pointer to a function is a pointer that holds the address of a function.
    - A pointer to a function can be used to call a function.

    ```c++
    #include <iostream>
    using namespace std;

    int add(int a, int b) {
        return a + b;
    }

    int main() {
        int (*p)(int, int);
        p = add;
        cout << p(2, 3) << endl;
        return 0;
    }
    ```

    ```c++
    #include <iostream>
    using namespace std;

    typedef int (*func)(int, int);

    int add(int a, int b) {
        return a + b;
    }

    int sub(int a, int b) {
        return a - b;
    }

    int main() {
        func f;
        f = add;
        cout << f(2, 3) << endl;
        f = sub;
        cout << f(2, 3) << endl;
        return 0;
    }
    ```
    e. Pointers to objects
    - A pointer to an object is a pointer that holds the address of an object.
    - A pointer to an object can be used to access the object.

    ```c++
    #include <iostream>
    using namespace std;

    class Rectangle {
        private:
            int length;
            int breadth;
        public:
            Rectangle(int l, int b) {
                length = l;
                breadth = b;
            }
            int area() {
                return length * breadth;
            }
    };

    int main() {
        Rectangle r(10, 5);
        Rectangle *p;
        p = &r;
        cout << p->area() << endl;
        return 0;
    }
    ```
    f. Array of pointers to objects
    - An array of pointers to objects is an array whose elements are pointers to objects of a given type.
    - An array of pointers to objects can be used to store a list of objects.

    ```c++
    #include <iostream>
    using namespace std;

    class Rectangle {
        private:
            int length;
            int breadth;
        public:
            Rectangle(int l, int b) {
                length = l;
                breadth = b;
            }
            int area() {
                return length * breadth;
            }
    };

    int main() {
        Rectangle r1(10, 5);
        Rectangle r2(5, 5);
        Rectangle r3(10, 10);
        Rectangle *p[3];
        p[0] = &r1;
        p[1] = &r2;
        p[2] = &r3;
        for (int i = 0; i < 3; i++) {
            cout << p[i]->area() << endl;
        }
        return 0;
    }
    ```
### 4. this pointer
- The `this` pointer is a pointer that points to the object for which the member function is called.
- The `this` pointer is used to refer to the object for which the member function is called.
- The `this` pointer is used to access the members of the object for which the member function is called.
- The `this` pointer is used to make a copy of the object for which the member function is called.

```c++
#include <iostream>

class MyClass {
public:
    void printAddress() {
        std::cout << "Object address: " << this << std::endl;
    }

    void setValue(int value) {
        this->value = value;
    }

    int getValue() const {
        return value;
    }

private:
    int value;
};

int main() {
    MyClass obj1, obj2;

    obj1.printAddress(); 
    obj2.printAddress(); 

    obj1.setValue(42);
    std::cout << "Value of obj1: " << obj1.getValue() << std::endl;

    return 0;
}
```

### 5. Virtual Functions
- A virtual function is a function that can be overridden in a derived class.

```c++
#include <iostream>
using namespace std;

class Base {
    public:
        virtual void print() {
            cout << "Base" << endl;
        }
};

class Derived : public Base {
    public:
        void print() {
            cout << "Derived" << endl;
        }
};

int main() {
    Base b;
    Derived d;
    Base *bptr;
    cout << "bptr pointer pointing to derived" << endl;
    bptr = &d;
    bptr->print();

    cout << "bptr pointer pointing to base" << endl;
    bptr= &b;
    bptr->print();
    return 0;
}
```

### 6. Pure Virtual Functions
- A pure virtual function is a virtual function that has no definition in the base class.
- A pure virtual function is a virtual function that is declared as follows:
    - virtual void func() = 0;
- A pure virtual function is a virtual function that must be overridden in a derived class.
    
    ```c++
    #include <iostream>
    using namespace std;

    class Base {
        public:
            virtual void print() = 0;
    };

    class Derived : public Base {
        public:
            void print() {
                cout << "Derived" << endl;
            }
    };

    int main() {
        Derived d;
        d.print();
        return 0;
    }
    ```
    





  