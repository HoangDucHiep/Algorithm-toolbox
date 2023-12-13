#include <bits/stdc++.h>
using namespace std;

int fillTimes(int d, int m, int *stop, int n)
{
    if(stop[0] > m)
        return -1;
    int tank = m;
    int fills = 0;
    for(int i = 1; i <= n; i++)
    {
        if(stop[i] > tank)
        {
            tank = stop[i-1] + m;
            if(stop[i] > tank)
                return -1;
            fills++;
        }
    }
    return fills;
}


int main(){
    int d, m, n;
    cin >> d >> m >> n;
    int stop[n];
    for(int i = 0; i < n; i++)
    {
        cin >> stop[i];
    }    
    stop[n] = d;
    cout << fillTimes(d, m, stop, n);
    return 0;
}