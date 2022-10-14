#include <iostream>
using namespace std;

// int find(int key)
// {
// 	int hKey = getHash(key);
// 	for (auto p : h[hKey])
// 	{
// 		if (p.first == key)
// 		{
// 			return p.value;
// 		}
// 	}
// 	return 0;
// }

// int getHash(int key)
// {
// 	return key % P;
// }

int SequentialSearch(int *a, int n, int x)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (x == a[i])
		{
			return i;
		}
	}
	return -1;
}

int BinarySearch(int *a, int n, int x)
{
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

int main()
{
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << BinarySearch(a, 10, 12);
	return 0;
}