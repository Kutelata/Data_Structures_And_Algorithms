#include <iostream>
#include <vector>
#include <math.h>
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

const int P = 1e6 + 3;

struct HashTable {
    vector< pair<int,int> > h[P];

public:
    void insert(int key, int value) {
        int hkey = getHash(key);
        for (auto p : h[hkey]) {
            if (p.first == key) {
                // key da ton tai trong Hash table, ta bo qua
                return;
            }
        }
        // Them (key, value) vao hash table
        h[hkey].emplace_back(key, value);
    }

    int find(int key) {
        int hkey = getHash(key);
        for(auto p : h[hkey]) {
            if (p.first == key) {
                // ton tai key trong Hash table, return value
                return p.second;
            }
        }
        // Khong tim thay
        return 0;
    }

private:
    int getHash(int key) {
        // Cho 1 key, tra lai Hash value la key % P
        return key % P;
    }
};

int main()
{
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int b[10] = {0, 2, 1, 5, 3, 4, 6, 9, 8, 7};
	// vector<pair<int, int>> h[P];
	// insert(456, 1527394, h);
	// cout << find(456,h) << endl;

	cout << BinarySearch(a, 10, 3) << endl;
	cout << SequentialSearch(b, 10, 9) << endl;

	// HashTable ht;
	// ht.insert(456,1527394);
	// ht.insert(123,7532453);
	// ht.insert(321,8637439);
	// ht.insert(478,5142783);
	// ht.insert(999,6242582);

	// cout << ht.find(123) << endl;
	return 0;
}