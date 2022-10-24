#include <iostream>
#include "../../hash_table.cpp"

using namespace std;

int main()
{
    HashMapTable table = HashMapTable(9);
    table.Insert(111,564);
    table.Insert(222,123);
    table.Insert(333,679);
    table.Insert(444,542);
    table.Insert(555,65);
    table.Insert(666,354);
    table.Insert(777,165);
    table.Insert(888,567);
    table.Insert(999,80);
    table.Insert(000,434);
    table.Insert(111,36);
    table.Insert(222,42);
    table.Insert(333,134);

    table.Display();
    table.Search(333);
    table.Remove(333);
    table.Display();

    // 564, 123,
    // 679, 542, 65, 354, 165, 567, 80, 434, 36, 42, 134
    return 0;
}