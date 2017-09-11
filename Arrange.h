/*****************************************************************************/
/*! @file Arrange.h
 * @brief Polymorphism with virtual keyword and class template.
 *
 * @details To create Polymorphism with virtual keyword and swap between the 
   * two number, alphabetical... . 
 */
/*****************************************************************************/

#ifndef _ARRANGE_H_
#define _ARRANGE_H_
#include <iostream>
/*!
 * @brief The Arrange class is used to create Polymorphism with virtual keyword and swap between the 
   * two number, alphabetical... . 
 *
 * Provide class template.
 * Provide Polymorphism with virtual keyword.
 *
 */
template <class T> 
class Arrange {
public:
    /*!
     * @brief function Sort
     *
     * The function to create polymorphism with virtual keyword .
     *
     * @param[in] array and length of this array.
     * 
     */
    virtual void Sort(T *arr, int n) = 0;
    /*!
     * @brief function Sort
     *
     * The function to swap between two number, alphabetical... .
     *
     * @param[in] two number, alphabetical....
     * 
     */
    void Swap(T &x, T &y);
};

/*!
 * @internal using teamplate and then swap between two number, alphabetical...
 * 
 */
template <class T>
void Arrange<T>::Swap(T &x, T &y){
    int t = x;
    x = y;
    y = t;
}
#endif