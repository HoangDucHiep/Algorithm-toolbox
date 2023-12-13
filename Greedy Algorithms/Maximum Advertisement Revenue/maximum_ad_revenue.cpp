#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    long long p[n], c[n];
    int i;
    for(i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    for(i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    for(int k = 0; k < n-1; k++)
    {
        for(int l = k+1; l < n; l++)
        {
            if(p[l] > p[k])
                swap(p[l], p[k]);
            if(c[l] > c[k])
                swap(c[l], c[k]);
        }
    }

    long long total = 0;
    for(i = 0; i < n; i++)
    {
        total += p[i]*c[i];
    }
    cout << total;
    return 0;
}