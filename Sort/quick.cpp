#include <iostream>

using namespace std;

int Partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void QuickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int p = Partition(arr, start, end);
    QuickSort(arr, start, p - 1);
    QuickSort(arr, p + 1, end);
}

void QuicksortV2(int arr[], int start, int end)
{
    int pivot, i, j, mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        swap(arr[start], arr[mid]);
        pivot = arr[start];
        i = start + 1;
        j = end;
        while (i <= j)
        {
            while (i <= end && arr[i] <= pivot)
                i++;
            while (j >= start && arr[j] > pivot)
                j--;
            if (i < j)
                swap(arr[i], arr[j]);
        }
        swap(arr[start], arr[j]);
        QuicksortV2(arr, start, j - 1);
        QuicksortV2(arr, j + 1, end);
    }
}