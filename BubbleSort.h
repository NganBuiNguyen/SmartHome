#ifndef _BUBBLESORT_H_
#define _BUBBLESORT_H_
#include "Arrange.h"
#include <iostream>

template <class T>
class BubbleSort : public Arrange<T>
{
    public:
        // BubbleSort(void);
        // ~BubbleSort(void);
        void Sort(T *arr, int n);
};
#endif

template <class T>
void BubbleSort<T>::Sort(T *arr, int n){
    std::cout<<"Here is BubbleSort"<< std::endl;
    for (int i = n-1; i >= 1; i--)
    {
        for(int j =1; j <= (i-1); j++)
        {
            if (arr[j-1] > arr[j])
            {
                this->Swap(arr[j], arr[j - 1]);
            }
        }
    }
    for (int i = 0; i<= n-1; i++)
    {
        std::cout<< arr[i] << std::endl;
    }
}
