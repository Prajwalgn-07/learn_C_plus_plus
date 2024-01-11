# learn_c++


### 1. Class Templates

 ```c++
    #include <iostream>
    using namespace std;

    template <class T>
    class mypair {
        T a, b;
        public:
            mypair (T first, T second) {
                a = first;
                b = second;
            }
            T getmax(){
                int retval;
                retval = a > b ? a : b;
                return retval;
            }
    };

    mypair <T>::getmax() {
        int retval;
        retval = a > b ? a : b;
        return retval;
    }

    int main() {
        mypair <int> myobject(100, 75);
        cout << myobject.getmax();
        return 0;
    }
```

### 2. Class and Function Templates with Multiple Parameters

```c++
    #include <iostream>
    using namespace std;

    template <class T, class U>
    class mypair {
        T a;
        U b;
        public:
            mypair (T first, U second) {
                a = first;
                b = second;
            }
            T getmax();
            U getmin();
    };

    template <class T, class U>
    T mypair<T, U>::getmax() {
        T retval;
        retval = a > b ? a : b;
        return retval;
    }

    template <class T, class U>
    U mypair<T, U>::getmin() {
        U retval;
        retval = a < b ? a : b;
        return retval;
    }

    int main() {
        mypair <int, double> myobject(100, 75.5);
        cout << myobject.getmax() << endl;
        cout << myobject.getmin() << endl;
        return 0;
    }
```
### 3. Non-Type Template Arguments
    
```c++
    #include <iostream>
    using namespace std;

    template <class T, int N>
    class mysequence {
        T x;
        int y;
        public:
            void setmember(int t, T value){
                y = t;
                x = value;
            }
            T getmember(){
                return x;
            }
    };

    int main() {
        mysequence <int, 5> myints;
        mysequence <double, 5> myfloats;
        myints.setmember(0, 100);
        myfloats.setmember(3, 3.1416);
        cout << myints.getmember() << endl;
        cout << myfloats.getmember()<<endl;
    }
```

### 4. Exception Handling

```c++
    #include <iostream>
    using namespace std;

    int main() {
        try {
            throw 20;
        }
        catch (int e) {
            cout << "An exception occurred. Exception Nr. " << e << endl;
        }
        return 0;
    }
```
    4.1 Multiple catch blocks

```c++
    #include <iostream>
    using namespace std;

    int main() {
        try {
            throw 20;
        }
        catch (int e) {
            cout << "An exception occurred. Exception Nr. " << e << endl;
        }
        catch (char e) {
            cout << "An exception occurred. Exception Nr. " << e << endl;
        }
        catch (...) {
            cout << "Default Exception" << endl;
        }
        return 0;
    }
```

    4.2 Invoking functions that generate exceptions

```c++
    #include <iostream>
    using namespace std;

    double division(int a, int b) {
        if (b == 0) {
            throw "Division by zero condition!";
        }
        return (a / b);
    }

    int main(){
        try{
            cout << division(10, 0) << endl;
        }
        catch (const char* msg) {
            cerr << msg << endl;
        }
        return 0;
    }
```

    4.3 Handling all exceptions

```c++
    #include <iostream>
    using namespace std;

    void myfunc(int x){
        try {
        if (x == 0) throw x;
        if (x == 1) throw 'x';
        if (x == 2) throw 1.0;
        }
        catch (...) {
            cout << "Default Exception" << endl;
        }
    }

    int main() {
        myfunc(0);
        myfunc(1);
        myfunc(2);
        return 0;
    }
```

    4.4 Re-throwing exceptions

```c++
    #include <iostream>
    using namespace std;

    void myfunc(int x){
        try {
        if (x == 0) throw x;
        if (x == 1) throw 'x';
        if (x == 2) throw 1.0;
        }
        catch (...) {
            cout << "Default Exception" << endl;
            throw;
        }
    }

    int main() {
        try {
            myfunc(0);
        }
        catch (int x) {
            cout << "int exception" << endl;
        }
        catch (char x) {
            cout << "char exception" << endl;
        }
        catch (double x) {
            cout << "double exception" << endl;
        }
        return 0;
    }
```