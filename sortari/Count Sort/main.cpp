#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;
ifstream fin("date.in");
long v[1000000], n, val_max, nr_teste, u[1000000];

void generate_numbers()
{
    srand(time(0));
    for(int i = 0; i < n; i++){
        v[i] = rand() % val_max;
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

void count_sort()
{
    for(int i=0; i<n; i++)
        u[v[i]]++;
    int k = 0;
    for(int i=0; i<val_max; i++){
        while(u[i] != 0){
            v[k++] = i;
            u[i]--;
        }
    }
}

int main()
{
    fin >> nr_teste;
    for(int i = 1; i <= nr_teste; i++){
        fin >> n >> val_max;
        generate_numbers();

        auto start = chrono::high_resolution_clock::now();
        ios_base::sync_with_stdio(false);

        count_sort();
        //afisare_numere();

        auto sfarsit = chrono::high_resolution_clock::now();
        double time_taken = chrono::duration_cast<chrono::nanoseconds>(sfarsit - start).count();
        time_taken *= 1e-9;

        cout << "N = " << n << "   Max = " << val_max << '\n';
        test_sort();
        cout << "Timpul de executie: " << fixed << time_taken << setprecision(9) << " sec\n\n";
    }
    return 0;
}

