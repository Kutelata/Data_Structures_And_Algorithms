#include <iostream>
#include <math.h>

using namespace std;

void bubbleSort(int a[], int n){
    int i, j;
    for (i = (n-1); i >= 0; i--) {
        for (j = 1; j <= i; j++){
            if (a[j-1] > a[j])
            swap(a[j-1],a[j]);
        }
    }
}
void insertionSort(int a[], int array_size) {
    int i, j, k;
    for (i=1; i < array_size; i++) {
        k = a[i];
        j = i;
    while ((j > 0) && (a[j-1] > k)) {
        a[j] = a[j-1];
        j = j -1 ;
        }
        a[j] = k;
    }
}
void selectionSort(int a[], int n){
    int i, j, min, temp;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++){
            if (a[j] < a[min])
                min = j;
        }
        swap(a[i], a[min]);
    }
}
int main()
{
    int a[7]={1,5,4,6,12,24,10};
    int b[7]={2,3,5,4,9,44,20};
    int c[7]={4,6,1,48,15,68,50};
    insertionSort(a, 7);
    for(int i=0; i<7; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    selectionSort(b, 7);
    for(int i=0; i<7; i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    bubbleSort(c, 7);
    for(int i=0; i<7; i++)
    {
        cout<<c[i]<<" ";
    }
}
