#include<iostream>
#include "Engine.h"
#include "Wheels.h"
using namespace std;

int main(){
    Engine::Speed e(10);
    Wheels::Speed w(20);
    cout<< e.getValue()<<endl;
    cout<< w.getValue()<<endl;
    return 0;
}