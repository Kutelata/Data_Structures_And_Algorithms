#include "point.cpp"
#include "contestant.cpp"
#include "fraction.cpp"
#include "complex.cpp"

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
	Fraction fa;
	Fraction fb;
	fa.Input();
	fb.Input();
	fa.Output();
	fb.Output();
	fa.Add(fb);
	fa.Subtract(fb);
	fa.Multiply(fb);
	fa.Divide(fb);

	cout << "Bai 5" << endl;
	Complex ca;
	Complex cb;
	ca.Input();
	cb.Input();
	ca.Output();
	cb.Output();
	ca.Add(cb);
	ca.Subtract(cb);
	ca.Multiply(cb);
	ca.Divide(cb);
	return 0;
}