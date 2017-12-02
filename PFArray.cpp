/* 
 * File:   PFArray.cpp
 * Author: eray
 * 
 * Created on 10 Kasım 2016 Perşembe, 12:24
 */

#include "PFArray.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int PFArray::livingArray = 0;

PFArray::PFArray():capacity(50), used(0) {
    
    livingArray++;
    a = new double[capacity];
}

PFArray::PFArray(int theCapacity): capacity(theCapacity), used(0)
{
    livingArray++;
    a = new double[capacity];
}

PFArray::PFArray(double *theV, int theUsed): capacity(50)
{
    used = theUsed;
    a = new double[capacity];
    livingArray++;

    for(int i=0; i< used; i++)
        a[i] = theV[i];
}

PFArray::PFArray(const PFArray& otherObj) {
    
    capacity = otherObj.capacity;
    used = otherObj.used;
    a = new double[capacity];
    livingArray++;
    for(int i=0; i<used; i++)
        a[i] = otherObj.a[i];
}

PFArray::~PFArray() {
    livingArray--;
    delete [] a;
}

int PFArray::liveArray()
{
    return livingArray;
}


PFArray& PFArray::operator =(const PFArray& rtSide){
    
    if(this == &rtSide)
        return *this;
    else
    {
        capacity = rtSide.capacity;
        used = rtSide.used;
        delete [] a;
        
        a = new double[capacity];
        for(int i=0; i<used; i++)
            a[i] = rtSide.a[i];
        return *this;
    }
}

bool PFArray::Full()
{
    return used == capacity;
}

const PFArray PFArray::operator+(const PFArray& other)
{
    double *temp = new double[capacity];

    for(int i=0; i<used; i++)
        temp[i] = a[i] + other.a[i];

    return PFArray(temp,used);
}

PFArray& PFArray::operator++()
{   
    int j=0;
    double *temp = new double[capacity];
    for(int i=0; i<used; i++){
        j++;
        temp[i] = a[j];
    }
    delete [] a;

    a = temp;

    return *this;
}

void PFArray::addElement(double element) {
    
    if(used >= capacity)
    {
        double *temp = new double[capacity*2];
        
        for(int i=0; i< capacity; i++)
            temp[i] = a[i];
        
        delete [] a;
        a = temp;
    }
    
    a[used] = element;
    used++;
}

PFArray& PFArray::operator+=(const PFArray& rtSide)
{
    for(int i=0; i<used; i++)
        a[i] += rtSide.a[i];

    return *this;
}

void PFArray::popBack()
{
    used--;
}

double* PFArray::intersetion(const PFArray otherObj)
{
    int i=0, j=0, k=0;
    double *temp = new double[capacity];

        for(int i=0; i<getNumberUsed(); i++)
        {
            for(int j=0; j<getNumberUsed(); j++)
            {
                if(a[i] == otherObj.a[j])
                {
                    temp[k] = a[i];
                    k++;
                }
            }
        }
    
    return temp;
}

double& PFArray::operator[](int index) {
    
    if(index > used)
    {
        cout<<"illegeal index"<<endl;
        exit(1);
    }
    return a[index];
}

const double& PFArray::operator[](int index)const {
    
    if(index > used)
    {
        cout<<"illegeal index"<<endl;
        exit(1);
    }
    return a[index];
}

void PFArray::emptyArray() {
    
    used =0;
}

int PFArray::getCapacity() const {
    return capacity;
}

int PFArray::getNumberUsed() const {
    return used;
}


ostream& operator<<(ostream& outS, const PFArray& other) {
    
    for(int i=0; i<other.getNumberUsed(); i++)
        outS<<other.a[i]<<" ";
    outS<<endl;

    return outS;
}

