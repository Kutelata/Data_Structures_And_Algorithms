#include <iostream>
#include <fstream> // Thư viện hỗ trợ file.
using namespace std;

void DocFile(int *&a, int &n, ifstream &FileIn)
{
	n = 0; // Khởi tạo số lượng = 0.

	// Duyệt từ đầu tới cuối tập tin.
	while(!FileIn.eof())
	{
		int x;
		FileIn >> x;

		int *Temp;

		bool Check = false;
		if(n != 0)
		{
			Check = true;
			Temp = new int[n]; // Cấp phát bộ nhớ cần sử dụng.

			for(int i = 0; i < n; i++)
			{
				Temp[i] = a[i];
			}
		}
		n++;

		a = new int[n]; // Cấp phát lại bộ nhớ cho mảng a.
		for(int i = 0; i < n - 1; i++)
		{
			a[i] = Temp[i];
		}

		if(Check == true)
		{
			delete[] Temp; // Giải phóng bộ nhớ.
		}
		

		a[n - 1] = x;
	}
}

// Tìm kiếm xem phần tử x có nằm trong mảng hay không ? Trả về true nếu tìm thấy, ngược lại trả về false.
bool TimKiemTuanTuVetCan(int *a, int n, int x)
{
	for(int i = 0; i < n - 1; i++)
	{
		if(x == a[i])
		{
			return true;
		}
	}
	return false;
}

// Tìm kiếm xem phần tử x có nằm trong mảng hay không ? Trả về true nếu tìm thấy, ngược lại trả về false.
bool TimKiemTuanTuLinhCanh(int *a, int n, int x)
{
	for(int i = 0; ; i++)
	{
		if(x == a[i])
		{
			if(i != n - 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

// Tìm kiếm nhị phân. Trả về true nếu tìm thấy, ngược lại trả về false.
bool TimKiemNhiPhan(int *a, int n, int x)
{
	int Left = 0, Right = n - 1;
	while(Left <= Right)
	{
		int Mid = (Left + Right) / 2;
		if(x < a[Mid])
		{
			Right = Mid - 1;
		}
		else if(x > a[Mid])
		{
			Left = Mid + 1;
		}
		else
		{
			return true;
		}
	}
	return false;
}

int main()
{
	ifstream FileIn; // Khai báo file.
	FileIn.open("input.txt", ios_base::in); // Mở file để đọc dữ liệu.

	// Kiểm tra xem tập tin có tồn tại hay không ?
	if(!FileIn)
	{
		cout << "\nKhong tim thay tap tin input.txt !";
		system("pause");
		return 0; // Đóng chương trình lại.
	}

	int *a, n;

	DocFile(a, n, FileIn);

	bool Check = TimKiemNhiPhan(a, n - 1, a[n - 1]); //TimKiemTuanTuLinhCanh(a, n, a[n - 1]); //TimKiemTuanTuVetCan(a, n - 1, a[n - 1]);
	if(Check == true)
	{
		cout << "\nPhan tu " << a[n - 1] << " co ton tai trong mang !";
	}
	else
	{
		cout << "\nPhan tu " << a[n - 1] << " khong ton tai trong mang !";
	}

	FileIn.close(); // Đóng lại.

	system("pause");
}