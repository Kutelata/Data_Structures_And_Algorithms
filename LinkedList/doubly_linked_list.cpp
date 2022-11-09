#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *pre;
    Node *next;

    Node(int value)
    {
        this->data = value;
        this->next = nullptr;
        this->pre = nullptr;
    }
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void InsertHead(int value)
    {
        Node *newNode = new Node(value);
        if (this->head == nullptr)
        {
            this->head = newNode;
            this->tail = this->head;
        }
        else
        {
            newNode->next = this->head;
            this->head->pre = newNode;
            this->head = newNode;
        }
    }

    void InsertTail(int value)
    {
        Node *newNode = new Node(value);
        if (this->head == nullptr)
        {
            this->head = newNode;
            this->tail = this->head;
        }
        else
        {
            newNode->pre = this->tail;
            this->tail->next = newNode;
            this->tail = newNode;
        }
    }

    void Display()
    {
        Node *newNode;
        newNode = this->head;
        while (newNode != nullptr)
        {
            cout << newNode->data << endl; 
            newNode = newNode->next;
        }
    }

    void DeleteFirst()
    {
        Node *newNode;
        if (this->head != nullptr)
        {
            newNode = this->head;
            this->head = this->head->next;
            this->head->pre = nullptr;
            delete newNode;
            if (this->head == nullptr)
            {
                this->tail = nullptr;
            }
        }
    }

    void DeleteEnd()
    {
        Node *newNode;
        if (this->head != nullptr)
        {
            newNode = this->tail;
            this->tail = this->tail->pre;
            this->tail->next = nullptr;
            delete newNode;
            if (this->tail == nullptr)
            {
                this->head = nullptr;
            }
        }
    }

    void DeleteAll()
    {
        Node *newNode;
        while (this->head != NULL)
        {
            newNode = this->head;
            this->head = this->head->next;
            delete newNode;
        }
        this->tail = NULL;
    }

    void Sort()
    {
        Node *nodeFirst, *nodeSecond;
        nodeFirst = this->head;
        while (nodeFirst != this->tail)
        {
            nodeSecond = nodeFirst->next;
            while (nodeSecond != NULL)
            {
                if (nodeFirst->data > nodeSecond->data)
                {
                    swap(nodeFirst->data, nodeSecond->data);
                }
                nodeSecond = nodeSecond->next;
            }
            nodeFirst = nodeFirst->next;
        }
    }
};

int main()
{
    DoublyLinkedList dll;
    
    dll.InsertHead(6);
    dll.InsertHead(9);
    dll.InsertTail(1);
    dll.InsertTail(3);
    cout << "Current Linked List: \n";
    dll.Display();

    cout << "Deleting: \n";
    dll.Sort();
    dll.Display();
}