#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class QueueLinkedList
{
public:
    Node *front;
    Node *rear;

    QueueLinkedList()
    {
        this->front = nullptr;
        this->rear = nullptr;
    }

    void Enqueue(int data)
    {
        Node *newNode = new Node(data);
        if (front != nullptr)
        {
            rear->next = newNode;
        }
        else
        {
            front = newNode;
        }
        rear = newNode;
    }

    int Dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty";
            return -1;
        }
        else
        {
            int res = front->data;
            Node *p = front->next;
            delete front;
            front = p;
            if (front == NULL)
            {
                rear = NULL;
            }
            return res;
        }
    }

    // print Queue
    void PrintQueue()
    {
        Node *p = front;
        cout << "Elements in Queue: ";
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
};

int main()
{
    QueueLinkedList l;

    l.Enqueue(5);
    l.Enqueue(21);
    l.Enqueue(10);
    l.Enqueue(99);
    l.Enqueue(101);
    l.PrintQueue();

    cout << endl
         << "Dequeue fromt Queue: ";
    cout << l.Dequeue() << " ";
    cout << l.Dequeue() << endl;
    // print Queue after dequeue
    cout << "Print Queue after dequeue" << endl;
    l.PrintQueue();
    return 0;
}