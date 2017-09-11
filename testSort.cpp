/*****************************************************************************/
/*! @file testSort.h
 * @brief Unit Test Quick sort and Bubble sort algorithm.
 *
 * @details to test all funtion in QuickSort class and BubbleSort class. 
 */
/*****************************************************************************/
#include "gtest/gtest.h"
#include "../BubbleSort.h"
#include "../QuickSort.h"

/*!
 * @brief The TestSort class is used to test all function in QuickSort class  
   * and BubbleSort class.
 *
 * Using macro to define test and apply test.
 *
 */

class TestSort : public ::testing::Test
{
public:
protected:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }
    Arrange<int> *s = new BubbleSort<int>();
    Arrange<char> *s_char = new QuickSort<char>();
};

/*!
 * @internal create two array. The first is arr and the second is arr_result. 
   * Then call function Sort of BubbleSort class and use EXPECT_EQ to compare 
   * two that array. 
 */

TEST_F(TestSort, TestSortBubbleInt_RESULT_OK)
{
    int arr[] = { 12, 7, 49, 21, 8, 35, 50 };
    int arr_result[] = { 7, 8, 12, 21, 35, 49, 50 };
    int length = sizeof(arr) / sizeof(arr[0]);
    s->Sort(arr, length);
    
    for(int i = 0; i <= length; i++)
    {
        EXPECT_EQ(arr[i], arr_result[i]);
    } 
}

/*!
 * @internal create two array. The first is arr and the second is arr_result. 
   * Then call function Sort of QuickSort class and use EXPECT_EQ to compare 
   * two that array. 
 */

TEST_F(TestSort, TestSortQuickChar_RESULT_OK)
{
    char arr_char[] = { 'a', 't', 'e', 'b', 'r' };
    char arr_char_result[] = {'a', 'b', 'e','r', 't'};
    int length = sizeof(arr_char) / sizeof(arr_char[0]);
    s_char->Sort(arr_char, length);
    
    for(int i = 0; i < length; i++)
    {
        EXPECT_EQ(arr_char[i], arr_char_result[i]);
    } 
}

// int main(int argc, char **argv){
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }