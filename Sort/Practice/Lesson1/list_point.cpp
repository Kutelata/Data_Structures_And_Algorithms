#include "point.cpp"

class ListPoint
{
public:
    Point *p;
    int n;

    ListPoint()
    {
        this->p = nullptr;
        this->n = 0;
    }

    ListPoint(Point *p, int n)
    {
        this->p = p;
        this->n = n;
    }

    ~ListPoint()
    {
        n = 0;
        if (p != nullptr)
        {
            delete p;
        }
    }

    void input()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> this->p[i];
        }
    }

    void output()
    {
        for (int i = 0; i < n; i++)
        {
            cout << p[i];
        }
    }
};