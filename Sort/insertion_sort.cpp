#include <iostream>

using namespace std;

void InsertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // Đẩy các phần tử lớn hơn key ra đằng sau
            j = j - 1;
        }
        arr[j + 1] = key; // Chèn vào vị trí arr[j] < key
    }
}