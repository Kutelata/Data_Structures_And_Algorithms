#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Array
{
private:
    int *a, n;

public:
    int BinarySearch(int x)
    {
        // Quicksort()
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (a[mid] == x)
            {
                return mid;
            }
            else if (a[mid] > x)
            {
                right = mid - 1;
            }
            else if (a[mid] < x)
            {
                left = mid + 1;
            }
        }
        return -1;
    }

    int SequentialSearch(int x)
    {
        for (int i = 0; i < n; i++)
        {
            if (x == a[i])
            {
                return i;
            }
        }
        return -1;
    }

    // PT khoi dung mac dinh
    Array()
    {
        n = 0;
        a = NULL;
    }

    // PT khoi dung co tham so
    Array(int *a, int n1 = 0)
    {
        n = n1;
        a = new int[n + 1];
    }

    ~Array()
    {
        n = 0;
        if (a != NULL)
            delete a;
    }
    
    // PT nhap
    void input()
    {
        int i;
        cout << "\nNhap so phan tu n = ";
        cin >> n;
        cout << "\nNhap cac phan tu cua mang\n";
        this->a = new int[n];
        for (i = 0; i < n; i++)
        {
            cout << "a[" << i + 1 << "]= ";
            cin >> a[i];
        }
    }

    // PT hien thi
    void display()
    {
        int i;
        for (i = 0; i < n; i++)
            cout << a[i] << " ";
    }
    
    // PT doi cho
    void swap(int *x, int *y)
    {
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
    }

    // PT chon key
    int getkeyposition(int i, int j)
    {
        return (i + j) / 2;
    }

    // PT Quicksort
    void Quicksort1(int *a, int m, int n)
    {
        int key, i, j, k;
        if (m < n)
        {
            k = getkeyposition(m, n);
            swap(&a[m], &a[k]);
            key = a[m];
            i = m + 1;
            j = n;
            while (i <= j)
            {
                while (i <= n && a[i] <= key)
                    i++;
                while (j >= m && a[j] > key)
                    j--;
                if (i < j)
                    swap(&a[i], &a[j]);
            }
            swap(&a[m], &a[j]);
            Quicksort1(a, m, j - 1);
            Quicksort1(a, j + 1, n);
        }
    }

    void Quicksort()
    {
        Quicksort1(a, 0, n - 1);
    }
};
//==========================================================================
class Array1 : Array
{
};
//==========================================================================
int main()
{
    //    clrscr();
    Array Q;
    Q.input();
    cout << "\nMang vua nhap la:\n";
    Q.display();
    cout << "\nMang sau khi sap xep giam la:\n";
    Q.Quicksort();
    Q.display();
    cout << "\nTim kiem nhi phan:\n";
    if(Q.BinarySearch(3) == -1){
        cout << "\nKhong tim thay";
    }else{
        cout << Q.BinarySearch(3);
    };
    cout << "\nTim kiem tuan tu:\n";
    if(Q.SequentialSearch(3) == -1){
        cout << "\nKhong tim thay";
    }else{
        cout << Q.SequentialSearch(3);
    };
    getch();
    return 0;
}
