# learn_c++

## 1. What is Call by refernce and return by reference
### 1.1 Call by reference
- Call by reference is a method of passing arguments to a function where the function receives the reference of the variable rather than the value of the variable. The reference of the variable is passed to the function as the address of the variable. Any changes made to the reference variable will affect the original variable.
```
#include <iostream>
using namespace std;

void swap(int &x, int &y) {
   int temp;
   temp = x; /* save the value of x */
   x = y;    /* put y into x */
   y = temp; /* put temp into y */

   return;
}

int main(){
    int a = 100;
    int b = 200;
    swap(a,b);
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
}
```
### 1.2 Return by reference
- Return by reference is a method of returning the reference of the variable rather than the value of the variable. The reference of the variable is returned from the function as the address of the variable. Any changes made to the reference variable will affect the original variable.
```
#include <iostream>
using namespace std;

int& max(int &x, int &y) {
    if(x > y){
        return x;
    }else{
        return y;
    }
}

int main(){
    int a = 100;
    int b = 200;
    int &c = max(a,b);
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl;
    c = 300;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl;
}
```

## 2. What is INLINE function

- A inline function is a function that is expanded in line when its invoked
- With the use of inline function the overhead of function call is reduced.
- If the inline function is used for small functions, then it reduces the execution time of the program.

```
#include <iostream>
using namespace std;

inline int max(int x, int y){
    return (x > y)? x : y;
}

int main(){
    int a = 100;
    int b = 200;
    cout<<"Max = "<<max(a,b)<<endl;
}
```
### 3. Function Overloading
- Function overloading is a feature in C++ where two or more functions can have the same name but different parameters.
- Function overloading can be considered as an example of polymorphism feature in C++.

```
#include <iostream>
using namespace std;

int max(int x, int y){
    return (x > y)? x : y;
}

double max(double x, double y){
    return (x > y)? x : y;
}

int main(){
    int a = 100;
    int b = 200;
    cout<<"Max = "<<max(a,b)<<endl;
    double c = 100.5;
    double d = 200.5;
    cout<<"Max = "<<max(c,d)<<endl;
}
```
### 4. How to define a class and create objects and access class members

```
#include <iostream>
using namespace std;

class Rectangle{
    public:
        int length;
        int breadth;
        int area(){
            return length * breadth;
        }
        int perimeter(){
            return 2 * (length + breadth);
        }
};


int main(){
    Rectangle r1;
    r1.length = 100;
    r1.breadth = 200;
    cout<<"Area = "<<r1.area()<<endl;
    cout<<"Perimeter = "<<r1.perimeter()<<endl;
}
```

### 5. How to define member functions outside the class

```
#include <iostream>
using namespace std;

class Rectangle{
    public:
        int length;
        int breadth;
        int area();
        int perimeter();
};

int Rectangle::area(){
    return length * breadth;
}

int Rectangle::perimeter(){
    return 2 * (length + breadth);
}

int main(){
    Rectangle r1;
    r1.length = 100;
    r1.breadth = 200;
    cout<<"Area = "<<r1.area()<<endl;
    cout<<"Perimeter = "<<r1.perimeter()<<endl;
}
```

### 6. Private and Public Access Specifiers

```
#include <iostream>
using namespace std;

class Sample{
    int a; // private
    void read();
    public:
        int b; // public
        void print();
};

void Sample::read(){
    a = 100;
}

void Sample::print(){
    read();
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
}

int main(){
    Sample s;
    s.b = 200;
    s.print();
}
```

### 7. Static Data Members and Static Member Functions
- Static data members are class members that are shared by all objects.
- Static member functions are class functions that are independent of objects.

```
#include <iostream>
using namespace std;

class Sample{
    public:
        static int x;
        static int y;
        static void print(){
            cout<<"x = "<<x<<endl;
            cout<<"y = "<<y<<endl;
        }
};

int Sample::x = 100;
int Sample::y = 200;

int main(){
    Sample::print();
}
```

### 8. Objects as function Arguments

```
#include <iostream>
using namespace std;

class Rectangle{
    public:
        int length;
        int breadth;
        int area(){
            return length * breadth;
        }
        int perimeter(){
            return 2 * (length + breadth);
        }
        void setLength(int l){
            length = l;
        }
        void setBreadth(int b){
            breadth = b;
        }
};

void initialize(Rectangle *r, int l, int b){
    r->setLength(l);
    r->setBreadth(b);
}

int main(){
    Rectangle r;
    initialize(&r, 100, 200);
    cout<<"Area = "<<r.area()<<endl;
    cout<<"Perimeter = "<<r.perimeter()<<endl;
}
```

### 9. Friend Functions

- A friend function is a function that is not a member of a class but has access to the class's private and protected members.

```
#include <iostream>
using namespace std;

class Rectangle{
    private:
        int length;
        int breadth;
    public:
        Rectangle(){}
        Rectangle(int l, int b){
            length = l;
            breadth = b;
        }
        int area(){
            return length * breadth;
        }
        int perimeter(){
            return 2 * (length + breadth);
        }
        int getLength(){
            return length;
        }
        int getBreadth(){
            return breadth;
        }
        void setLength(int l){
            length = l;
        }
        void setBreadth(int b){
            breadth = b;
        }
        ~Rectangle(){}
        friend void display(Rectangle r);
};


void display(Rectangle r){
    cout<<"Length = "<<r.length<<endl;
    cout<<"Breadth = "<<r.breadth<<endl;
}

int main(){
    Rectangle r(10,5);
    display(r);
}
```

### 10. Pointers to Members

```
#include <iostream>
using namespace std;

class Rectangle{
    private:
        int length;
        int breadth;
    public:
        Rectangle(){}
        Rectangle(int l, int b){
            length = l;
            breadth = b;
        }
        int area(){
            return length * breadth;
        }
        int perimeter(){
            return 2 * (length + breadth);
        }
        int getLength(){
            return length;
        }
        int getBreadth(){
            return breadth;
        }
        void setLength(int l){
            length = l;
        }
        void setBreadth(int b){
            breadth = b;
        }
        ~Rectangle(){}
};

int main(){
    Rectangle r(10,5);
    Rectangle *p = &r;
    cout<<"Area = "<<p->area()<<endl;
    cout<<"Perimeter = "<<p->perimeter()<<endl;
}
```
