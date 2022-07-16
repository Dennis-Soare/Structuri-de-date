#include <bits/stdc++.h>

using namespace std;

bool pereche(char p1, char p2)
{
    return (p1=='(' && p2==')') || (p1=='[' && p2==']') || (p1=='{' && p2=='}');
}

struct paranteza
{
    char par;
    int poz;
};


int main()
{
    ifstream in("paranteze.in");
    ofstream out("paranteze.out");
    
    stack<paranteza> stiva;
    int n, l_max = 0;
    in >> n;

    paranteza p;
    p.poz = -1;
    p.par = '*';
    stiva.push(p);      // inseram primul element pentru a avea mereu cel putin un element in stiva 

    for(int i=0; i<n; i++) {
        paranteza p;
        in >> p.par;
        p.poz = i;

        if(pereche(stiva.top().par, p.par)) {   // daca paranteza din varful stivei si cea curenta formeaza o pereche
            stiva.pop();                                // emiminam varful stivei
            l_max = max(l_max, i - stiva.top().poz);    // maximul devine pozitia curenta - ultima pozitie din stiva
        }
        else {
            stiva.push(p);      // altfel inseram noua paranteza in stiva 
        }
    }

    /*
    while (!stiva.empty())
    {
        cout << stiva.top().par << ' ' << stiva.top().poz << "\n";
        stiva.pop();
    }
    */

    out << l_max;
    in.close();
    out.close();

    return 0;
}