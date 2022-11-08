#include <iostream>

using namespace std;

class DaySo
{
public:
    int *arr, size;

    DaySo()
    {
        this->arr = nullptr;
        this->size = 0;
    }

    DaySo(int *arr, int size)
    {
        this->size = size;
        this->arr = arr;
    }

    ~DaySo()
    {
        this->size = 0;
        if (this->arr != nullptr)
            delete this->arr;
    }

    void BubbleSort()
    {
        for (int i = 0; i < this->size - 1; i++)
            for (int j = 0; j < this->size - i - 1; j++)
                if (this->arr[j] > this->arr[j + 1])
                    swap(arr[j], arr[j + 1]);
    }

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

    void QuickSortExec(int arr[], int start, int end)
    {
        if (start >= end)
            return;
        int p = Partition(arr, start, end);
        QuickSortExec(arr, start, p - 1);
        QuickSortExec(arr, p + 1, end);
    }

    void QuickSort()
    {
        QuickSortExec(this->arr, 0, this->size);
    }

    void BinarySearch(int x)
    {
        int left = 0, right = size - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] == x)
            {
                cout << "Phan tu dang o vi tri thu: " << mid + 1 << endl;
            }
            else if (arr[mid] > x)
            {
                right = mid - 1;
            }
            else if (arr[mid] < x)
            {
                left = mid + 1;
            }
        }
        cout << "Khong tim thay phan tu nao" << endl;
    }

    void SequentialSearch(int x)
    {
        int position = -1;
        for (int i = 0; i < this->size; i++)
            if (x == arr[i])
            {
                position = i;
                break;
            }
        if (position == -1)
            cout << "Khong tim thay phan tu nao" << endl;
        else
            cout << "Phan tu dang o vi tri thu: " << position + 1 << endl;
    }

    void Display()
    {
        for (int i = 0; i < this->size; i++)
            cout << this->arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    int arr[] = {4, 3, 8, 12, 65, 34, 98, 23};
    int size = 8;
    DaySo ds = DaySo(arr, size);

    cout << "Day so ban dau: " << endl;
    ds.Display();

    ds.SequentialSearch(8);

    cout << "Day so sau khi sap xep: " << endl;
    ds.BubbleSort();
    ds.Display();
}
