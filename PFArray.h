/* 
 * File:   PFArray.h
 * Author: eray
 *
 * Created on 10 Kasım 2016 Perşembe, 12:24
 */

#ifndef PFARRAY_H
#define	PFARRAY_H

#include <iostream>
using namespace std;

class PFArray {
public:
    PFArray();
    PFArray(int theCapacity);
    PFArray(const PFArray& otherObj);
    PFArray(double *theV, int theUsed);
    
    int getCapacity()const;
    int getNumberUsed()const;
    
    void addElement(double element);
    
    PFArray& operator =(const PFArray& rtSide);
    PFArray& operator +=(const PFArray& rtSide);
    const PFArray operator +(const PFArray& other);
    double& operator [](int index); //lvalue
    const double& operator[](int index)const; // rvalue
    PFArray& operator++();

    bool Full();
    
    void emptyArray();
    void popBack();
    double* intersetion(const PFArray otherObj);
    
    friend ostream& operator<<(ostream& outS, const PFArray& other);

    static int liveArray();
    
    ~PFArray();
private:
    
    double *a;
    int capacity;
    int used;
    static int livingArray;
    
};

#endif	/* PFARRAY_H */

