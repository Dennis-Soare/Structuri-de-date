// BUBBLE SORT
// complexitatea = O(n*n)

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;
ifstream fin("date.in");

long v[1000000], n, val_max, nr_teste;

void generate_numbers()
{
    srand(time(0));
    for(int i = 0; i < n; i++){
        v[i] = rand() % val_max;
    }
}

void bubble_sort()
{
    for(int i = n-2; i >= 0; i--)
    {
        bool swapped = false;
        for(int j = 0; j <= i; j++)
            if(v[j] > v[j+1])
            {
                swap(v[j], v[j+1]);
                swapped = true;
            }
        if(swapped = false)                 //daca vectorul este sortat, algoritmul se opreste
            break;
    }
}

void afisare_numere(){
    for(int i = 0; i < n; i++)
        cout << v[i] << ' ';
    cout<<'\n';
}

void test_sort()
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

int main()
{
    fin >> nr_teste;
    for(int i = 1; i <= nr_teste; i++){
        fin >> n >> val_max;
        generate_numbers();
        cout << "N = " << n << "   Max = " << val_max << '\n';

        if(n>=100000)
            cout << "Algoritmul nu poate sorta";
        else{
        auto start = chrono::high_resolution_clock::now();
        ios_base::sync_with_stdio(false);

        bubble_sort();

        auto sfarsit = chrono::high_resolution_clock::now();
        double time_taken = chrono::duration_cast<chrono::nanoseconds>(sfarsit - start).count();
        time_taken *= 1e-9;

        test_sort();
        cout << "Timpul de executie: " << fixed << time_taken << setprecision(9) << " sec\n\n";
        }
    }
    return 0;
}
