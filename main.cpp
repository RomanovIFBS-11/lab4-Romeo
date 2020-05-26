#include <iostream>
#include "binarymaxheap.h"
using namespace std;

int main()
{
    BinaryMaxHeap<int> heap1(9);
    heap1.insert(15);
    heap1.print();
    cout<<endl;
    heap1.insert(5);
    heap1.insert(15);
    heap1.insert(7);
    heap1.insert(8);
    heap1.print();
    cout<<endl;
    BinaryMaxHeap<int> heap2(heap1);
    heap2.deleteThis();
    heap2.deleteThis();
    heap2.deleteThis();
    heap2.deleteThis();
    heap2.deleteThis();
    heap2.deleteThis();
    heap2.deleteThis();
    heap2.deleteThis();
    heap2.deleteThis();
    heap2.deleteThis();
    heap2.deleteThis();
    heap2.print();
    cout<<endl;
    heap2 = heap1;
    heap2.print();
    cout<<endl;
    if(heap2.isContains(7))
        cout<<"\nHeap is contain 7"<<endl;
    heap1.clear();
    heap1.print();
    cout<<endl;
    heap2.print();
    cout<<endl;
    return 0;
}
