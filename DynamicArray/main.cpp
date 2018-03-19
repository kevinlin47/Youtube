#include "DynamicArray.h"
#include<iostream>

int main()
{
    DynamicArray testArray;

    for (int i=0;i<40;++i)
    {
        testArray.add(i*2);
    }

    testArray.print();

    for (int i=0;i<38;++i)
    {
        testArray.remove(i*2);
    }

    testArray.print();

}
