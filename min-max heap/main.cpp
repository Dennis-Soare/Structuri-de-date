#include <bits/stdc++.h>

using namespace std;


template <typename T>
class MinMaxHeap
{
    vector <T> heap_;
    vector <bool> lvl_;     // 0 -> nivel de minim; 1 -> nivel de maxim

    void Build(const vector<T>&);   // construieste min-max heap dintr-un vector de elemente
    void PushDown(const int);    
    void PushUp(const int);

public:

    MinMaxHeap() : heap_(1), lvl_{1} {}
    MinMaxHeap(const vector<T>& heap);
    vector<T> GetMinMaxHeap();
    T GetMinim();
    T GetMaxim();
    void PopMinim();
    void PopMaxim();
    void Insert(const T);
    void Reunion(MinMaxHeap<T>&);
    void PrintMinMaxHeap();
};


template <typename T>
MinMaxHeap<T>::MinMaxHeap(const vector<T>& heap) : heap_(1), lvl_{1} {
    Build(heap);
}

template <typename T>
void MinMaxHeap<T>::Build(const vector<T>& heap) {
    for (auto i : heap) {
        heap_.push_back(i);
        lvl_.push_back(1 ^ lvl_[lvl_.size() / 2]);
    }

    for (int i = heap_.size() - 1; i >= 1; i--)
        PushDown(i);
}


template <typename T>
void MinMaxHeap<T>::PushDown(const int poz) {
    vector <int> fii;
    for (int i = 2 * poz; i <= 2 * poz + 1; i++)
        if (i < (int)heap_.size())
            fii.push_back(i);

    for (int i = 4 * poz; i <= 4 * poz + 3; i++)
        if (i < (int)heap_.size())
            fii.push_back(i);

    auto cmp = (lvl_[poz] ? [](T a, T b) { return a > b; } : [](T a, T b) { return a < b; });
    // nivel de maxim -> returneaza a > b;
    // nivel de minim -> returneaza a < b;

    int fiu = -1;
    for (auto i : fii)
        if (fiu == -1 || !cmp(heap_[fiu], heap_[i]))
            fiu = i;
    // nivel de maxim -> fiu = cel mai mare fiu;
    // nivel de minim -> fiu = cel mai mic fiu;

    if (fiu != -1 && cmp(heap_[fiu], heap_[poz])) {
        swap(heap_[poz], heap_[fiu]);

        if (fiu >= 4 * poz && !cmp(heap_[fiu], heap_[fiu / 2]))
            swap(heap_[fiu], heap_[fiu / 2]);
            
        PushDown(fiu);
    } 
}

template <typename T>
void MinMaxHeap<T>::PushUp(const int poz) {
    auto cmp = (lvl_[poz] ? [](T a, T b) { return a > b; } : [](T a, T b) { return a < b; });
    // nivel de maxim -> returneaza a > b;
    // nivel de minim -> returneaza a < b;

    if (poz / 2 != 0 && cmp(heap_[poz / 2], heap_[poz])) { 
        swap(heap_[poz], heap_[poz / 2]);
        PushUp(poz / 2);
    }
    else if (poz / 4 != 0 && cmp(heap_[poz], heap_[poz / 4])) { 
        swap(heap_[poz], heap_[poz / 4]);
        PushUp(poz / 4);
    }
}

template <typename T>
vector<T> MinMaxHeap<T>::GetMinMaxHeap() {
    return heap_;
}

template <typename T>
T MinMaxHeap<T>::GetMinim() {
    if (heap_.size() == 1)
        throw runtime_error("Tried to get minimum from an empty heap!");
    return heap_[1];
}

template <typename T>
T MinMaxHeap<T>::GetMaxim() {
    if (heap_.size() == 1)
        throw runtime_error("Tried to get maximum from an empty heap!");
    if (heap_.size() == 2)
        return heap_[1];
    if (heap_.size() == 3)
        return heap_[2];
    else
        return max(heap_[2], heap_[3]);
}

template <typename T>
void MinMaxHeap<T>::PopMinim() {
    if (heap_.size() == 1)
        throw runtime_error("Tried to pop the minimum from an empty heap!");
    else {
        swap(heap_.back(), heap_[1]);
        heap_.pop_back();
        lvl_.pop_back();
        PushDown(1);
    }
}

template <typename T>
void MinMaxHeap<T>::PopMaxim() {
    if (heap_.size() == 1)
        throw runtime_error("Tried to pop the maximum from an empty heap!");
    else {
        T maxim = GetMaxim();        
        int poz = 1;
        while (heap_[poz] != maxim)
            poz++;

        swap(heap_.back(), heap_[poz]);
        heap_.pop_back();
        lvl_.pop_back();
        PushDown(poz);
    }
}

template <typename T>
void MinMaxHeap<T>::Insert(const T elem) {
    int poz = heap_.size();
    heap_.push_back(elem);
    lvl_.push_back(1 ^ lvl_[poz / 2]);
    PushUp(poz);
}

template <typename T>
void MinMaxHeap<T>::Reunion(MinMaxHeap<T>& b) {
    vector<T> v = b.GetMinMaxHeap();

    for(int i=1; i<(int)v.size(); i++) {
        Insert(v[i]);
    }

    MinMaxHeap<T> nou;
    b = nou;
}

template <typename T>
void MinMaxHeap<T>::PrintMinMaxHeap() {
    vector<T> v = GetMinMaxHeap();
    int j = 0, k = 1;
    for(int i=1; i<(int)v.size(); i++) {
        cout << v[i] << ' ';
        j++;
        if(j == k) {
            cout << '\n';
            j = 0;
            k *= 2;
        }
    }
    cout << '\n';
}


void mergeheap_infoarena()
{
    ifstream in("mergeheap.in");
    ofstream out("mergeheap.out");

    int n, q;
    in >> n >> q;

    MinMaxHeap <int> mmh[n+1];

    for(int i=0; i<q; i++) {
        int op;
        in >> op;

        switch (op)
        {
        case 1:
            int m, x;
            in >> m >> x;
            mmh[m].Insert(x);
            break;

        case 2:
            in >> m;
            out << mmh[m].GetMaxim() << "\n";
            mmh[m].PopMaxim();
            break;

        case 3:
            int a, b;
            in >> a >> b;
            mmh[a].Reunion(mmh[b]);
            break;
        
        default:
            break;
        }
    }

    in.close();
    out.close();
}

void AfisareMeniu()
{
    cout << "1. Insert element\n";
    cout << "2. Print minim\n";
    cout << "3. Print maxim\n";
    cout << "4. Pop minim\n";
    cout << "5. Pop maxim\n";
    cout << "6. Print min-max heap\n";
    cout << "7. Exit\n";
}

void Meniu()
{
    int n;
    cout << "n = ";
    cin >> n;
    cout << "Introduceti " << n << " numere.\nnumere = ";
    vector<int> v;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        v.push_back(x); 
    }

    MinMaxHeap<int> mmh(v);
    bool ok = true;
    cout << "\n";
    AfisareMeniu();

    while (ok)
    {
        int comanda;
        cout << "comanda = ";
        cin >> comanda;

        switch (comanda)
        {
        case 1:
            cout << "element = ";
            int el;
            cin >> el;
            mmh.Insert(el);
            break;
        case 2:
            cout << "Minim = " << mmh.GetMinim() << "\n\n";
            break;
        case 3:
            cout << "Maxim = " << mmh.GetMaxim() << "\n\n";
            break;
        case 4:
            mmh.PopMinim();
            cout << "Minimul a fost eliminat.\n";
            break;
        case 5:
            mmh.PopMaxim();
            cout << "Maximul a fost eliminat.\n";
            break;
        case 6:
            cout << "\n";
            mmh.PrintMinMaxHeap();
            cout << "\n";
            break;
        default:
            ok = false;
            break;
        }
    }
    

}


int main()
{
    Meniu();
    return 0;
}