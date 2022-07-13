#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
ifstream fin("date.in");

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int Merge(int A[],int p, int q,int r)
{
    int n1,n2,i,j,k;
    n1=q-p+1;
    n2=r-q;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
        L[i]=A[p+i];
    for(j=0;j<n2;j++)
        R[j]=A[q+j+1];
    i=0,j=0;
    for(k=p;i<n1&&j<n2;k++)
    {
        if(L[i]<R[j])
            A[k]=L[i++];
        else
            A[k]=R[j++];
    }
    while(i<n1)
        A[k++]=L[i++];
    while(j<n2)
        A[k++]=R[j++];

}

int MergeSort(int A[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
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
        auto start = chrono::high_resolution_clock::now();
        ios_base::sync_with_stdio(false);

        if (n <= 64)
            insertionSort(A, n);
        else MergeSort(A,0,n-1);

        auto sfarsit = chrono::high_resolution_clock::now();
        double time_taken = chrono::duration_cast<chrono::nanoseconds>(sfarsit - start).count();
        time_taken *= 1e-9;

        //afisare_numere(A, n);
        cout << "N = " << n << "   Max = " << val_max << '\n';
        test_sort(A, n);
        cout << "Timpul de executie: " << fixed << time_taken << setprecision(9) << " sec\n\n";
    }
    return 0;
}
