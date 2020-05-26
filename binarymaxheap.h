#pragma once
#include <iostream>
#include <cmath>
using namespace std;
template<typename Data>
class BinaryMaxHeap
{
private:
    struct Element
    {
        Data data;
        unsigned int index;
    };
    Element *heap;
    unsigned int heapHight;
    unsigned int currentIndex;
public:
    BinaryMaxHeap()
    {
        heap = nullptr;
        currentIndex = 0;
        heapHight = 0;
    }
    BinaryMaxHeap(Data const data)
    {
        heap = new Element[1];
        heap[0].data = data;
        heap[0].index = 0;
        heapHight = 1;
        currentIndex = 1;
    }
    BinaryMaxHeap(BinaryMaxHeap const &binaryMaxHeap)
    {
        if(binaryMaxHeap.heapHight == 0)
        {
            heap = nullptr;
            currentIndex = 0;
            heapHight = 0;
            return;
        }
        heapHight = binaryMaxHeap.heapHight;
        unsigned int countelement = 0;
        for(unsigned int i = 0 ; i<heapHight;++i)
        {
            countelement += pow(2,i);
        }
        heap = new Element[countelement];
        for(currentIndex =0; currentIndex <binaryMaxHeap.currentIndex; ++currentIndex)
        {
            heap[currentIndex].data =
             binaryMaxHeap.heap[currentIndex].data;
            heap[currentIndex].index = currentIndex;
        }
    }

    bool const insert(Data const data)
    {
        unsigned  int countelement = 0;
        for(unsigned int i = 0 ; i<heapHight;++i)
        {
            countelement += pow(2,i);
        }
        if(currentIndex == countelement)
        {
            unsigned int tmpSize = (pow(2, heapHight) + countelement)*sizeof(Element);
            Element* tmpHeap = new Element[tmpSize];
            if(tmpHeap == nullptr)
                return false;
            for(unsigned int i = 0; i<currentIndex; ++i)
            {
                tmpHeap[i].data = heap[i].data;
                tmpHeap[i].index = i;
            }
            delete[] heap;
            heap = tmpHeap;
            ++heapHight;
        }
        heap[currentIndex].data = data;
        heap[currentIndex].index = currentIndex;
        int tmpcurrentIndex = currentIndex;
        while( heap[currentIndex].data > heap[(tmpcurrentIndex - 1)/2].data )
        {
            Data tmpdata = heap[(tmpcurrentIndex - 1)/2].data;
            heap[(tmpcurrentIndex - 1)/2].data = heap[currentIndex].data;
            heap[currentIndex].data = tmpdata;
            tmpcurrentIndex = (tmpcurrentIndex - 1)/2;
        }
        ++currentIndex;
        return true;
    }
    bool const deleteThis()
    {
        if(heapHight == 0)
            return false;
        if(currentIndex == 1)
        {
            delete[] heap;
            heap = nullptr;
            currentIndex = 0;
            heapHight = 0;
            return true;
        }
        unsigned int countelementdown = 0;
        for(unsigned  i = 0 ; i<heapHight-1;++i)
        {
            countelementdown += pow(2,i);
        }
        if(currentIndex == countelementdown+1)
        {
            Element* tmpHeap = new Element[countelementdown*sizeof(Element)];
            if(tmpHeap == nullptr)
                return false;
            for(unsigned int i = 0; i<countelementdown; ++i)
            {
                tmpHeap[i].data = heap[i].data;
                tmpHeap[i].index = i;
            }
            delete[] heap;
            heap = tmpHeap;
        }
        --currentIndex;
        return true;
    }
    bool clear()
    {
        if(heap == nullptr)
            return false;
        delete[] heap;
        heap = nullptr;
        heapHight = 0;
        currentIndex = 0;
        return true;
    }
    bool isContains(Data const data) const
    {
        for(unsigned int i = 0; i < currentIndex; ++i)
            if(heap[i].data == data)
                return true;
        return false;
    }
    bool isEmpty() const
    {
        if(currentIndex == 0)
            return true;
        return false;
    }
    bool print() const
    {
        if(isEmpty())
        {
            cout<<"\nHeap is empty!\n";
            return false;
        }
        for(unsigned int i = 0, y = 0, z = pow(2, y); i < currentIndex; ++i)
        {
            if(i == z)
            {
                ++y;
                z += pow(2, y);
                cout<<endl;
            }
            cout<<heap[i].data<<"\t";
        }
        return true;
    }
    BinaryMaxHeap& operator = (BinaryMaxHeap const &binaryMaxHeap)
    {
        if(binaryMaxHeap.heapHight == 0)
        {
            heap = nullptr;
            currentIndex = 0;
            heapHight = 0;
            return *this;
        }
        heapHight = binaryMaxHeap.heapHight;
        unsigned int countelement = 0;
        for(unsigned int i = 0 ; i<heapHight;++i)
        {
            countelement += pow(2,i);
        }
        heap = new Element[countelement];
        for(currentIndex =0; currentIndex <binaryMaxHeap.currentIndex; ++currentIndex)
        {
            heap[currentIndex].data = binaryMaxHeap.heap[currentIndex].data;
            heap[currentIndex].index = currentIndex;
        }
        return *this;
    }

    ~BinaryMaxHeap()
    {
        delete[] heap;
        heap = nullptr;
        currentIndex = 0;
        heapHight =0;
    }
};


