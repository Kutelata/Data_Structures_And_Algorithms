#include <iostream>
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