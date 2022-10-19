#include <iostream>

using namespace std;

// Mảng phải được sắp xếp rồi
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