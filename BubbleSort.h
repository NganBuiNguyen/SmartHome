/*****************************************************************************/
/*! @file BubbleSort.h
 * @brief Implement Bubble sort algorithm.
 *
 * @details To arrange number, alphabetical... bellow Bubble sort algorithm. 
 */
/*****************************************************************************/

#ifndef _BUBBLESORT_H_
#define _BUBBLESORT_H_
#include "Arrange.h"
#include <iostream>
/*!
 * @brief The BubbleSort class is used to arrange number, alphabetical... 
   * bellow Bubble sort algorithm.
 *
 * Provide class template.
 * Provide Polymorphism with virtual keyword.
 *
 */

template <class T>
class BubbleSort : public Arrange<T>
{
    public:
        /*!
         * @brief Constructor
         */
        // BubbleSort(void);
        /*!
         * @brief Destructor of class, reset member value to zero
         */
        // ~BubbleSort(void);
        /*!
         * @brief function Sort
         *
         * The function will take number, alphabetical... and arrange with  
           * another number, alphabetical... in array.
         * Polymorphism from Arrange class.
         * @param[in] array and length of this array.
         * 
         */
        void Sort(T *arr, int n);
};
#endif

/*!
 * @internal using teamplate, arrange number, alphabetical... 
   * bellow Bubble sort algorithm and then print the result.
 * 
 */

template <class T>
void BubbleSort<T>::Sort(T *arr, int n){
    // std::cout<<"Here is BubbleSort"<< std::endl;
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
    // for (int i = 0; i<= n-1; i++)
    // {
    //     std::cout<< arr[i] << std::endl;
    // }
}
