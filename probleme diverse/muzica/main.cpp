#include <bits/stdc++.h>
using namespace std;
  
int main()
{
    ifstream in("muzica.in");
    ofstream out("muzica.out");

    long long n, m, a, b, c, d, e, urm, ans = 0;
    unordered_set<long long> playlist(100001);

    in >> n >> m;
    in >> a >> b >> c >> d >> e;

    for(int i=0; i<n; i++) {
        int melodie;
        in >> melodie;
        playlist.insert(melodie);
    }

    for(int i=0; i<m; i++)
    {
        if(playlist.find(a) != playlist.end()) {
            ans++;
            playlist.erase(a);
        }
        urm = (c * b + d * a) % e;
        a = b;
        b = urm;
    }

    out << ans;

    return 0;
}