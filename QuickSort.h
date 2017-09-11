/*****************************************************************************/
/*! @file QuickSort.h
 * @brief Implement Quick sort algorithm.
 *
 * @details To arrange number, alphabetical... bellow Quick sort algorithm. 
 */
/*****************************************************************************/
#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_
#include "Arrange.h"
#include <iostream>

/*!
 * @brief The QuickSort class is used to arrange number, alphabetical... 
   * bellow Quick sort algorithm.
 *
 * Provide class template.
 * Provide Polymorphism with virtual keyword.
 *
 */

template <class T>
class QuickSort : public Arrange<T>
{
    public:
        /*!
         * @brief function partition
         *
         * The function will find number, alphabetical... and take it to swap 
           * between two number, alphabetical....
         * 
         * @param[in] array , first position and last position.
         * 
         */
        int partition (T arr[], int low, int high);
        /*!
         * @brief function quickSort. This is recursion function.
         *
         * The function will recur quickSort funtion.
         * 
         * @param[in] array , first position and last position.
         * 
         */
        void quickSort(T arr[], int low, int high);
        /*!
         * @brief function Sort
         *
         * The function will call quickSort function and print result.
         * Polymorphism from Arrange class.
         * @param[in] array and length of this array.
         * 
         */
        void Sort(T *arr, int n);      
};
#endif

/*!
 * @internal using teamplate, find number, alphabetical... and take it to swap 
   * between two number, alphabetical...
 * 
 */

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

/*!
 * @internal recur quickSort funtion.
 * 
 */

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

/*!
 * @internal use teamplate, call quickSort function and print result.
 * 
 */
template <class T>
void QuickSort<T>::Sort(T arr[], int n)
{
    // std::cout<<"Here is QuickSort" << std::endl;
    quickSort(arr, 0, n-1);
    // for (int i = 0; i<= n-1; i++)
    // {
    //     std::cout<< arr[i] << std::endl;
    // }
}