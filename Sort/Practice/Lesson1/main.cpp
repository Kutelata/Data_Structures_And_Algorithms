#include <iostream>

using namespace std;

class Point
{
public:
    int x, y;

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

    ~Point()
    {
        this->x = 0;
        this->y = 0;
    }

    friend istream &operator>>(istream &is, Point &p)
    {
        is >> p.x;
        is >> p.y;
        return is;
    }

    friend ostream &operator<<(ostream &os, Point &p)
    {
        os << p.x << " " << p.y << endl;
        return os;
    }
};

class ListPoint
{
public:
    Point *p;

    ListPoint()
    {
        this->p = nullptr;
    }

    ListPoint(int n)
    {
        this->p = new Point[n];
    }

    ~ListPoint()
    {
        if (p != nullptr)
        {
            delete p;
        }
    }

    void Input(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> this->p[i];
        }
    }

    void Output(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << this->p[i];
        }
    }

    void InsertionSort(int n)
    {
        int i, currX, currY, j;
        for (i = 1; i < n; i++)
        {
            currX = this->p[i].x;
            currY = this->p[i].y;
            j = i - 1;
            while (j >= 0 && this->p[j].x > currX)
            {
                this->p[j + 1] = this->p[j];
                j = j - 1;
            }
            this->p[j + 1].x = currX;
            this->p[j + 1].y = currY;
        }
    }
};

int main(int argc, char const *argv[])
{
    int size;
    cin >> size;
    ListPoint lp(size);
    lp.Input(size);
    lp.InsertionSort(size);
    lp.Output(size);
    return 0;
}