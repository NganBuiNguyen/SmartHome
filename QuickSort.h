#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_
#include "Arrange.h"
#include <iostream>

template <class T>
class QuickSort : public Arrange<T>
{
    public:
        // QuickSort(void);
        // ~QuickSort(void);
        int partition (T arr[], int low, int high);
        void quickSort(T arr[], int low, int high);
        void Sort(T *arr, int n);      
};
#endif

template <class T>
int QuickSort<T>::partition (T arr[], int low, int high)
{
    int pivot = arr[high];    
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {
        
        if (arr[j] <= pivot)
        {
            i++;    
            this->Swap(arr[i], arr[j]);
        }
    }
    this->Swap(arr[i + 1], arr[high]);
    return (i + 1);
}

template <class T>
void QuickSort<T>::quickSort(T arr[], int low, int high)
{
    if (low < high)
    {
        
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
template <class T>
void QuickSort<T>::Sort(T arr[], int n)
{
	std::cout<<"Here is QuickSort" << std::endl;
    quickSort(arr, 0, n-1);
    for (int i = 0; i<= n-1; i++)
    {
        std::cout<< arr[i] << std::endl;
        // printf("%i,", arr1[i]);
    }
}