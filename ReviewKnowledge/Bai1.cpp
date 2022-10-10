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
	int ts;
	int ms;

public:
	Fraction()
	{
		this->ts = 0;
		this->ms = 0;
	}

	Fraction(int ts, int ms)
	{
		this->ts = ts;
		this->ms = ms;
	}

	void Input()
	{
		cout << "Tu so: ";
		cin >> ts;
		cout << "Mau so: ";
		cin >> ms;
		while (ms == 0)
		{
			cout << "Mau so phai khac 0";
			cout << "\nMau so: ";
			cin >> ms;
		};
	}

	void Output()
	{
		this->Reduce();
		if (this->ms < 0)
		{
			this->ts = this->ts * (-1);
			this->ms = this->ms * (-1);
			cout << "" << this->ts << "/" << this->ms << "" << endl;
		}
		else
			cout << "" << this->ts << "/" << this->ms << "" << endl;
	}

	/* Uoc chung lon nhat  */
	int GCD(int a, int b)
	{
		if (a % b == 0)
			return b;
		else
			return GCD(b, a % b);
	}

	void Reduce()
	{
		int gcd = this->GCD(this->ts, this->ms);
		this->ts = this->ts / gcd;
		this->ms = this->ms / gcd;
	}

	void Add(Fraction b)
	{
		Fraction c;
		c.ts = this->ts * b.ms + b.ts * this->ms;
		c.ms = this->ms * b.ms;
		cout << "Tong:" << endl;
		c.Output();
	}

	void Subtract(Fraction b)
	{
		Fraction c;
		c.ts = this->ts * b.ms - b.ts * this->ms;
		c.ms = this->ms * b.ms;
		cout << "Hieu: " << endl;
		c.Output();
	}

	void Multiply(Fraction b)
	{
		Fraction c;
		c.ts = this->ts * b.ts;
		c.ms = this->ms * b.ms;
		cout << "Tich: " << endl;
		c.Output();
	}

	void Divide(Fraction b)
	{
		Fraction c;
		c.ts = this->ts * b.ms;
		c.ms = this->ms * b.ts;
		cout << "Thuong: " << endl;
		c.Output();
	}
};

class Complex
{
private:
	int _virtual;
	int _real;

public:
	Complex()
	{
	}

	Complex(int _virtual, int _real)
	{
		this->_virtual = _virtual;
		this->_real = _real;
	}

	void Input()
	{
		cout << "Nhap phan thuc cua so phuc  ";
		cin >> this->_real;
		cout << "Nhap phan ao cua so phuc : ";
		cin >> this->_virtual;
	}

	void Output()
	{
		cout << "So phuc: " << this->_real << " + " << this->_virtual << "i" << endl;
	}

	void Add(Complex b)
	{
		int bReal = this->_real + b._real;
		int bVirtual = this->_virtual + b._virtual;
		cout << "Tong: " << bReal << " + " << bVirtual << endl;
	}
	
	void Subtract(Complex b)
	{
		int phanthuc = thuc - sp1.thuc;
		int phanao = ao - sp1.ao;
		cout << "Hieu: " << phanthuc << " + " << phanao << "i" << endl;
	}
	void Multiply(Complex b)
	{
		int phanthuc = (ao * sp1.ao) - (thuc * sp1.thuc);
		int phanao = (ao * sp1.thuc) + (sp1.ao * thuc);
		cout << "Tich: " << phanthuc << " + " << phanao << "i" << endl;
	}
	void Divide(Complex b)
	{
		int phanthuc = (ao * sp1.ao) + (thuc * sp1.thuc);
		int phanthuc1 = pow(sp1.ao, 2) + pow(sp1.thuc, 2);
		int phanao = (thuc * sp1.ao) - (ao * sp1.thuc);
		cout << "Thuong: " << phanthuc << "/" << phanthuc1 << " + " << phanao << "/" << phanthuc1 << "i" << endl;
	}
};

int main()
{
	// cout << "Bai 1:" << endl;
	// Point a;
	// a.Input();
	// a.Output();

	// cout << "Bai 2" << endl;
	// Point b;
	// b.Input();
	// b.Output();
	// cout << "Do dai doan thang: ";
	// cout << a.Distance(b) << endl;

	// cout << "Bai 3" << endl;
	// Contestant c1;
	// c1.Input();
	// c1.Output();
	// cout << c1.Total() << endl;

	// cout << "Bai 4" << endl;
	// Fraction fa;
	// Fraction fb;
	// fa.Input();
	// fb.Input();
	// fa.Output();
	// fb.Output();
	// fa.Add(fb);
	// fa.Subtract(fb);
	// fa.Multiply(fb);
	// fa.Divide(fb);

	cout << "Bai 5" << endl;
	return 0;
}