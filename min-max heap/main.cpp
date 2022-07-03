#include <bits/stdc++.h>

using namespace std;


class MinMaxHeap
{
    vector<int> heap;

    void PushDown(int);
    void PushUp(int);

    int getParentIndex(int);
    int getGrandparentIndex(int);
    int getLeftChildIndex(int);
    int getRightChildIndex(int);

public:

    int GetMinim();
    int GetMaxim();
    void PopMinim();
    void PopMaxim();
    void Insert(int);
    void BuildHeap(vector<int>);

};


int MinMaxHeap::getParentIndex(int poz) {
    if (poz <= 0)
        return -1;
    else
        return (poz - 1) / 2;
}

int MinMaxHeap::getGrandparentIndex(int poz) {
    return getParentIndex(getParentIndex(poz));
}

int MinMaxHeap::getLeftChildIndex(int poz) {
    return 2 * poz + 1;
}

int MinMaxHeap::getRightChildIndex(int poz) {
    return 2 * poz + 2;
}

int MinMaxHeap::GetMinim() {
    if (heap.size() == 0)
        throw runtime_error("Tried to get minimum from an empty heap!");
    return heap[0];
}

int MinMaxHeap::GetMaxim() {
    if (heap.size() == 0)
        throw runtime_error("Tried to get maximum from an empty heap!");
    if (heap.size() == 1)
        return heap[0];
    if (heap.size() == 2)
        return heap[1];
    else
        return max(heap[1], heap[2]);
}

void MinMaxHeap::PopMinim() {
    swap(heap[0], heap.back());
    heap.pop_back();
    PushDown(0);
}

void MinMaxHeap::PopMaxim() {
    int maxim = GetMaxim();
    int poz = 0;

    while (heap[poz] != maxim) {
        poz++;
    }

    swap(heap[poz], heap.back());
    heap.pop_back();
    PushDown(poz);
}

void MinMaxHeap::Insert(int elem) {
    heap.push_back(elem);
    PushUp(heap.size() - 1);
}

void MinMaxHeap::BuildHeap(vector<int> v) {
    for(int elem: v) {
        Insert(elem);
    }
} 

void MinMaxHeap::PushDown(int poz) {

}

void MinMaxHeap::PushUp(int poz) {

}

int main()
{
    return 0;
}