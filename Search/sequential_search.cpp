#include <iostream>

using namespace std;

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