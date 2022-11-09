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
        this->top = nullptr;
    }

    void Push(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        if (this->top != nullptr)
        {
            newNode->next = this->top;
            this->top = newNode;
        }
        else
        {
            newNode->next = nullptr;
            this->top = newNode;
        }
    }

    int Pop()
    {
        if (this->top == nullptr)
        {
            cout << "Stack is empty";
            return -1;
        }
        else
        {
            int value = this->top->data;
            Node *newNode = this->top->next;
            delete this->top;
            this->top = newNode;
            return value;
        }
    }

    int Empty()
    {
        if (this->top == nullptr)
        {
            return 0;
        }
        return 1;
    }

    int Size()
    {
        if (this->top == nullptr)
        {
            return 0;
        }
        else
        {
            int sizeStack = 0;
            Node *newNode = this->top;
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
        if (this->top == nullptr)
        {
            cout << "Stack is empty";
            return -1;
        }
        else
        {
            int value = this->top->data;
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