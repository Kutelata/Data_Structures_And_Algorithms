#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Vector
{
private:
	int size;	  // bien luu do dai cua vector
	int capacity; // bien luu dung luong cua vector
	T *array;	  // tao con tro chua mang

	void expand(int newCapacity)
	{
		if (newCapacity <= size)
			return;

		T *old = array;				// old tro toi mang cu
		array = new T[newCapacity]; // array tro toi mang moi

		for (int i = 0; i < size; i++)
			array[i] = old[i]; // sao chep phan tu tu mang cu sang mang moi

		delete[] old;			// xoa mang cu
		capacity = newCapacity; // dat dung luong moi
	}

public:
	Vector(int initCapacity = 100)
	{
		size = 0;
		capacity = initCapacity;
		array = new T[capacity];
	}

	~Vector()
	{
		delete[] array;
	}

	Vector &operator=(Vector &rhs)
	{
		if (this != &rhs) // ngan can tu sao chep
		{
			delete[] array;			 // xoa mang hien tai
			size = rhs.size;		 // dat kich thuoc moi
			capacity = rhs.capacity; // dat dung luong moi
			array = new T[capacity]; // tao mang moi

			// Sao chep cac phan tu tu phai sang trai
			for (int i = 0; i < size; i++)
				array[i] = rhs.array[i];
		}

		return *this; // tra ve vector ve trai sau khi gan xong
	}

	int Size()
	{
		return size;
	}

	bool empty()
	{
		return (size == 0);
	}

	T &operator[](int index)
	{
		return array[index];
	}
	
	void push_back(T newElement)
	{
		// Gap doi dung luong neu vector day
		if (size == capacity)
			expand(2 * size);

		// Chen phan tu moi vao ngay sau phan tu cuoi cung
		array[size] = newElement;

		// Tang kich thuoc
		size++;
	}
	void popBack()
	{
		size--;
	}
	void insert(int pos, T newElement)
	{
		// Gap doi dung luong neu vector day
		if (size == capacity)
			expand(2 * size);

		// Dich cac phan tu sang phai de tao cho trong cho viec chen
		for (int i = size; i > pos; i--)
			array[i] = array[i - 1];

		// Dat phan tu moi vao vi tri chen
		array[pos] = newElement;

		// Tang kich thuoc
		size++;
	}
	void erase(int pos)
	{
		// Dich cac phan tu sang trai de lap day cho trong de lai do viec xoa
		for (int i = pos; i < size - 1; i++)
			array[i] = array[i + 1];

		// Giam kich thuoc
		size--;
	}
	void clear()
	{
		size = 0;
	}
};

class HocSinh
{
private:
	string HoTen, NgaySinh;
	int MSV, DiemDanh;

public:
	HocSinh() {}
	HocSinh(string hoTen, string ngaySinh, int Msv, int diemDanh)
	{
		HoTen = hoTen;
		NgaySinh = ngaySinh;
		MSV = Msv;
		DiemDanh = diemDanh;
	}
	~HocSinh() {}
	void nhap()
	{
		cout << "\nNhap ho ten: ";
		fflush(stdin);
		getline(cin, HoTen);
		cout << "Nhap nam sinh: ";
		fflush(stdin);
		getline(cin, NgaySinh);
		cout << "Nhap MSV: ";
		cin >> MSV;
		cout << "Nhap so Diem Danh: ";
		cin >> DiemDanh;
	}
	void xuat()
	{
		cout << "\nHo ten: " << HoTen;
		cout << "\nNgay Sinh: " << NgaySinh;
		cout << "\nMSV: " << MSV;
		cout << "\nDiem Danh: " << DiemDanh;
		cout << endl;
	}
	void getDiemDanh()
	{
		cout << DiemDanh;
	}
	void getMSV()
	{
		cout << MSV;
	}
};

int main()
{
	Vector<int> arrayTest;
	arrayTest.push_back(1);
	arrayTest.push_back(2);
	arrayTest.push_back(3);
	arrayTest.push_back(4);
	arrayTest.insert(1,4);
	arrayTest.popBack();
	arrayTest.popBack();

	int element = arrayTest[4];
	cout << element << endl;
	cout << arrayTest.Size();
	// Vector<HocSinh> vhs;
	// int n;
	// cout << "Nhap so hoc sinh: ";
	// cin >> n;
	// cout << "\nNhap thong tin hoc sinh: ";
	// for (int i = 0; i < n; i++)
	// {
	// 	HocSinh a;
	// 	cout << "\nNhap hoc sinh thu " << i + 1;
	// 	a.nhap();
	// 	vhs.push_back(a);
	// }
	// cout << "\nTong so hoc sinh " << vhs.Size();
	// HocSinh b;
	// b = vhs[0];
	// cout << "\nSo lan diem danh cua hoc sinh thu 1: ";
	// b.getDiemDanh();
	return 0;
}
