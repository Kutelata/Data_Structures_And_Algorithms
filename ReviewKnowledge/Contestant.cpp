#include <iostream>

using namespace std;

class Contestant
{
	int sbd;
	string hoTen;
	int namSinh;
	string gioiTinh;
	float dt;
	float dl;
	float dh;

public:
	Contestant()
	{
		this->sbd = 0;
		this->hoTen = "";
		this->namSinh = 0;
		this->gioiTinh = "";
		this->dt = 0;
		this->dl = 0;
		this->dh = 0;
	}

	Contestant(int sbd, string hoTen, string gioiTinh, float dt, float dl, float dh)
	{
		this->sbd = sbd;
		this->hoTen = hoTen;
		this->gioiTinh = gioiTinh;
		this->dt = dt;
		this->dl = dl;
		this->dh = dh;
	}

	void Input()
	{
		cout << "Nhap sbd: ";
		cin >> sbd;
		cout << "Nhap ho ten: ";
		cin.ignore();
		getline(cin, hoTen);
		cout << "Nhap nam sinh: ";
		cin >> namSinh;
		cout << "Nhap gioi tinh: ";
		cin.ignore();
		getline(cin, gioiTinh);
		cout << "Nhap diem toan: ";
		cin >> dt;
		cout << "Nhap diem ly: ";
		cin >> dl;
		cout << "Nhap diem hoa: ";
		cin >> dh;
	}

	void Output()
	{
		cout << "sbd: " << sbd << endl;
		cout << "Ho ten: " << hoTen << endl;
		cout << "Nam sinh: " << namSinh << endl;
		cout << "Gioi tinh: " << gioiTinh << endl;
		cout << "Toan: " << dt << endl;
		cout << "Ly: " << dl << endl;
		cout << "Hoa: " << dh << endl;
	}

	float Total()
	{
		float total = dt + dl + dh;
		return total;
	}
};