#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

class Point
{
	int x;
	int y;

public:
	Point()
	{
		this->x = 0;
		this->y = 0;
	}

	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	void Input()
	{
		cout << "Nhap x: ";
		cin >> x;
		cout << "Nhap y: ";
		cin >> y;
	}

	void Output()
	{
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}

	float Distance(Point p)
	{
		float distance;
		distance = sqrt(pow(this->x - p.x, 2) + pow(this->y - p.y, 2));
		return distance;
	}
};

class Contestant
{
	int sbd;
	string hoTen;
	int namSinh;
	string gioiTinh;
	float dt;
	float dl;
	float dh;
	// Point p;

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
		// this->p = Point(0, 0);
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

class Fraction
{
private:
	float ts;
	float ms;

public:
	Fraction()
	{
		this->ts = 0;
		this->ms = 0;
	}

	Fraction(float ts, float ms)
	{
		this->ts = ts;
		this->ms = ms;
	}

};

int main()
{
	cout << "Bai 1:" << endl;
	Point a;
	a.Input();
	a.Output();

	cout << "Bai 2" << endl;
	Point b;
	b.Input();
	b.Output();
	cout << "Do dai doan thang: ";
	cout << a.Distance(b) << endl;

	cout << "Bai 3" << endl;
	Contestant c1;
	c1.Input();
	c1.Output();
	cout << c1.Total() << endl;

	cout << "Bai 4" << endl;

	cout << "Bai 5" << endl;
	return 0;
}