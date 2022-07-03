#include <iostream>

using namespace std;

bool hotel[10];

int main()
{
    int n, st=0, dr=9;
    char c;

    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> c;

        if(c == 'L') {
            while (hotel[st])   // cat timp camera este ocupata
                st++;
            hotel[st] = 1;
        }
        else if(c == 'R') {
            while(hotel[dr])
                dr--;
            hotel[dr] = 1;
        }
        else {
            int client = c - '0';
            hotel[client] = 0;  // clientul pleaca
            if (st > client)
                st = client;
            if (dr < client)
                dr = client;
        }
    }

    for(int i=0; i<10; i++) {
        cout << hotel[i];
    }

    return 0;
}