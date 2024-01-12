# learn_c++


### 1. Sequence Containers in C++ STL
  
    1.1 vector
    - vector is a sequence container and also known as Dynamic Array or Array List.
    - Its size can grow and shrink dynamically, and no need to provide size at compile time.
    - It is a part of C++ STL (Standard Template Library).
    - Random access is fast
    - Insertion and deletion at the end is fast
    - Insertion and deletion at the middle is slow
```c++
    #include <iostream>
    #include <vector>
    using namespace std;

    int main(){
        vector<int> g1;
        for(int i=0;i<5;i++){
            g1.push_back(i);
        }

        for(int i=0;i<g1.size();i++){
            cout<<g1[i]<<" ";
        }
        cout<<endl;

        g1.pop_back();

        g1.insert(g1.begin(),5);

        vector<int> g2;
        for(int i=0;i<5;i++){
            g2.push_back(i*2);
        }

        g1.swap(g2);

        for(auto i=g1.begin();i!=g1.end();i++){
            cout<<*i<<" ";
        }
        return 0;
    }
```
    
    1.2 list
    - list is a sequence container and also known as Doubly Linked List.
    - Random access is Slow
    - Insertion and deletion at the middle is fast
    - Insertion and deletion at the fronts are fast

```c++

#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> g1;
    for(int i=0;i<5;i++){
        g1.push_back(i);
    }
    cout<<"List is: ";
    for(auto i=g1.begin();i!=g1.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    cout<<"Front: "<<g1.front()<<endl;
    cout<<"Back: "<<g1.back()<<endl;
    cout<<"Size: "<<g1.size()<<endl;
    cout<<"Max Size: "<<g1.max_size()<<endl;
    g1.reverse();
    cout<<"Reverse: ";
    for(auto i=g1.begin();i!=g1.end();i++){
        cout<<*i<<" ";
    }
    cout<<"Empty: "<<g1.empty()<<endl;
    cout<<"Pop Front: ";
    g1.pop_front();
    for(auto i=g1.begin();i!=g1.end();i++){
        cout<<*i<<" ";
    }

    return 0;
}
```
    
    1.3 deque
    - deque is a sequence container and also known as Double Ended Queue.
    - Random access is fast
    - Insertion and deletion at the ends are slow
    - Insertion and deletion at middle is slow

```c++
#include <iostream> 
#include <deque>
using namespace std;

int main(){
    deque<int> g1;
    for(int i=0;i<5;i++){
        g1.push_back(i);
    }
    cout<<g1.at(2)<<endl;
    cout<<g1[2]<<endl;
    cout<<g1.front()<<endl;
    cout<<g1.back()<<endl;
    cout<<g1.size()<<endl;
    cout<<g1.max_size()<<endl;
    cout<<g1.empty()<<endl;
    g1.pop_front();
    g1.pop_back();
    for(auto i=g1.begin();i!=g1.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    g1.insert(g1.begin(),5);
    g1.insert(g1.begin(),2,3);
    for(auto i=g1.begin();i!=g1.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    g1.erase(g1.begin(),g1.begin()+2);
    for(auto i=g1.begin();i!=g1.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
}
```

### 2. Associative Containers in C++ STL

    2.1 set
    - set is an associative container that contains a sorted set of unique objects of type Key.
    - It is usually implemented using Red-Black Tree.
    - Insertion, Removal, Search have logirathmic complexity.
    - If we want to store user defined data type in set then we will have to provide 
      compare function so that set can store them in sorted order.
    - We can pass the order of sorting while constructing set object.

```c++
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
    set<int> s;
    for(int i=0;i<5;i++){
        s.insert(i);
    }
    for(auto i=s.begin();i!=s.end();i++){
        cout<<*i<<" ";
    }

    set<int> s1(s.begin(),s.end());
    cout<<endl;
    for(auto i=s1.begin();i!=s1.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;

    set<int> s2(s1);
    cout<<endl;
    for(auto i=s2.begin();i!=s2.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;

    cout<<s2.size()<<endl;
    cout<<s2.max_size()<<endl;
    cout<<s2.empty()<<endl;
}
```

    2.2 multiset
    - multiset is an associative container that contains a sorted set of duplicate objects of type Key.


```c++
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){
    multiset<int> s;
    for(int i=0;i<5;i++){
        s.insert(i);
    }
    for(auto i=s.begin();i!=s.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    s.erase(1);
    for(auto i=s.begin();i!=s.end();i++){
        cout<<*i<<" ";
    }
    cout<<end

    multiset<int> s1(s.begin(),s.end());
    cout<<endl;
    for(auto i=s1.begin();i!=s1.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
}
````

    2.3 map
    - map is an associative container that store elements in key value combination.
    - Each element has a key value and a mapped value.
    - No two mapped values can have same key values.
    - All operations have logirathmic complexity.

```c++
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    map<int,string> m;
    m[1]="abc";
    m[5]="cdc";
    m[3]="efg";
    m.insert({4,"hij"});
    for(auto i=m.begin();i!=m.end();i++){
        cout<<i->first<<" "<<i->second<<endl;
    }   
    cout<<endl;
    map<int,string> m1(m.begin(),m.end());
    for(auto i=m1.begin();i!=m1.end();i++){
        cout<<i->first<<" "<<i->second<<endl;
    }
    cout<<endl;
    map<int,string> m2(m1);
    for(auto i=m2.begin();i!=m2.end();i++){
        cout<<i->first<<" "<<i->second<<endl;
    }
    cout<<endl;
    cout<<m2.size()<<endl;
    cout<<m2.max_size()<<endl;
    cout<<m2.empty()<<endl;
}
```

    2.4 multimap
    - multimap is an associative container that store elements in key value combination.
    - Each element has a key value and a mapped value.
    - Mapped values can repeat.
    - All operations have logirathmic complexity.

```c++
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    multimap<int,string> m;
    m.insert({1,"abc"});
    m.insert({5,"cdc"});
    m.insert({3,"efg"});
    m.insert({4,"hij"});
    m.insert({4,"hij"});
    for(auto i=m.begin();i!=m.end();i++){
        cout<<i->first<<" "<<i->second<<endl;
    }   
    cout<<endl;
    multimap<int,string> m1(m.begin(),m.end());
    for(auto i=m1.begin();i!=m1.end();i++){
        cout<<i->first<<" "<<i->second<<endl;
    }
    cout<<endl;
    multimap<int,string> m2(m1);
    for(auto i=m2.begin();i!=m2.end();i++){
        cout<<i->first<<" "<<i->second<<endl;
    }
    cout<<endl;
    cout<<m2.size()<<endl;
    cout<<m2.max_size()<<endl;
    cout<<m2.empty()<<endl;
}
```

### 3. Derived containers in C++ STL

    3.1 stack
    - stack is a container adaptor that gives the programmer the functionality of a stack - specifically, a LIFO (Last-In-First-Out) data structure.
    - The class template acts as a wrapper to the underlying container - only a specific set of functions is provided.
    - The stack pushes and pops the element from the back of the underlying container, known as the top of the stack.

```c++
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    stack<int>s1;
    for(int i=0;i<5;i++){
        s1.push(i);
    }
    cout<<s1.size()<<endl;
    cout<<s1.top()<<endl;
    s1.pop();
    cout<<s1.top()<<endl;
    stack<int>s2(s1);
    cout<<s2.size()<<endl;
}
````

    3.2 queue
    - queue is a container adaptor that gives the programmer the functionality of a queue - specifically, a FIFO (First-In-First-Out) data structure.
    - The class template acts as a wrapper to the underlying container - only a specific set of functions is provided.
    - The queue pushes the element from the back of the underlying container, known as the top of the queue.
    - The queue pops the element from the front of the underlying container, known as the top of the queue.

```c++
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
    queue<int>q1;
    for(int i=0;i<5;i++){
        q1.push(i);
    }
    cout<<q1.size()<<endl;
    cout<<q1.front()<<endl;
    cout<<q1.back()<<endl;
    q1.pop();
    cout<<q1.front()<<endl;
    queue<int>q2(q1);
    cout<<q2.size()<<endl;
}
```

3.3 priority_queue
- priority_queue is a container adaptor that provides constant time lookup of the largest (by default) element, at the expense of logarithmic insertion and extraction.

```c++
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
    priority_queue<int>q1;
    for(int i=0;i<5;i++){
        q1.push(i);
    }
    cout<<q1.size()<<endl;
    cout<<q1.top()<<endl;
    q1.pop();
    cout<<q1.top()<<endl;
    priority_queue<int>q2(q1);
    cout<<q2.size()<<endl;
}
```

### 4.Iterators in C++ STL

    4.1 iterator
    - Iterators are used to point at the memory addresses of STL containers.
    - They are primarily used in sequence of numbers, characters etc.
    - Iterators are the objects that can be pointed to a memory address.
    - The iterator object is initialized using the begin() function and then can be incremented to point to the next memory location.

```c++
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v={1,2,3,4,5};
    vector<int>::iterator it=v.begin();
    cout<<*it<<endl;
    it++;
    cout<<*it<<endl;
    it=v.end();
    cout<<*it<<endl;
    it=v.begin();
    cout<<*it<<endl;
    it=v.begin()+3;
    cout<<*it<<endl;
    it=v.begin()+4;
    cout<<*it<<endl;
    it=v.begin();
    cout<<*it<<endl;
}
```

    4.2 reverse_iterator
    - reverse_iterator is a special type of iterator which can be used to iterate in reverse order of a container.

```c++
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v={1,2,3,4,5};
    vector<int>::reverse_iterator it=v.rbegin();
    cout<<*it<<endl;
    it++;
    cout<<*it<<endl;
    it=v.rend();
    cout<<*it<<endl;
    it=v.rbegin();
    cout<<*it<<endl;
    it=v.rbegin()+3;
    cout<<*it<<endl;
    it=v.rbegin()+2;
    cout<<*it<<endl;
    it=v.rbegin();
    cout<<*it<<endl;
}
```