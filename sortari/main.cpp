#include <bits/stdc++.h>

using namespace std;


void bubble_sort(vector<int>& v, int n) 
{ 
    int i, j; 
    for (i = 0; i < n - 1; i++) 
        for (j = 0; j < n - i - 1; j++) 
            if (v[j] > v[j + 1]) 
                swap(v[j], v[j + 1]); 
} 


void merge(vector<int> &v, int l, int m, int r){

    int i = l, j = m + 1, k = 0;
    vector<int> c(r-l+1);

    ///interclasare
    while(i <= m && j <= r) {

        if(v[i]<=v[j])
            c[k]=v[i++];
        else
            c[k]=v[j++];
        k++;
    }

    while(i<=m)
        c[k++]=v[i++];

    while(j<=r)
        c[k++]=v[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        v[i] = c[k];
    c.clear();
}

void merge_sort(vector<int> &v, int l, int r) {

    if (l < r) {
        int m = l+(r-l)/2;
        merge_sort(v, l, m);
        merge_sort(v, m+1, r);

        merge(v, l, m, r);
    }
}


int rand_between(int a, int b){
    int r = a + (rand() % ( b - a) );
        if(r<a || r>b) throw EXIT_FAILURE;
    return r;
}

int partition(vector<int> &arr, int l, int r){
    int pivot = rand_between(l, r);

    if(pivot!=r) swap(arr[pivot], arr[r]);
    int x = arr[r], i = (l - 1);

    for (int j = l; j <= r - 1; j++)
        if (arr[j] < x) {
            i++;
            swap(arr[i], arr[j]);
        }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}

void quick_sort(vector<int> &arr, int l, int r){
    if(l>=r) return;
    int pi = partition(arr, l, r);

    quick_sort(arr, l, pi - 1);
    quick_sort(arr, pi + 1, r);
}

void count_sort(vector<int>&v, int nr_elem, int val_max) {

    vector<int> cnt(val_max+1, 0);

    for(auto &i: v)
        cnt[i]++;

    int x  =0;
    for(int j = 0; j < (int)cnt.size(); j++)
        while(cnt[j]-- != 0)
            v[x++] = j;
}

int get_max(vector<int> a){
    int maxi = -9e5;
    for(auto x: a)
        if(x>maxi) maxi = x;
    return maxi;
}

void countsort_by_exp(vector<int> &a, int exp) {
    vector<int> b(a.size());
    vector<int> count(10, 0);

    for(auto x: a)
        count[(x/exp) % 10]++;

    for(int i = 1; i < 10; i++)
        count[i] += count[i-1];

    for(int i = a.size()-1; i >= 0; i--)
        b[--count[(a[i] / exp) % 10]] = a[i];

    for(int i=0;i<(int)a.size();i++)
        a[i] = b[i];
}

void radixsort(vector<int> &a, int val_max) {
    for (int exp = 1; val_max/exp > 0; exp *= 10)
        countsort_by_exp(a, exp);
}



void algsort_infoarena()
{
    ifstream in("algsort.in");
    ofstream out("algsort.out");

    int val_max = 0;
    int n;
    in >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        in >> v[i];
        if(v[i] > val_max) {
            val_max = v[i];
        }
    }


    for(int i=0; i<n; i++) {
        out << v[i]<< ' ';
    }

    in.close();
    out.close();
}

bool verificare_sortare(vector<int>& v)
{
    for (int i=0; i<(int)v.size()-1; i++)
    {
        if(v[i] > v[i+1])
            return 0;
    }
    return 1;
}

uint64_t timeSinceEpochMillisec() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

uint64_t currentTime()
{
    return timeSinceEpochMillisec();;
}

void generare_sir(vector<int>& v, int n, int val_max)
{
    srand(time(0));
    int seed=rand()*rand();
    mt19937_64 r(seed);
    uniform_int_distribution<int> distr;
    for(int i=0; i<n; i++)
    {
        v.push_back(distr(r)%val_max);
    }
}

void print(vector<int>& v)
{
    for(auto x: v) {
        cout << x << ' ';
    }
    cout << '\n';
}


void teste()
{
    ifstream in("teste.in");
    ofstream out("teste.out");

    int nr_teste;
    in >> nr_teste;

    for(int i=0; i<nr_teste; i++) {

        vector<int> v, v_copie;
        int n, val_max;

        in >> n;
        in >> val_max;

        generare_sir(v, n, val_max);

        out << "\nTest " << i+1 << ":  nr elemente = " << n << ";  val max = " << val_max << ";\n";

        out << "Bubble sort: ";
        if(val_max>1000000000 || n>10000) {
            out << "input prea mare\n";
        }
        else {
            v_copie = v;
            uint64_t t1 = currentTime();
            bubble_sort(v_copie, n);
            uint64_t t2 = currentTime();

            if(verificare_sortare(v_copie)) {
                out << "Succes;     timp = ";
                out << t2-t1 <<" milisecunde\n";
            }
            else {
                out << "Esec\n";
            }
        }

        out << "Merge sort: ";
        if(val_max>1000000000 || n>10000000) {
            out << "input prea mare\n";
        }
        else {
            v_copie = v;
            uint64_t t1 = currentTime();
            merge_sort(v_copie, 0, n-1);
            uint64_t t2 = currentTime();

            if(verificare_sortare(v_copie)) {
                out << "Succes;     timp = ";
                out << t2-t1 <<" milisecunde\n";
            }
            else {
                out << "Esec\n";
            }
        }

        out << "Quick sort: ";
        if(val_max>1000000000 || n>10000000) {
            out << "input prea mare\n";
        }
        else {
            v_copie = v;
            uint64_t t1 = currentTime();
            quick_sort(v_copie, 0, n-1);
            uint64_t t2 = currentTime();

            if(verificare_sortare(v_copie)) {
                out << "Succes;     timp = ";
                out << t2-t1 <<" milisecunde\n";
            }
            else {
                out << "Esec\n";
            }
        }

        out << "Count sort: ";
        if(n > 1000000000 || val_max > 1000000000) {
            out << "input prea mare\n";
        }
        else {
            v_copie = v;
            uint64_t t1 = currentTime();
            count_sort(v_copie, n, val_max);
            uint64_t t2 = currentTime();

            if(verificare_sortare(v_copie)) {
                out << "Succes;     timp = ";
                out << t2-t1 <<" milisecunde\n";
            }
            else {
                out << "Esec\n";
            }
        }

        out << "Radix sort: ";
        if(n > 10000000) {
            out << "input prea mare\n";
        }
        else {
            v_copie = v;
            uint64_t t1 = currentTime();
            radixsort(v_copie, val_max);
            uint64_t t2 = currentTime();

            if(verificare_sortare(v_copie)) {
                out << "Succes;     timp = ";
                out << t2-t1 <<" milisecunde\n";
            }
            else {
                out << "Esec\n";
            }
        }
    }

    in.close();
    out.close();
}

int main()
{
    teste();
    return 0;
}