#include "AList.h"

int main()
{
    AList<int> arrayList(1024) ;
    arrayList.insert(3);
    arrayList.insert(6);
    arrayList.print();
}
