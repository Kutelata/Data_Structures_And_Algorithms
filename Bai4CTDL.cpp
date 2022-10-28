#include <iostream>
using namespace std;

class DIEM
{
	int x, y;

public:
	friend istream &operator>>(istream &is, DIEM &d)
	{
		cout << "Nhap hoanh do x = ";
		is >> d.x;
		cout << "Nhap tung do y = ";
		is >> d.y;
		return is;
	}
	friend ostream &operator<<(ostream &os, DIEM d)
	{
		os << "(" << d.x << "," << d.y << ")";
		return os;
	}
	float getX()
	{
		return x;
	}
	float getY()
	{
		return y;
	}
	void setX(float temp)
	{
		x = temp;
	}
};

class DAYDIEM
{
	DIEM *arr;

public:
	DAYDIEM();
	DAYDIEM(int n)
	{
		arr = new DIEM[n];
	}
	void nhap(int n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
	}
	void insertionSort(int n)
	{
		int i, key, j;
		for (i = 1; i < n; i++)
		{
			key = arr[i].getX();
			j = i - 1;
			while (j >= 0 && arr[j].getX() > key)
			{
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			arr[j + 1].setX(key);
		}
	}
	void xuat(int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i];
		}
	}
};
int main()
{
	int n;
	cout << "Nhap so phan tu cua day n = ";
	cin >> n;
	DAYDIEM arr(n);
	arr.nhap(n);
	arr.insertionSort(n);
	arr.xuat(n);
}
