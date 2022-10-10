#include <iostream>
#include <math.h>

using namespace std;

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
		Complex c;
		c._real = this->_real + b._real;
		c._virtual = this->_virtual + b._virtual;
		c.Output();
	}

	void Subtract(Complex b)
	{
		Complex c;
		c._real = this->_real - b._real;
		c._virtual = this->_virtual - b._virtual;
		c.Output();
	}

	void Multiply(Complex b)
	{
		Complex c;
		c._real = this->_real * b._real - this->_virtual * b._virtual;
		c._virtual = this->_real * b._virtual - this->_virtual * b._real;
		c.Output();
	}

	void Divide(Complex b)
	{
		Complex c;
		c._real = (this->_real * b._real + this->_virtual * b._virtual) / (pow(b._real, 2) + pow(b._virtual, 2));
		c._virtual = (this->_virtual * b._real - this->_real * b._virtual) / (pow(b._real, 2) + pow(b._virtual, 2));
		c.Output();
	}
};
