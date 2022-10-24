#include <iostream>
#include <vector>

using namespace std;

class HashTableEntry
{
public:
    int key;
    int value;

    HashTableEntry(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};

class HashMapTable
{
public:
    vector<HashTableEntry> *table;
    int N;

    HashMapTable(int N)
    {
        this->N = N;
        table = new vector<HashTableEntry>[N];
    }

    int Hash(int key)
    {
        return (key * key + key + 1) % N;
    }

    void Insert(int key, int value)
    {
        int hKey = Hash(key);

        vector<HashTableEntry>::iterator hte;
        for (hte = table[hKey].begin(); hte != table[hKey].end(); hte++)
        {
            if (hte->key == key)
            {
                cout << "Key da ton tai, vui long them key khac!" << endl;
                break;
            }
        }
        if (hte == table[hKey].end())
        {
            HashTableEntry hte = HashTableEntry(key, value);
            table[hKey].push_back(hte);
            cout << "Them thanh cong!" << endl;
        }
    }

    void Display()
    {
        for (int i = 0; i < N; i++)
        {
            cout << i;
            for (auto hte : table[i])
                cout << " --> "
                     << "key: " << hte.key << " value: " << hte.value;
            cout << endl;
        }
    }

    void Search(int key)
    {
        int hKey = Hash(key);

        vector<HashTableEntry>::iterator hte;
        for (hte = table[hKey].begin(); hte != table[hKey].end(); hte++)
        {
            if (hte->key == key)
            {
                cout << hte->value << endl;
                cout << "Tim kiem thanh cong!" << endl;
                break;
            }
        }
        if (hte == table[hKey].end())
        {
            cout << "Tim kiem that bai!" << endl;
        }
    }

    void Remove(int key)
    {
        int hKey = Hash(key);

        vector<HashTableEntry>::iterator hte;
        for (hte = table[hKey].begin(); hte != table[hKey].end(); hte++)
        {
            if (hte->key == key)
            {
                table[hKey].erase(hte);
                cout << "Xoa thanh cong!" << endl;
                break;
            }
        }
        if (hte == table[hKey].end())
        {
            cout << "Xoa that bai!" << endl;
        }
    }
};