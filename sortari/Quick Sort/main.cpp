#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
ifstream fin("date.in");

int part(int *a,int st,int dr)
{
    int pivot=a[dr];
    int P_index=st;
    int i,t;
    for(i=st;i<dr;i++)
    {
    	if(a[i]<=pivot)
        {
            t=a[i];
            a[i]=a[P_index];
            a[P_index]=t;
            P_index++;
        }
     }
      t=a[dr];
      a[dr]=a[P_index];
      a[P_index]=t;
     return P_index;
 }

 void Quicksort(int *a,int st,int dr)
 {
    if(st<dr)
    {
         int P_index=part(a,st,dr);
             Quicksort(a,st,P_index-1);
             Quicksort(a,P_index+1,dr);
    }
}

void test_sort(int v[], int n)
{
    bool sortate = true;
    for(int i = 0; i < n-1; i++)
        if(v[i] > v[i+1])
            sortate = false;
    if(sortate)
        cout << "Numerele au fost sortate";
    else
        cout << "Numerele NU au fost sortate";
    cout << '\n';
}

void afisare_numere(int v[], int n){
    for(int i = 0; i < n; i++)
        cout << v[i] << ' ';
    cout<<'\n';
}

int main()
{
    int n, A[100000], val_max, nr_teste;
    fin >> nr_teste;
    for(int i = 1; i <= nr_teste; i++){
        fin >> n >> val_max;
        srand(time(0));
        for(int i = 0; i < n; i++){
            A[i] = rand() % val_max;
        }
        //afisare_numere(A, n);
        auto st = chrono::high_resolution_clock::now();
        ios_base::sync_with_stdio(false);

        Quicksort(A,0,n-1);

        auto sfarsit = chrono::high_resolution_clock::now();
        double time_taken = chrono::duration_cast<chrono::nanoseconds>(sfarsit - st).count();
        time_taken *= 1e-9;

        //afisare_numere(A, n);
        cout << "N = " << n << "   Max = " << val_max << '\n';
        test_sort(A, n);
        cout << "Timpul de executie: " << fixed << time_taken << setprecision(9) << " sec\n\n";
    }
    return 0;
}
