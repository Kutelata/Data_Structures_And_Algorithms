#include <iostream>
using namespace std;

class Employee
{
public:
    int id;
    string name;
    int yearOfBirth;
    float salary;

    Employee()
    {
    }

    Employee(int id, string name, int yearOfBirth, float salary)
    {
        this->id = id;
        this->name = name;
        this->yearOfBirth = yearOfBirth;
        this->salary = salary;
    }

    ~Employee()
    {
    }

    friend istream &operator>>(istream &is, Employee &e)
    {
        cout << "Nhap ma: " << endl;
        is >> e.id;
        cout << "Nhap ho ten: " << endl;
        cin.ignore();
        getline(is, e.name);
        cout << "Nhap nam sinh: " << endl;
        is >> e.yearOfBirth;
        cout << "Nhap luong " << endl;
        is >> e.salary;
        return is;
    }

    friend ostream &operator<<(ostream &os, Employee &e)
    {
        os << "Ma nhan vien: " << e.id << endl;
        os << "\tHo ten: " << e.name << endl;
        os << "\tNam sinh: " << e.yearOfBirth << endl;
        os << "\tLuong: " << e.salary << endl;
        return os;
    }

    int getId()
    {
        return id;
    }

    int setId(int id)
    {
        this->id = id;
    }
};

class Node
{
public:
    Employee employee;
    Node *next;

    Node(Employee employee = Employee())
    {
        this->employee = employee;
        this->next = nullptr;
    }

    Node(Employee employee, Node *next)
    {
        this->employee = employee;
        this->next = next;
    }
};

class Manage
{
public:
    int size;
    Node *head;
    Node *tail;

    Manage()
    {
        size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    void Input()
    {
        cin >> size;
        for (int i = 0; i < size; i++)
        {
            Employee employee = Employee();
            cin >> employee;
            this->InsertLast(employee);
        }
    }

    void Display()
    {
        Node *temp = this->head;
        while (temp != nullptr)
        {
            cout << temp->employee;
            temp = temp->next;
        }
    }

    void InsertFirst(Employee employee)
    {
        Node *newNode = new Node(employee);

        if (this->head == nullptr)
        {
            this->head = newNode;
        }
        else
        {
            newNode->next = this->head;
            this->head = newNode;
        }
    }

    void InsertLast(Employee employee)
    {
        Node *newNode = new Node(employee);

        if (this->head == nullptr)
        {
            this->head = newNode;
            this->tail = newNode;
        }
        else
        {
            this->tail->next = newNode;
            this->tail = newNode;
        }
    }

    void Remove(int id)
    {
        Node *temp = this->head;
        if (temp != nullptr && temp->employee.getId() == id)
        {
            this->head = temp->next;
            delete temp;
            return;
        }
        else
        {
            Node *curr = this->head;
            while (temp != nullptr && temp->employee.getId() != id)
            {
                curr = temp;
                temp = temp->next;
            }
            if (!temp)
            {
                cout << "Khong tim thay nhan vien can xoa!" << endl;
                return;
            }

            curr->next = temp->next;
            delete temp;
        }
    }

    void GetListBySalaryBigger(int salary){
        Node *temp = head;
        while (temp != nullptr)
        {
            if(temp->employee.salary > salary){
                cout << temp->employee;
            }
            temp = temp->next;
        }
    }
};

int main()
{
    Manage m;
    m.Input();
    m.Display();
    m.GetListBySalaryBigger(1);
    m.Remove(123);
    m.Remove(1);
    m.Display();
    return 0;
}