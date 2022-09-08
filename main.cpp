#include <iostream>

#include "hash_list.h"


int main(int argc, char *argv[])
{
    hash_list list;

    if (list.get_size() != 0)
    {
        std::cout << "Invalid size" << std::endl;
        exit(1);
    }


std::cout << "(INIT) Initialized" << std::endl;
    list.insert(3, 4);
    list.insert(4, 5);
    list.printArray();
    list.get_size();


    if (list.get_size() != 2)
    {
        std::cout << "Invalid size" << std::endl;
        exit(1);
    }

    if (!list.get_value(3).has_value())
    {
        std::cout << "expected 3 to be in list but it wasn't" << std::endl;
        exit(1);
    }

list.printArray();

    if (!list.remove(3))
    {
        std::cout << "Failed to remove 3 from list" << std::endl;
        exit(1);
    }

list.printArray();

    if (list.get_value(3).has_value())
    {
        std::cout << "Unexpected 3 in list" << std::endl;
        exit(1);
    }

    

    std::cout << "<Starting Test for Trace 1>" << std::endl;
    hash_list list2;
    list2.get_size();
    list2.insert(1, 1);
    list2.insert(2, 2);
    list2.insert(3, 3);
    list2.insert(4, 4);
    list2.get_value(1);
    list2.get_value(2);
    list2.get_value(3);
    list2.get_value(4);
    list2.printArray();
    std::cout << "<Starting Test for Trace 2>" << std::endl;
    hash_list list3;
    list3.insert(1, 1);
    list3.insert(1, 11);
    list3.insert(2, 2);
    list3.insert(2, 22);
    list3.insert(3, 3);
    list3.insert(3, 33);
    list3.insert(4, 4);
    list3.insert(4, 44);
    list3.printArray();
    std::cout << "<Starting Test for Trace 3>" << std::endl;
    list3.get_value(101);
    list3.get_value(102);
    list3.get_value(103);
    list3.get_value(104);
    std::cout << "<Starting Test for Trace 4>" << std::endl;
    list3.remove(1);
    list3.remove(2);
    list3.get_value(1);
    list3.get_value(2);
    list3.printArray();
    std::cout << "<Starting Test for Trace 5>" << std::endl;
    list3.remove(101);
    list3.remove(102);

    std::cout << "<Remaining>" << std::endl;
    list.printArray();
    list2.printArray();
    list3.printArray();
}

