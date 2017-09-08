#ifndef _ARRANGE_H_
#define _ARRANGE_H_

#include <iostream>

template <class T> 
class Arrange {
public:
    virtual void Sort(T *arr, int n) = 0;
    void Swap(T &x, T &y);
};


template <class T>
void Arrange<T>::Swap(T &x, T &y){
    int t = x;
    x = y;
    y = t;
}
#endif