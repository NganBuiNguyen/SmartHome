#include "QuickSort.h"
#include "BubbleSort.h"

int main ()
{
    int arr[] = { 12, 7, 49, 21, 8, 35, 50 };
    char arr1[] = { 'h', 'a', 'e', 'g' };
   
    Arrange<int> *s = new QuickSort<int>();
    int length = sizeof(arr) / sizeof(arr[0]);
    s->Sort(arr, length);

    Arrange<char> *st = new BubbleSort<char>();
    int length2 = sizeof(arr1) / sizeof(arr1[0]);
    st->Sort(arr1, length2);

    return 0;
}