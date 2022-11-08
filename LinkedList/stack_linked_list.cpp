#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class StackLinkedList
{
public:
    Node *top;

    StackLinkedList()
    {
        top = nullptr;
    }

    void Push(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        if (top != nullptr)
        {
            newNode->next = top;
            top = newNode;
        }
        else
        {
            newNode->next = nullptr;
            top = newNode;
        }
    }

    int Pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty";
            return -1;
        }
        else
        {
            int value = top->data;
            Node *newNode = top->next;
            delete top;
            top = newNode;
            return value;
        }
    }

    int Empty()
    {
        if (top == nullptr)
        {
            return 0;
        }
        return 1;
    }

    int Size()
    {
        if (top == nullptr)
        {
            return 0;
        }
        else
        {
            int sizeStack = 0;
            Node *newNode = top;
            while (newNode != nullptr)
            {
                sizeStack++;
                newNode = newNode->next;
            }
            return sizeStack;
        }
    }

    int Top()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty";
            return -1;
        }
        else
        {
            int value = top->data;
            return value;
        }
    }
};

int main()
{
    StackLinkedList sll = StackLinkedList();
    sll.Push(5);
    sll.Push(21);
    sll.Push(10);
    sll.Push(99);
    sll.Push(101);

    cout << "Size of Stack = " << sll.Size() << endl;

    cout << sll.Pop() << endl;
    cout << sll.Pop() << endl;

    cout << "Size of Stack after pop = " << sll.Size() << endl;
}