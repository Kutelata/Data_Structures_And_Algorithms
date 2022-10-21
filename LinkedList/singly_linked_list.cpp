#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data = 0)
    {
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class SinglyLinkedList
{
public:
    Node *head;

    SinglyLinkedList()
    {
        this->head = nullptr;
    }

    // Inserting elements (At start of the list)
    void Insert(int data)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    // Loop over the list. Return true if element found
    bool Search(int data)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == data)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void Remove(int data)
    {
        Node *temp = head;
        // If the head is to be deleted
        if (temp != nullptr && temp->data == data)
        {
            head = temp->next;
            delete temp;
            return;
        }
        // Else loop over the list and search for the node to delete
        else
        {
            Node *curr = head;
            while (temp != nullptr && temp->data != data)
            {
                // When node is found, delete the node and modify the pointers
                curr = temp;
                temp = temp->next;
            }
            // If values is not found in the linked list
            if (!temp)
            {
                cout << "Value not found" << endl;
                return;
            }

            curr->next = temp->next;
            delete temp;
        }
    }

    void Display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    SinglyLinkedList l;
    
    // Inserting elements
    l.Insert(6);
    l.Insert(9);
    l.Insert(1);
    l.Insert(3);
    l.Insert(7);
    cout << "Current Linked List: ";
    l.Display();

    cout << "Deleting 1: ";
    l.Remove(1);
    l.Display();

    cout << "Deleting 13: ";
    l.Remove(13);

    cout << "Searching for 7: ";
    cout << l.Search(7) << endl;

    cout << "Searching for 13: ";
    cout << l.Search(13) << endl;
}