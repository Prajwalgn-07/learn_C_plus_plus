# learn_c++

## 1. Constructor in C++
- Constructor is a special member function with the same name as of the class. It is used to initialize the objects of its class.
- It is automatically invoked whenever an object is created.
- It is constructor is used to initialize the object of its class.
- It is declared in the public section of the class.

````cpp
#include <iostream>
using namespace std;

class Complex
{
private:
    int a, b;

public:
    Complex(void); // Constructor declaration
    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};
````

### 2. Parameterized Constructor
- A parameterized constructor is a constructor with parameters.
- It is used to provide different values to distinct objects.
- It is declared in the public section of the class.
- It is invoked when the objects are created.

````cpp
#include <iostream>
using namespace std;

class Complex
{
private:
    int a, b;

public:
    Complex(int, int); // Constructor declaration
    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

Complex::Complex(int a, int b) // ----> This is a parameterized constructor as it takes 2 parameters
{
    this->a = a;
    this->b = b;
}
````

### 3. Multiple Constructors in C++
- A class can have multiple constructors with a difference in parameters.
- Overloaded constructors allow us to initialize the object in different ways.
- Overloaded constructors are declared in the public section of the class.
- They are invoked according to the arguments passed in the object while creating it.

````cpp
#include <iostream>
using namespace std;

class Complex
{
private:
    int a, b;

public:
    Complex(int, int);      // Constructor declaration
    Complex(int);           // Constructor declaration
    Complex(void);          // Constructor declaration
    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

Complex::Complex(int a, int b) // ----> This is a parameterized constructor as it takes 2 parameters
{
    this->a = a;
    this->b = b;
}

Complex::Complex(int a) // ----> This is a parameterized constructor as it takes 1 parameter
{
    this->a = a;
    b = 0;
}

Complex::Complex(void) // ----> This is a default constructor as it takes no parameters
{
    a = 0;
    b = 0;
}
````
### 4. Copy Constructor in C++  

- A copy constructor is a member function that initializes an object using another object of the same class.

- A copy constructor has the following general function prototype:

````cpp
ClassName ( ClassName &old_obj);
````
- Here, old_obj is an object of the ClassName class whose values are copied to the new object being created.

- When is copy constructor called?

- In C++, a Copy Constructor may be called in the following cases:

````cpp
ClassName obj2(obj1);   // Copy constructor called
````
```
ClassName obj2 = obj1;  // Copy constructor called
```

````cpp
#include <iostream>
using namespace std;

class Number
{
    int a;

public:

Number() {} // Default Constructor
Number(Number &obj)
{
    cout << "Copy constructor called!!!" << endl;
    a = obj.a;
}
void display()
{
    cout << "The number for this object is " << a << endl;
}

void setdata(int a)
{
    this->a = a;
}
};

int main()
{
    Number x, y;
    x.setdata(3);
    y.setdata(4);

    Number z(x); // Copy constructor invoked
    z.display();

    Number z2 = y; // Copy constructor invoked
    z2.display();

    return 0;
}
````
### 5. Destructor in C++
- A destructor is a member function that destructs or deletes an object.
- A destructor has the same name as that of the class with a tilde(~) symbol before it.
- Unlike a constructor that is used to initialize an object, the destructor is used to destroy an object.

````cpp
#include <iostream>
using namespace std;

class Number
{
    int a;

public:

Number() {} // Default Constructor
Number(Number &obj)
{
    cout << "Copy constructor called!!!" << endl;
    a = obj.a;
}
~Number() // Destructor
{
    cout << "Destructor called for " << a << endl;
}
void display()
{
    cout << "The number for this object is " << a << endl;
}

void setdata(int a)
{
    this->a = a;
}
};

int main()
{
    Number x, y;
    x.setdata(3);
    y.setdata(4);

    Number z(x); // Copy constructor invoked
    z.display();

    Number z2 = y; // Copy constructor invoked
    z2.display();

    return 0;
}
````

### 6. Operator Overloading in C++

- Operator overloading is a concept of object-oriented programming.
- It is a technique by which operators used in a programming language are implemented as functions.
- Operator overloading is used to overload or redefines most of the operators available in C++.
- It is used to perform the operation on the user-defined data type.
- It allows us to use the same operator for multiple operations.
- It is achieved by defining a function inside a class.

````cpp
#include <iostream>
using namespace std;

class Complex
{
private:
    int real, imaginary;

public:

 Complex operator+(Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.imaginary = imaginary + c.imaginary;
        return temp;
    }
    void getData(int a, int b)
    {
        real = a;
        imaginary = b;
    }
    void displayData()
    {
        cout << "Complex number is " << real << " + " << imaginary << "i" << endl;
    }
};

int main()
{
    Complex c1, c2, c3;
    c1.getData(2, 3);
    c2.getData(4, 5);
    c3 = c1 + c2;
    c3.displayData();
    return 0;
}
````
