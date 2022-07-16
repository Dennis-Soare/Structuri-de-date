#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ifstream in("pariuri.in");
    ofstream out("pariuri.out");
    
    unordered_map<int, int> umap;
    int n, m, timp, bani;

    in >> n;

    for(int i=0; i<n; i++) {
        in>>m;

        for(int j=0; j<m; j++) {
            in >> timp >> bani;
            umap[timp] += bani;
        }
    }

    out << umap.size() << '\n';

    for(auto x:umap)
        out << x.first <<' '<< x.second <<' ';

    in.close();
    out.close();
    
    return 0;
}