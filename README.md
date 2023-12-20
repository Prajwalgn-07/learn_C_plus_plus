# learn_c++

### 1. Single Inheritance in c++

- In this type of inheritance, there is only one base class and one derived class.
- The derived class inherits all the properties of the base class.

```c++
#include<iostream>
using namespace std;

class Base{
    public:
        int a;
        void display(){
            cout<<"Display of Base "<<a<<endl;
        }
};

class Derived:public Base{
    public:
        void show(){
            cout<<"Display of Derived "<<a<<endl;
        }
};

int main(){
    Base b;
    b.a = 5;
    b.display();

    Derived d;
    d.a = 10;
    d.display();
    d.show();
    return 0;
}
```

### 2. Visibility Mode in Inheritance in c++

- Visibility mode is used to specify the visibility of the base class members in the derived class.
- There are three types of visibility modes in c++.
  - Private Visibility Mode
  - Protected Visibility Mode
  - Public Visibility Mode

#### 2.1. Private Visibility Mode

- In this mode, all the public members of the base class become private members of the derived class.
- All the protected members of the base class become private members of the derived class.
- The private members of the base class are not accessible in the derived class.

```c++
#include<iostream>
using namespace std;

class Base{
    public:
        int a;
    private:
        int b;
    protected:
        int c;
};

class Derived:private Base{
    public:
        void fun(){
            a = 10;
            c = 20;
            // b = 30; // Not allowed as b is private in base class
        }
};

int main(){
    Base b;
    Derived d;
    // d.a = 10; // Not allowed as a is private in derived class
    // d.b = 20; // Not allowed as b is private in derived class
    // d.c = 30; // Not allowed as c is private in derived class
    return 0;
}
```

#### 2.2. Protected Visibility Mode

- In this mode, all the public members of the base class become protected members of the derived class.
- All the protected members of the base class become protected members of the derived class.
- The private members of the base class are not accessible in the derived class.

```c++
#include<iostream>
using namespace std;

class Base{
    public:
        int a;
    private:
        int b;
    protected:
        int c;
};

class Derived:protected Base{
    public:
        void fun(){
            a = 10;
            c = 20;
            // b = 30; // Not allowed as b is private in base class
        }
};

int main(){
    Base b;
    Derived d;
    // d.a = 10; // Not allowed as a is protected in derived class
    // d.b = 20; // Not allowed as b is private in derived class
    // d.c = 30; // Not allowed as c is protected in derived class
    return 0;
}
```

#### 2.3. Public Visibility Mode

- In this mode, all the public members of the base class become public members of the derived class.
- All the protected members of the base class become protected members of the derived class.

```c++
#include<iostream>
using namespace std;

class Base{
    public:
        int a;
    private:
        int b;
    protected:
        int c;
};

class Derived:public Base{
    public:
        void fun(){
            a = 10;
            c = 20;
            // b = 30; // Not allowed as b is private in base class
        }
};


int main(){
    Base b;
    Derived d;
    d.a = 10;
    // d.b = 20; // Not allowed as b is private in derived class
    // d.c = 30; // Not allowed as c is protected in derived class
    return 0;
}
```

### 3. MultiLevel Inheritance in c++

- In this type of inheritance, there is one base class and multiple derived classes.
- The derived class inherits all the properties of the base class.

```c++
#include<iostream>
using namespace std;

class Base{
    public:
        int a;
        void display(){
            cout<<"Display of Base "<<a<<endl;
        }
};

class Derived:public Base{
    public:
        void show(){
            cout<<"Display of Derived "<<a<<endl;
        }
};

class Derived2:public Derived{
    public:
        void show2(){
            cout<<"Display of Derived2 "<<a<<endl;
        }
};

int main(){
    Base b;
    b.a = 5;
    b.display();

    Derived d;
    d.a = 10;
    d.display();
    d.show();

    Derived2 d2;
    d2.a = 15;
    d2.display();
    d2.show();
    d2.show2();
    return 0;
}
```

### 4. Multiple Inheritance in c++

- In this type of inheritance, there are multiple base classes and one derived class.
- The derived class inherits all the properties of the base classes.

```c++
#include<iostream>
using namespace std;

class Base1{
    public:
        int a;
        void display(){
            cout<<"Display of Base1 "<<a<<endl;
        }
};

class Base2{
    public:
        int b;
        void display(){
            cout<<"Display of Base2 "<<b<<endl;
        }
};

class Derived:public Base1, public Base2{
    public:
        void show(){
            cout<<"Display of Derived "<<a<<" "<<b<<endl;
        }
};

int main(){
    Derived d;
    d.a = 10;
    d.b = 20;
    d.display();
    d.Base1::display();
    d.Base2::display();
    d.show();
    return 0;
}
```

### 5. Ambiguity Problem in Multiple Inheritance in c++

- Ambiguity Problem is one of the problems in multiple inheritance in c++.
- In this problem, the compiler is not able to decide which base class function to call.

```c++

#include<iostream>
using namespace std;

class Base1{
    public:
        void greet(){
            cout<<"How are you?"<<endl;
        }
};

class Base2{
    public:
        void greet(){
            cout<<"Kaise ho?"<<endl;
        }
}

class Inherited: public Base1, public Base2{
    public:
        void greet(){
            Base1::greet();
        }
}

int main(){
    Inherited d;
    d.greet();
    return 0;
}
```

### 6. Ambiguity Resolution in single inheritance in c++

- Ambiguity Resolution is one of the problems in single inheritance in c++.

```c++
#include<iostream>
using namespace std;

class Base{
    public:
        void greet(){
            cout<<"How are you?"<<endl;
        }
};

class Derived: public Base{
    public:
        void greet(){
            Base::greet();
        }
}


int main(){
    Derived d;
    d.greet();
    d.Base::greet();
    d.Derived::greet();
    return 0;
}
```

### 7. Hierarchical Inheritance in c++

- Hierarchical Inheritance is one of the types of inheritance in c++.
- In this type of inheritance, there is one base class and multiple derived classes.

```c++
#include<iostream>
using namespace std;

class Base{
    public:
        int a;
        void display(){
            cout<<"Display of Base "<<a<<endl;
        }
};

class Derived:public Base{
    public:
        void show(){
            cout<<"Display of Derived "<<a<<endl;
        }
};

class Derived2:public Base{
    public:
        void show2(){
            cout<<"Display of Derived2 "<<a<<endl;
        }
};

int main(){
    Base b;
    b.a = 5;
    b.display();

    Derived d;
    d.a = 10;
    d.display();
    d.show();

    Derived2 d2;
    d2.a = 15;
    d2.display();
    d2.show2();
    return 0;
}
```

### 8. Hybrid Inheritance in c++

- Hybrid Inheritance is one of the types of inheritance in c++.

```c++
#include<iostream>
using namespace std;

class Base{
    public:
        int a;
        void display(){
            cout<<"Display of Base "<<a<<endl;
        }
};

class Derived:public Base{
    public:
        void show(){
            cout<<"Display of Derived "<<a<<endl;
        }
};

class Derived2:public Base{
    public:
        void show2(){
            cout<<"Display of Derived2 "<<a<<endl;
        }
};

class Derived3:public Derived, public Derived2{
    public:
        void show3(){
            cout<<"Display of Derived3 "<<a<<endl;
        }
};

int main(){
    Base b;
    b.a = 5;
    b.display();

    Derived d;
    d.a = 10;
    d.display();
    d.show();

    Derived2 d2;
    d2.a = 15;
    d2.display();
    d2.show2();

    Derived3 d3;
    d3.a = 20;
    d3.display();
    d3.show();
    d3.show2();
    d3.show3();
    return 0;
}
```

### 9. Constructor in Inheritance in c++

- Constructor in Inheritance is one of the concepts in inheritance in c++.
- The constructor of the base class is called first and then the constructor of the derived class is called.

```c++
#include<iostream>
using namespace std;

class Base{
    public:
        Base(){
            cout<<"Default Constructor of Base"<<endl;
        }
        Base(int x){
            cout<<"Parameterized Constructor of Base "<<x<<endl;
        }
};

class Derived:public Base{
    public:
        Derived(){
            cout<<"Default Constructor of Derived"<<endl;
        }
        Derived(int y){
            cout<<"Parameterized Constructor of Derived "<<y<<endl;
        }
        Derived(int x, int y):Base(x){
            cout<<"Parameterized Constructor of Derived "<<y<<endl;
        }
};

int main(){
    Derived d;
    Derived d2(5);
    Derived d3(5, 10);
    return 0;
}
```

### 10. Destructor in Inheritance in c++

- Destructor in Inheritance is one of the concepts in inheritance in c++.
- The destructor of the derived class is called first and then the destructor of the base class is called.

```c++
#include<iostream>
using namespace std;

class Base{
    public:
        Base(){
            cout<<"Default Constructor of Base"<<endl;
        }
        Base(int x){
            cout<<"Parameterized Constructor of Base "<<x<<endl;
        }
        ~Base(){
            cout<<"Destructor of Base"<<endl;
        }
};

class Derived:public Base{
    public:
        Derived(){
            cout<<"Default Constructor of Derived"<<endl;
        }
        Derived(int y){
            cout<<"Parameterized Constructor of Derived "<<y<<endl;
        }
        Derived(int x, int y):Base(x){
            cout<<"Parameterized Constructor of Derived "<<y<<endl;
        }
        ~Derived(){
            cout<<"Destructor of Derived"<<endl;
        }
};

int main(){
    Derived d;
    Derived d2(5);
    Derived d3(5, 10);
    return 0;
}
```

### 11. Order of Constructor and Destructor Call in Inheritance in c++

- Order of Constructor and Destructor Call in Inheritance is one of the concepts in inheritance in c++.
- The constructor of the base class is called first and then the constructor of the derived class is called.
- The destructor of the derived class is called first and then the destructor of the base class is called.

```c++
#include<iostream>
using namespace std;

class Base{
    public:
        Base(){
            cout<<"Default Constructor of Base"<<endl;
        }
        Base(int x){
            cout<<"Parameterized Constructor of Base "<<x<<endl;
        }
        ~Base(){
            cout<<"Destructor of Base"<<endl;
        }
};

class Derived:public Base{
    public:
        Derived(){
            cout<<"Default Constructor of Derived"<<endl;
        }
        Derived(int y){
            cout<<"Parameterized Constructor of Derived "<<y<<endl;
        }
        Derived(int x, int y):Base(x){
            cout<<"Parameterized Constructor of Derived "<<y<<endl;
        }
        ~Derived(){
            cout<<"Destructor of Derived"<<endl;
        }
};

int main(){
    Derived d;
    Derived d2(5);
    Derived d3(5, 10);
    return 0;
}
```

### 12. Virtual Base Class in c++

- Lets take an example, there is a Grandfather as a base class, Parent 1 and Pareant 2 as a common base class as Grandfather, and child class inheirts from both the parent classes.
- In this case, the child class will have two copies of the Grandfather class.
- To avoid this problem, we use virtual base class.
- In this case, the child class will have only one copy of the Grandfather class.

```c++
#include<iostream>
using namespace std;

class Grandfather{
    public:
        int a;
        Grandfather(){
            cout<<"Default Constructor of Grandfather"<<endl;
        }
};

class Parent1:virtual public Grandfather{
    public:
        Parent1(){
            cout<<"Default Constructor of Parent1"<<endl;
        }
};

class Parent2:virtual public Grandfather{
    public:
        Parent2(){
            cout<<"Default Constructor of Parent2"<<endl;
        }
};

class Child:public Parent1, public Parent2{
    public:
        Child(){
            cout<<"Default Constructor of Child"<<endl;
        }
};

int main(){
    Child c;
    Child c2(5);
    return 0;
}
```