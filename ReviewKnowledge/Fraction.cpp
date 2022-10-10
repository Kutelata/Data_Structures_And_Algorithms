#include <iostream>

using namespace std;

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