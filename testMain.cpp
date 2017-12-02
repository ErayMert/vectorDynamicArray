/* 
 * File:   main.cpp
 * Author: eray
 *
 * Created on 10 Kasım 2016 Perşembe, 12:23
 */

#include <cstdlib>

#include "PFArray.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArray temp(cap), temp2(cap), temp1(cap);
    
    cout << "Enter up to " << cap << " nonnegative numbers.\n";
    cout << "Place a negative number at the end.\n";

    double next;
    cin>>next;
    while ((next >= 0) && (!temp.Full())) {
        temp.addElement(next);
        cin>>next;
    }
    
    cout << "Enter up to " << cap << " nonnegative numbers.\n";
    cout << "Place a negative number at the end.\n";
    
    double x;
    cin>>x;
    while ((x >= 0) && (!temp2.Full())) {
        temp2.addElement(x);
        cin>>x;
    }

    cout<<"livingVector: "<< PFArray::liveArray()<<endl;

    temp += temp2;

    cout<<temp;

    temp.popBack();

    cout<<"popBack: "<<temp;

    temp1 = temp+ temp2;

    cout<< "add: "<<temp1;

    
    /*double *b = new double(cap);
    
    b = temp.intersetion(temp2);
    
    for(int i=0; i<cap; i++ )
    {
        if( b[i] != 0)
            cout<<b[i]<<" ";
    }*/
    
   
    return 0;
}

