#include <iostream>

using namespace std;

#define MAX 1000

class Stack
{
public:
    int top;
    int a[MAX];

    Stack()
    {
        top = -1;
    }

    bool Push(int x)
    {
        if (top >= (MAX - 1))
        {
            cout << "Stack Overflow";
            return false;
        }
        else
        {
            a[++top] = x;
            cout << x << " pushed into stack\n";
            return true;
        }
    }

    bool Pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow";
            return 0;
        }
        else
        {
            int x = a[top--];
            return x;
        }
    }

    int Peek()
    {
        if (top < 0)
        {
            cout << "Stack is Empty";
            return 0;
        }
        else
        {
            int x = a[top];
            return x;
        }
    }

    bool IsEmpty()
    {
        return (top < 0);
    }
};

int main()
{
    Stack s;
    s.Push(10);
    s.Push(20);
    s.Push(30);
    cout << s.Pop() << " Popped from stack\n";

    cout << "Top element is : " << s.Peek() << endl;

    cout << "Elements present in stack : ";
    while (!s.IsEmpty())
    {
        cout << s.Peek() << " ";
        s.Pop();
    }
    return 0;
}